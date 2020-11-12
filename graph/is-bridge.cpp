/////////https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

///////////

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

//////////

//// is bridge

void dfs(list<int> adj[],int s,int vis[])
{
    vis[s]=1;
    list<int>::iterator i;
    for(i=adj[s].begin();i!=adj[s].end();i++)
    {
        if(!vis[*i]) dfs(adj,*i,vis);
    }
}

bool isconnected(list<int> adj[],int V,int s,int e)
{
    int vis[V]={0};
    dfs(adj,s,vis);
    if(vis[e])
    return 0;
    return 1;
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    adj[s].remove(e);
    adj[e].remove(s);
    return isconnected(adj,V,s,e);
}

/////
