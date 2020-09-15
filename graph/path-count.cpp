///////https://practice.geeksforgeeks.org/problems/path-count-in-directed-graph/1

//// path count

void dfs(int s,int d,int &count,bool vis[])
{
    if(s==d)
    {
        count++;
        return ;
    }
    vis[s]=1;
    for(auto i: adj[s])
    {
        if(vis[i]==0)
        {
            dfs(i,d,count,vis);
        }
    }
    vis[s]=0; //////////
}
int countPaths(int s, int d)
{
    bool vis[V]={0};
     int count=0;
     dfs(s,d,count,vis);
     return count;
}