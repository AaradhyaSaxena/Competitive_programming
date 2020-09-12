//// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

////// kosaraju's algorithm

void DFSS(int x,bool visited[],vector<int> rev[]){
    visited[x]=true;
    for(auto i:rev[x]){
        if(!visited[i])
            DFSS(i,visited,rev);
    }
}

void dfs1(vector<int> adj[],bool visited[],stack<int> &st,int s){
    visited[s]=true;
    for(auto i:adj[s]){
        if(!visited[i]){
            dfs1(adj,visited,st,i);
        }
    }
    st.push(s);
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    bool visited[V] = {};
    for(int i=0;i<V;i++){
        if(!visited[i])
        {
            dfs1(adj,visited,st,i);
        }
    }
    int count=0;
    vector<int> rev[V];
    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            rev[j].push_back(i);
        }
    }
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    while(!st.empty()){
        int x=st.top();
        st.pop();
        if(!visited[x]){
            DFSS(x,visited,rev);
            count++;
        }
    }
    return count;       
}

///////////////








