/// https://cp-algorithms.com/graph/bridge-searching.html

////// find bridges

int n;
vector<vector<int>> adj; 

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

///////

/*

We'll use "time of entry into node" computed by the depth first search.

So, let tin[v] denote entry time for node v. 
We introduce an array low which will let us check the fact for each vertex v. 
low[v] is the minimum of tin[v], 
the entry times tin[p] for each node p that is connected to node v via a back-edge (v,p) 
and the values of low[to] for each vertex to which is a direct descendant of v in the DFS tree:

low[v] = min⎧⎩⎨⎪⎪tin[v]tin[p]low[to] for all p for which (v,p) is a back edge for all to for which (v,to) is a tree edge

Now, there is a back edge from vertex v or one of its descendants to one of its ancestors 
if and only if vertex v has a child to for which low[to]≤tin[v]. 

If low[to]=tin[v], the back edge comes directly to v, otherwise it comes to one of the ancestors of v.

Thus, the current edge (v,to) in the DFS tree is a bridge if and only if low[to]>tin[v].

*/