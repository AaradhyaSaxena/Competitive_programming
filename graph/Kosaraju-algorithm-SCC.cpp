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
    for(int i=0; i<V; i++){
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

#include<bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int> adj[N];
vector<int> rev[N];
vector<bool> vis(N);
int cnt;

void dfs(int s){
    cnt++;
    vis[s] = true;
    for(auto to: rev[s]){
        if(vis[to]==false){
            dfs(to);
        }
    }
}

void toposort(int s, stack<int> &st){
    vis[s] = true;
    for(auto to: adj[s]){
        if(vis[to]==false){
            toposort(to, st);
        }
    }
    st.push(s);
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=1; i<=n; i++){
        vis[i] = false;
        adj[i].clear();
        rev[i].clear();
    }

    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }   
    
    stack<int> st;
    for(int i=1; i<=n; i++){
        if(vis[i]== false){
            toposort(i,st);
        }
    }

    for(int i=0; i<=n; i++){
        vis[i] = false;
    }
    int even = 0, odd = 0;
    while(!st.empty()){
        int p = st.top();
        st.pop();
        // cout<<p<<" ";
        if(vis[p]==false){
            cnt = 0;
            dfs(p);
            // cout<<cnt<<" ";
            if(cnt%2==0){
                even += cnt;
            }else{
                odd += cnt;
            }
        }
    }
    cout<<(odd-even)<<endl;
}








