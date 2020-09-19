//////https://www.geeksforgeeks.org/maximum-bipartite-matching/

/// Maximum bipartite matching
  
bool bfs(vector<vector<int>> &r,int parent[],int n){
    bool vis[n];
    memset(vis,false,sizeof(vis));
    parent[0]=-1;
    vis[0]=true;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        
        int j=q.front();
        q.pop();

        for(int i=0;i<n;i++)
        {
            if(vis[i]==false&&r[j][i]>0)
            {
                vis[i]=true;
                q.push(i);
                parent[i]=j;
            }
        }
    }
    return vis[n-1];
}

// see how the bipartite graph is build
int maxBPM(bool bp[M][N],int m,int n)
{
	vector<int> temp(n+m+2);
	vector<vector<int>> v(n+m+2,temp);
 	for(int i = 0; i < n+m+2; i++)
  		for(int j = 0; j < n+m+2; j++)
   			v[i][j] = 0;

 	for(int i = 1; i <= m; i++)
   		v[0][i] = 1;
 	
 	for(int j = m+1; j <= n+m; j++)
   		v[j][n+ m+ 1] = 1;
  	
  	for(int i=0; i<m; i++)
    	for(int j=0; j<n; j++)
    		if(bp[i][j]){
        		v[i+1][m+1+j] = 1;
      		}
    
    int parent[n + m + 2];
	int maxf = 0, path;
	
	while(bfs(v,parent,n+m+2)){
	   
	    for(int i = n+m+1; i!=0; i = parent[i]){
	        v[parent[i]][i] -= 1;
	        v[i][parent[i]] += 1;
	    }
	    maxf += 1;  
	}
    return maxf;    
}

//////////