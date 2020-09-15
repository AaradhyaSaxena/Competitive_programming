/////////https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

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
