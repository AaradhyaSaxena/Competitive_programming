/////https://practice.geeksforgeeks.org/problems/divisibility-tree/0

/// Divisibility Tree

#include <bits/stdc++.h>
using namespace std;

// int ans;

int dfs(int s, vector<vector<int>> adj, vector<bool> vis, vector<int> &st, int &ans){

	vis[s] = true;
	st[s] = 0;
	for(auto to: adj[s]){
		if(vis[to]==false){
			int res = dfs(to,adj,vis,st,ans);
			if(res%2 == 0){
				ans += 1;
			}
			else{
				st[s] += res;
			}
		}
	}
	return st[s] + 1;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		if(n%2 ==1){
			cout<<0<<endl;
			continue;
		}
		vector<vector<int>> adj(n+1);
		for(int i=0; i<e; i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int ans = 0;
		vector<bool> visited(n+1);
		vector<int> subtree(n+1);
		for(int i=0; i<n+2; i++){
			visited[i] = false;
			subtree[i] = 0;
		}

		int nodes = dfs(1, adj, visited, subtree);
		if(nodes%2==0) ans += 1;
		cout<<ans<<endl;
	}
	return 0;
}

////////////

#include<vector>
using namespace std;
#define size 1005

vector<int>adj[size];
bool vis[size];

int dfs(int vertex, int *grp){
    if(vis[vertex])
        return 0;   
    vis[vertex] = true;
    int ans = 1;
    
    for(int V:adj[vertex])
    {
        bool f = vis[V];
        int curr = dfs(V,grp);

        if(!curr && !f)
            (*grp) += 1;
        ans += curr;
    }
    
    return ans%2;
    
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    int n,e;
	    cin>>n>>e;
	    for(int i=1; i<=n; i++)
	    {
	        adj[i].clear();
	        vis[i] = false;
	    }
	    for(int i=0; i<e; i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        adj[x].push_back(y);
	        adj[y].push_back(x);
	    }
	    int ans = 0;
	    dfs(1, &ans);
	    cout<<ans<<endl;
	}
	return 0;
}







