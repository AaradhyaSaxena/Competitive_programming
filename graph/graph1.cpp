/////https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
/////////// level nodes

//// BFS

#include<bits/stdc++.h>
using namespace std;

#define N 100000
vector<int> adj[N];
bool visited[N];
int level[N] = {0};
int k;

void BFS(int s,int x){
    level[s]=1;
    queue <int> q;
    q.push(s);
    visited[s]=true;

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0; i<adj[p].size();i++){
            if(visited[adj[p][i]] == false){
                level[adj[p][i]] = level[p]+1;
                if(level[adj[p][i]]==x){
                    k++;
                }
                q.push(adj[p][i]);
                visited [adj[p][i]]=true;
            }
        }
    }
}

int main(){
    int x,y,nodes;
    cin>>nodes;
    for(int i=0;i<nodes-1;i++){
        cin>>x;
        cin>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int b;
    cin>>b;
    BFS( 1,b);

    cout<<k;
    return 0;
}

///////////////////////

//// DFS

#include<bits/stdc++.h>
using namespace std;

#define N 100000
vector<int> vec[N];
bool vis[N];

void dfs(int u){
    vis[u] = 1;
    for(int i=0; i<vec[u].size(); i++){
        if(!vis[vec[u][i]]){
            dfs(vec[u][i]);
        }
    }
}

int main(){
    int n,m,x,y,k;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    cin>>k;
    
    dfs(k);
    
    int ans =0;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//////////////////////////

///// Kruskals

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;

int id[MAX], nodes, edges;
pair <long long, pair<int,int>> p[MAX];

void initialize(){
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x){
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y){
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[]){
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i){
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main(){
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}

////////////////////////////////

///// Shortest Path

#include <bits/stdc++.h>
#define ll long long
#define T ll t; cin>>t; while(t--)
using namespace std;
#define speed ios_base::sync_with_stdio(0)
#define endl "\n"

vector <pair<int,int>> adj[1000001];
ll c = 1000000000;
bool visited[1000001];
ll dist[1000001];

void intialization(int n){
    for(ll i=0; i<=n; i++){
        visited[i] = 0;
        dist[i] = c;
    }
}

void dijkstras(){
    ll st = 1;
    dist[st] = 0;

    multiset <pair<int, int>> s;
    s.insert({0, st});
    
    while(!s.empty()){
        ll from, to, cost;
        pair<int,int> p = *s.begin();
        s.erase(s.begin());
        from = p.second;

        if(visited[from]) 
            continue;
        
        visited[from] = 1;
        
        for(ll i=0; i<adj[from].size(); i++){
            cost = adj[from][i].first;
            to = adj[from][i].second;
            if(dist[from] + cost < dist[to]){
                dist[to] = dist[from] + cost;
                s.insert({dist[to], to});
            }
        }
    }
}

int main(){
    speed;
    ll nodes,edges,i;
    cin>>nodes>>edges;
    intialization(nodes);

    for(i=0;i<edges;i++){
        ll from,to,cost;
        cin>>from>>to>>cost;
        adj[from].push_back({cost,to});
    }
    dijkstras();
    for(i=2;i<=nodes;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}


















































