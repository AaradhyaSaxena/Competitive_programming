/////////https://practice.geeksforgeeks.org/problems/find-minimum-s-t-cut-in-a-flow-network/0

/////// Min cut max flow

#include <bits/stdc++.h>
#define endll "\n";
using namespace std;

void dfs(vector<vector<int>> c,int s,vector<int> &vis){
    vis[s]=1;
    
    for(int i=0;i<c.size();i++)
    {
        if(vis[i]==0&&c[s][i]>0)
        {
            dfs(c,i,vis);
        }
    }
}

bool bfs(vector<vector<int>> c,int s,int t,vector<int> &vis,vector<int> &par){
    
    vis[s]=1;
    queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<c.size(); i++){
            if(vis[i] == 0 && c[u][i] > 0){
                par[i] = u;
                vis[i] = 1;
                q.push(i);
                if(i == t){
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> c(n,vector<int>(n)), c1(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> c[i][j];
                c1[i][j] = c[i][j];
            }
        }
        int s,t;
        cin>>s>>t;
        while(true){
        	vector<int> vis(n,0),par(n,-1);
            if(bfs(c,s,t,vis,par)==false){
        		break;
           	}
           	int v=t;
           	int max1=INT_MAX;
           	while(par[v]!=-1){
            	max1=min(max1,c[par[v]][v]);
               	v=par[v];
           	}
           	v=t;
           	while(par[v]!=-1){
               	c[par[v]][v] -= max1;
               	c[v][par[v]] += max1;
               	v = par[v];
            }
        }

        vector<int> vis(n, 0);
        dfs(c, s, vis);
        
        int f = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(vis[i]==1 && vis[j] == 0 && c1[i][j] != 0){
                    f = 0;
                    cout<<i<<" "<<j<<" ";
                }
            }
        }
        if(f==1){
            cout<<-1;
        }
        cout<<endll;
    }
    return 0;
}
/////////////
/////////

////////////