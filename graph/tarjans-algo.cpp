////// https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo/0

////// Tarjan's algo

#include <bits/stdc++.h>
#define se second
#define pb push_back
#define endll "\n";
using namespace std;
typedef pair<int,int> pp;
int t;
stack<int> s;

void dfs(vector<int> g[],int i,vector<int> &disc,vector<int> &low,
vector<int> &instack,vector<int> &vis){
    vis[i]=1;s.push(i);disc[i]=++t;low[i]=t;instack[i]=1;
    for(int j=0;j<g[i].size();j++){
        if(vis[g[i][j]]==0){
            dfs(g,g[i][j],disc,low,instack,vis);
        }
        if(instack[g[i][j]]){
            low[i]=min(low[i],low[g[i][j]]);
        }
    }
    if(disc[i]==low[i]){
        while(s.top()!=i){
            cout<<s.top()<<" ";
            instack[s.top()]=0;
            s.pop();
        }
        cout<<s.top()<<",";
        instack[s.top()]=0;
        s.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;cin>>tt;
    while(tt--){
        t=0;
        int n,e;cin>>n>>e;
        vector<int> g[n];
        int u,v;
        for(int i=0;i<e;i++){
            cin>>u>>v;
            g[u].pb(v);
        }
        vector<int> disc(n,-1),low(n,-1),instack(n,0),vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(g,i,disc,low,instack,vis);
            }
        }
        cout<<endll;
    }
    return 0;
}
