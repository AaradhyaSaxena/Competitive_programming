////////https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

//// Farthest node

int V;

pair<int, int> bfs(int u,vector<int>* adj){ 
    int dis[V]; 
    memset(dis, -1, sizeof(dis)); 
    queue<int> q; 
    q.push(u); 
    dis[u] = 0; 
    while (!q.empty()){ 
        int t = q.front();
        q.pop(); 
        for(int it = 0; it < adj[t].size(); it++){ 
            int v = adj[t][it]; 
            if (dis[v] == -1) { 
                q.push(v); 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
    int maxDis = 0; 
    int nodeIdx;
    for (int i = 0; i < V; i++){ 
        if (dis[i] > maxDis){ 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
}

int Solution::solve(vector<int> &A){
    V = A.size();
    if(V==1) return 0;
    pair<int, int> t1, t2;
    vector<int> adj[V];
    for(int i=0;i<V;i++){
        if(A[i]==-1){
            continue;            
        }
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    // If we start BFS from any node x and find a node with the longest distance from x,
    // it must be an end point of the longest path.
    t1 = bfs(0, adj);
    t2 = bfs(t1.first, adj);
    return t2.second;
}