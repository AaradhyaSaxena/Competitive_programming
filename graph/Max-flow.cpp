////////https://practice.geeksforgeeks.org/problems/find-the-maximum-flow/0

///// Calculate maximum flow

#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> adj, int s, int t, vector<int> &parent, int n){

	vector<bool> vis(n+1, false);
	queue<int> qt;
	qt.push(s);
	vis[s] = true;
	parent[s] = -1;

	while(!qt.empty()){
		int u = qt.front();
		qt.pop();
		vis[u] = true;

		for(int i=1; i<=n; i++){
			if(vis[i]==false and adj[u][i]>0){
				qt.push(i);
				parent[i] = u;
				// vis[u] = true;
			}
		}
	}

	if(vis[t]==true){
		return true;
	}
	return false;
}


int main() {
	int t; cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> adj(n+1, vector<int> (n+1, 0));
	    for(int i=0; i<m; i++){
	    	int x,y,z;
	    	cin>>x>>y>>z;
	    	adj[x][y] += z;
	    	adj[y][x] += z;
	    }
	    int s = 1, t = n;
	    int max_flow = 0;
	    int u, v;

	    vector<int> parent(n+1,-1);
	    while(bfs(adj,s,t,parent,n)){
	    	int flow_path = INT_MAX;

	    	for(v = t; v != s; v = parent[v]){
	    		u = parent[v];
	    		flow_path = min(flow_path, adj[u][v]);
	    	}

	    	for( v=t; v!= s; v = parent[v]){
	    		u = parent[v];
	    		adj[u][v] -= flow_path;
	    		adj[v][u] += flow_path; 
	    	}
	    	max_flow += flow_path;
	    }
	    cout<<max_flow<<endl;
	}
	return 0;
}


////////////////
///////////






//////////	
