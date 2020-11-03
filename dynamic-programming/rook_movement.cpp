//////// https://codeforces.com/contest/1395
/// p2
#include <bits/stdc++.h>
using namespace std;

bool visited[100][100];
int movex[4] = {0,1,0,-1};
int movey[4] = {1,0,-1,0};
vector<pair<int,int>> ans;

bool islegal(int n, int m, int x, int y){
    if(x>0 and x<=n and y>0 and y<=m){
        return true;
    }return false;
}

void move(int n,int m,int &x,int &y, int &left){
    if(left == 0)
        return;
    for(int k=1; k<max(n,m); k++){
        for(int i=0; i<4; i++){
            int X = x + k*movex[i], Y = y + k*movey[i];
            if(islegal(n,m,X,Y) and visited[X-1][Y-1]==false){
                x = X;
                y = Y;
                visited[x-1][y-1] = true;
                ans.push_back({x,y});
                left--;
                move(n,m,x,y,left);
            }
        }
    }
    if(left !=0){
        ans.pop_back();
    }
}

int main(){
    int n,m,x,y,t;
    cin>>n>>m>>x>>y;
    t = n*m;
    memset(visited, false, sizeof(visited));
    visited[x-1][y-1] = true;
    cout<<x<<" "<<y<<endl;
    int left = n*m -1;
    move(n,m,x,y,left);

    if(left==0){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
}

/////////////////
///////////////