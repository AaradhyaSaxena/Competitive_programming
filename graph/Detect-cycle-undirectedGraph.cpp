////////https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

///// Detect Cycle in Undirected graph

bool dfs(int u,int p,vector<int> g[],vector<bool> &vis){   
    vis[u] = true;
    for(auto i:g[u])
    {   
    	if(!vis[i])
    	{   
        	if(dfs(i,u,g,vis))
                return true;
        }
        else if( i != p || i == u)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int V){	
	vector<bool> vis(V);
	for(int i=0;i<V;i++){   
		if( !vis[i] && dfs(i,-1,g,vis))
	        return true;
	}
	return false;
}


/////////////////////////
/////////////////////////

/// wrong soln

// unordered_map<int,bool> mp;
// int id[10001];
// void initialize(){
//     for(int i=0; i<10001; i++){
//         id[i] = i;
//     }
// }
// int root(int x){
//     while(id[x]!=x){
//         id[x] = id[id[x]];
//         x = id[x];    
//     }
//     return x;
// }
// void union1(int x, int y){
//     int p = root(x);
//     int q = root(y);
//     id[p] = id[q];
// }

// bool dfs(int s, vector<int> adj[]){
//     mp[s] = true;
//     for(int i=0; i<adj[s].size(); i++){
//         if(mp[adj[s][i]]==false and root(s)==root(adj[s][i])){
//             return true;
//         }
//         if(mp[adj[s][i]]==false){
//             dfs(adj[s][i], adj);
//             union1(s,adj[s][i]);
//         }
//     }
//     return false;
// }

// bool isCyclic(vector<int> g[], int V){
//     initialize();
//     int flag = 0;
//     flag = dfs(0,g);
//     if(flag==1) return true;
//     for(int i=1; i<V; i++){
//         if(root(i-1)==root(i)){
//             return true;
//         }
//         dfs(i,g);
//         union1(i-1,i);
//     }
//     return false;
// }