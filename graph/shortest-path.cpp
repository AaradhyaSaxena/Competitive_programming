////// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

/// shortest path

//////////// floyd-warshalls

vector <int> floyd_warshalls(vector<vector<int>> g, int src, int V) {
    // int dp[V][V] = {INT_MAX};
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if( i != j and g[i][j]==0) g[i][j] = 1000000; // wt zero is treated as no edge
                if(g[i][j] > g[i][k]+ g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
                if(i==j) g[i][j] = 0;
            }
        }
    }
    vector<int> vec;
    for(int i=0; i<V; i++){
        vec.push_back(g[src][i]);
    }
    return vec;
}

////////////////////////
/////////// dijkstra

vector<int> dijkstra(vector<vector<int>> graph, int src, int V)
{
    priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> distance(V,INT_MAX);
    bool visited[V]={false};
    pq.push({0,src});
    distance[src]=0;
    
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        int u=p.second;
        if(visited[u]==true) continue;
        visited[u]=true;
        for(int i=0;i<V;i++){
            if(graph[u][i]!=0){
                int v=i;    
                int wt=graph[u][i];
                if(distance[v]>distance[u]+wt){
                    distance[v]=distance[u]+wt;
                    pq.push({distance[v],v});
                }
            }
        } 
    }
    vector<int> vec;
    for(int i=0; i<V; i++){
        vec.push_back(distance[i]);
    }
    return vec;
}

/////////////////////////
////// Bellman-fords

// The row graph[i] represents i-th edge with three values u, v and w. 
void BellmanFord(int graph[][3], int V, int E, int src) 
{ 
    int dis[V]; 
    for (int i = 0; i < V; i++) 
        dis[i] = INT_MAX;  // Initialize distance of all vertices as infinite. 
  
    dis[src] = 0; 
  
    for (int i = 0; i < V - 1; i++) 
    { 
        for (int j = 0; j < E; j++) 
        { 
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) 
            {
                dis[graph[j][1]] =  dis[graph[j][0]] + graph[j][2]; 
            }
        } 
    } 
  
    // check for negative-weight cycles. 
    // The above step guarantees shortest distances if graph doesn't contain negative weight cycle. 
    // If we get a shorter path, then there is a cycle. 
    for (int i = 0; i < E; i++) 
    { 
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y]) 
        {
            cout << "Graph contains negative weight cycle" << endl; 
        }
    } 
  
    for (int i = 0; i < V; i++) cout << i << "\t\t" << dis[i] << endl; 
} 
  
/////////////
/////////////






