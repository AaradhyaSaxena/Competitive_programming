///////https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/// Cycle in directed graph

int check_cycle(int s,int n,vector<int> adj[],vector<bool> &visited){
    visited[s] = true;
    for(auto to : adj[s]){
        if(visited[to] == true) return 1;
        else if(visited[to] == false){
            int result = check_cycle(to,n,adj,visited);
            if(result ==true) return true;
        }
    }
    visited[s] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V+1);
    for(int i=0; i<V; i++){
        visited[i] = false;
    }
    for(int i=0; i<V; i++){
        if(visited[i]==false){
            int result = check_cycle(i,V,adj,visited);
            if(result==1) return 1;    
        }
    }
    return 0;
}

//////

/*
int check_cycle(..................., vector<bool> &visited){
    visited[s] = true;
    for(auto to : adj[s]){
        .......................
    }
    visited[s] = false;
    return false;
}

OR

int check_cycle(..................., vector<bool> visited){
    visited[s] = true;
    for(auto to : adj[s]){
        .......................
    }
    //// visited[s] = false;
    return false;
}

We can use vector<bool> &visited with visited[s] = false or
 we can use vector<bool visited only, here everytime an updated copy is made.

*/


//////////////////////////
////////////////////////
/// edotorial solution

bool cyclic(int i, int V, vector<int> adj[],bool visited[], bool inTheCall[])
{
    visited[i]=true;
    inTheCall[i]=true;
    for(int j =0;j<adj[i].size();j++)
    { 
        if(!visited[adj[i][j]] &&  cyclic(adj[i][j],V,adj,visited,inTheCall))
        {
            return true;
        }
        else{
            if(inTheCall[adj[i][j]])
            return true;
        }
    }
    
    inTheCall[i]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V];
    bool inTheCall[V];
    for(int  i=0;i<V;i++)
    {
        visited[i]=false;
        inTheCall[i]= false;
    }
    
    for(int i =0;i<V;i++)
    {  
    	if(!visited[i]){
    		if(cyclic(i,V,adj,visited,inTheCall))
      		return true;
    	}
    }
    return false;
}

///////////////////////////////
///////////////////////////////