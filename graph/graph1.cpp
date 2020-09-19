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

////////////////////////////

//////////// floyd-warshalls

vector <int> floyd_warshalls(vector<vector<int>> g, int src, int V) {
    // int dp[V][V] = {INT_MAX};
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                // if( i != j and g[i][j]==0) g[i][j] = 1000000; // wt zero is treated as no edge
                if(g[i][j] > g[i][k]+ g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
                // if(i==j) g[i][j] = 0;
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

///// Hamiltonian Path

#include <bits/stdc++.h> 
using namespace std; 
  
// Number of vertices in the graph  
int V;  
  
void printSolution(int path[]);  
  
// Checks if the vertex v can be added at index 'pos'
bool isSafe(int v, bool graph[V][V], int path[], int pos)  
{  
    // Check if this vertex is an adjacent vertex of the previously added vertex. 
    if (graph [path[pos - 1]][ v ] == 0)  
        return false;  
  
    // Check if the vertex has already been included.  
    for (int i = 0; i < pos; i++)  
        if (path[i] == v)  
            return false;  
  
    return true;  
}  
  
bool hamCycleUtil(bool graph[V][V], int path[], int pos)  
{  
    // base case: If all vertices are included in Hamiltonian Cycle 
    if (pos == V)  
    {  
        // And if there is an edge from the last included vertex to the first vertex  
        if (graph[path[pos - 1]][path[0]] == 1)  
            return true;  
        else
            return false;  
    }  
  
    // Try different vertices as a next candidate in Hamiltonian Cycle. 
    // We don't try for 0 as we included 0 as starting point in hamCycle()  
    for (int v = 1; v < V; v++)  
    {  
        // Check if this vertex can be added to Hamiltonian Cycle 
        if (isSafe(v, graph, path, pos))  
        {  
            path[pos] = v;  
  
            // recur to construct rest of the path 
            if (hamCycleUtil (graph, path, pos + 1) == true)  
                return true;  
  
            // If adding vertex v doesn't lead to a solution, then remove it 
            path[pos] = -1;  
        }  
    }  
    return false;  
}  
  
bool hamCycle(bool graph[V][V]){

    int *path = new int[V];  
    for (int i = 0; i < V; i++)  
        path[i] = -1;  
  
    // Let us put vertex 0 as the first vertex in the path. 
    path[0] = 0;  

    if(hamCycleUtil(graph, path, 1) == false) {  
        cout << "\n Solution does not exist";  
        return false;  
    }  
  
    printSolution(path);  
    return true;  
}  
  
void printSolution(int path[]){
    cout << "Solution Exists: Following is one Hamiltonian Cycle \n";  
    
    for (int i = 0; i < V; i++){
        cout << path[i] << " ";  
    }  
    // Let us print the first vertex again to show the complete cycle  
    cout << path[0] << " ";  
    cout << endl; 
}  


int main()  
{  
    bool graph1[V][V] = {{0, 1, 0, 1, 0}, {1, 0, 1, 1, 1}, {0, 1, 0, 0, 1}, {1, 1, 0, 0, 1}, {0, 1, 1, 1, 0}};  
    hamCycle(graph1);  
      
    bool graph2[V][V] = {{0, 1, 0, 1, 0}, {1, 0, 1, 1, 1}, {0, 1, 0, 0, 1}, {1, 1, 0, 0, 0}, {0, 1, 1, 0, 0}};
    hamCycle(graph2);  
  
    return 0;  
}  
  
/////////////////
/////////////////














































