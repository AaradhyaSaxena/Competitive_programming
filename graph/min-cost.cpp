////////https://practice.geeksforgeeks.org/problems/minimum-cost-path/0

/// Min Cost

#include<bits/stdc++.h>
#include<queue>
using namespace std;

int BFS(vector<vector<int>> a, vector<vector<int>> dis, int n){
    dis[0][0] = a[0][0];
    queue<pair<int,int>> q1;
    q1.push({0,0});
    
    while(!q1.empty()){
        
        pair<int,int> x = q1.front();
        
        int p = x.first;
        int q = x.second;
        q1.pop();

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};

        for(int i=0; i<4; i++)
        {
            int d = p + dr[i];
            int e = q + dc[i];

            if(d>=0 && e>=0 && d<n && e<n) 
            {
                if((dis[p][q] + a[d][e]) < dis[d][e]){
                	dis[d][e] = dis[p][q] + a[d][e];
                	q1.push({d,e});
                }
            }
        }
    }
    return dis[n-1][n-1];
}

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<vector<int>> a;
	    vector<vector<int>> dis(n,vector<int>(n, INT_MAX));

	    for(int i=0; i<n; i++){
	        vector<int> x;
	        for(int j=0; j<n; j++){
	            int temp;
	            cin>>temp;
	            x.push_back(temp);
	        }
	        a.push_back(x);
	    }
	    int ans = BFS(a,dis,n);
	    cout<<ans<<endl;
	}
	return 0;
}

///////////
/////