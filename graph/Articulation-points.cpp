////////https://cp-algorithms.com/graph/cutpoints.html

///// FIND ARTICULATION POINTS

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } 
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

///////////////
///////////

// naive approach

function find_articulation_points(adj[][], V)
    count = 0
    for i = 0 to V
        visited[i] = false
    initial_val = 0 
    for i = 0 to V
        if visited[i] == false
            DFS(adj, V, visited, i)
            initial_val = initial_val+1

    for i=0 to V
        for j = 0 to V
            visited[j] = false
            copy[j] = adj[i][j]
            adj[i][j]=adj[j][i]=0

        nval = 0
        for j= 0 to V
            if visited[j] == false AND j != i
                nval = nval + 1
                DFS(adj, n, visited, j)
        if nval > initial_val
            count = count + 1
        for j= 0 to V
            adj[i][j] = adj[j][i] = copy[j]
    return count

/////////////////