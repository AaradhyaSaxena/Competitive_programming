///////// https://practice.geeksforgeeks.org/problems/hamiltonian-path/0

///// Hamiltonian Path

#include <bits/stdc++.h>
using namespace std;

bool dfs(int s,vector<int> adj[11], int vis[11], int n){
    vis[s]=1;
    
    if(n==0)
        return 1;
    
    for(int i=0; i<adj[s].size(); i++){
        if(!vis[adj[s][i]])
        {
            if(dfs(adj[s][i],adj,vis,n-1))
                return 1;
        }
    }

    if(n>0){
        vis[s]=0;
        return 0;
    }
    else
        return 1;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,u,v,i;
        vector<int> adj[11];
        int vis[11];
        cin>>n>>m;
        while(m--){
            cin>>u>>v;
            vis[u]=0;
            vis[v]=0;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(i=1; i<=n; i++){
            if(dfs(i,adj,vis,n-1)){
                cout<<1<<endl;
                break;
            }
        }
        if(i>n)
            cout<<0<<endl;
    }
    return 0;
	//code
}