//////https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
/// https://practice.geeksforgeeks.org/problems/biconnected-graph/0

/// Biconnected Component

#include<bits/stdc++.h>
using namespace std;
int timer;

bool dfs(int s,int par,int n,vector<vector<int>> &adj,vector<bool> &visited,
		vector<int> &low, vector<int> &pos){
    
    int child = 0;
    visited[s] = true;
    low[s] = pos[s] = timer++;
    for(int i=0; i<adj[s].size(); i++){
        int to = adj[s][i];
        if(visited[to]==false){
            child++;
            int result = dfs(to,s,n,adj,visited,low,pos);
            if(result == false){
            	return false;
            }
            low[s] = min(low[s], low[to]);

		    if(par == -1 and child > 1){
		    	return false;
            }
            if(par != -1 and low[to]>= pos[s]){
            	return false;
            }
        }
	    else if(to != par){
	        low[s] = min(low[s], pos[to]);
	    }
	}
	return true;
}


int main(){
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n, false);
    vector<int> low(n,-1);
    vector<int> pos(n,-1);
    timer = 0;
    int flag = 1, cnt = 0;
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            cnt++;
            int result = dfs(i,-1,n,adj,visited,low,pos);
            if(result == false){
                flag = 0;
                break;
            }
        }
        if(flag==0) break;
    }
    if(cnt>1) flag = 0;
    if(flag==1) cout<<1<<endl;
    else cout<<0<<endl;
    }
}



////////
