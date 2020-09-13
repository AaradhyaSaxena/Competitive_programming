///////https://practice.geeksforgeeks.org/problems/bipartite-graph/1

///// Bipartite graph

bool isBipartite(int G[][MAX],int V)
{
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
        colorArr[i] = -1; 
    
    int src = 0;
    colorArr[src] = 1; 
  
    queue <int> q; 
    q.push(src); 
  
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        if (G[u][u] == 1) return false;  
  
        for (int v = 0; v < V; ++v) 
        { 
        	if (G[v][v] == 1) return false;  
            if (G[u][v] && colorArr[v] == -1) 
            { 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination v is colored with same color as u 
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
  
    return true; 
}

//////////