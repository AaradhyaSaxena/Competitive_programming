//////https://codeforces.com/gym/102694

/////// algo thread tree basics

///// p1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

pair<int,int> bfs(int s, vector<vector<int>> adj){
	int n = adj.size();
	vector<bool> vis(n+1,false);
	vector<int> level(n+1,0);

	queue<int> qt;
	qt.push(s);
	level[s] = 0;

	while(!qt.empty()){
		int t = qt.front();
		qt.pop();
		vis[t] = true;
		for(auto to: adj[t]){
			if(vis[to]==false){
				level[to] = level[t] +1;
				qt.push(to);
			}
		}
	}
	int maxDist = 0;
	int node = s;
	for(int i=1; i<=n; i++){
		if(maxDist<level[i]){
			maxDist = level[i];
			node = i;
		}
	}
	return make_pair(node,maxDist);
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> gr(n+1);
    for(int i=0; i<n-1; i++){
    	int x,y;
    	cin>>x>>y;
    	gr[x].push_back(y);
    	gr[y].push_back(x);
    }
    pair<int,int> t1,t2;

    t1 = bfs(1,gr);
    t2 = bfs(t1.first,gr);
    cout<<3*t2.second<<endl;

    return 0;
}

///////////////// p2

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

pair<int,int> bfs(int i, vector<vector<int>> &adj, vector<int> &level){
	int n = adj.size();
	queue<int> qt;
	qt.push(i);
	level[i] = 0;
	vector<bool> vis(adj.size(), false);
	while(!qt.empty()){
		int p = qt.front();
		qt.pop();
		vis[p] = true;
		for(auto to: adj[p]){
			if(vis[to]==false){
				level[to] = level[p]+1;
				qt.push(to);
			}
		}
	}
	int res = 0, idx = 0;
	for(int i=0; i<n; i++){
		if(level[i]>res){
			res = level[i];
			idx = i;
		}
	}
	return make_pair(res,idx);
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> adj(n+2);
	for(int i=0; i<n-1; i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	pair<int,int> t1, t2, t3;
	vector<int> dist(n+2, 0);
	vector<int> dist2(n+2,0);

	t1 = bfs(1,adj,dist);
	for(int i=0; i<n+2; i++){
		dist[i] = 0;
	}

	t2 = bfs(t1.second,adj,dist);
	t3 = bfs(t2.second,adj,dist2);
	int dia = t3.first;

	int temp = 0;
	int ans = 1;
	for(int i=1; i<=n; i++){
		temp = 0;
		temp = max(dist[i], dist2[i]);
		if(adj[i].size()==1){
			ans = max(dia,temp+1);
		}
		else{
			ans = max(dia,temp);	
		}
		cout<<max(1,ans)<<endl;	
	}
}

//////////////// p3

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

int n, l;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> depth;

void dfs(int v, int p, vector<vector<int>> &adj)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i){
    	up[v][i] = up[up[v][i-1]][i-1];	
    }
    for(int to : adj[v]) {
    	if(to != p){
    		depth[to] = depth[v] + 1;
    		dfs(to, v, adj);
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){

    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root, vector<vector<int>> adj) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l+1));
    dfs(root, root, adj);
}

int main(){
	cin>>n;
	vector<vector<int>> adj(n+1);
	for(int i=0; i<n-1; i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	depth.resize(n+2);
	for(int i=0; i<n+1; i++) depth[i] = 0;
	preprocess(1,adj);

	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int x,y,z;
		cin>>x>>y>>z;
		int lc = lca(x,y);
		int distxy = depth[x] + depth[y] - 2*depth[lc];
		if(distxy<=z){
			cout<<y<<endl;
		}
		else if(depth[x]-depth[lc]>=z){
			cout<<up[x][z-1]<<endl;
		}
		else{
			int left = z - (depth[x]-depth[lc]);
			int dy = (depth[y]- depth[lc]) - left;
			cout<<up[y][dy]<<endl;
		}
	}
}


////////////////// p4

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

int n,m, l;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> parent;

void dfs(int v, int p, vector<vector<int>> &adj)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i){
    	up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int to : adj[v]) {
    	if(to != p){
    		parent[to] = v;
    		dfs(to, v, adj);
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int flow_bt(int x, int y, vector<vector<int>> adj){
	int ans = INT_MAX;

	while(parent[x] != y){
		ans = min(ans,adj[x][parent[x]]);
		x = parent[x];
	}
	ans = min(ans,adj[x][parent[x]]);
	return ans;
}

int lca(int u, int v){

    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root, vector<vector<int>> adj) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l+1));
    dfs(root, root, adj);
}

int main(){
	cin>>n>>m;
	vector<vector<int>> adj(n+2, vector<int> (n+2, 0));
	for(int i=0; i<m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x][y] = z;
		adj[y][x] = z;
	}

	parent.resize(n+2);
	for(int i=0; i<n+3; i++) parent[i] = 1;
	preprocess(1,adj);

	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int x,y;
		cin>>x>>y;
		int lc = lca(x,y);
		cout<<min(flow_bt(x,lc,adj),flow_bt(y,lc,adj))<<endl;		
	}
}

////////////////
//////

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,-1,1};

int ans = INT_MAX;
int n,m;

void dfs(pair<int,int> start,pair<int,int> end,vector<string> &vec,vector<vector<int>> vis,int wall,int tim){
	vis[start.first][start.second] = 1;
	cout<<"lol";

	if(vec[start.first][start.second] == '#'){
		tim += wall;
		wall++;
	}
	tim++;

	if(start==end){
		cout<<tim<<endl;
		ans = min(tim,ans);
		return;
	}

	for(int i=0; i<4; i++){
		int X = start.first + dx[i];
		int Y = start.second + dy[i];
		if(vis[X][Y]==0 and (X>=0 and X<n and Y>=0 and Y<m)){
			dfs(make_pair(X,Y),end,vec,vis,wall,tim);
		}
	}
}


int main(){
	cin>>n>>m;
	vector<string> vec(n+1);
	pair<int,int> start, end;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		vec[i] = s;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(vec[i][j]=='S'){
				start = make_pair(i,j)
			}
			if(vec[i][j]=='G'){
				start = make_pair(i,j)
			}
		}
	}
	ans = INT_MAX;
	vector<vector<int>> vis(n+1, vector<int> (m+1,0));
	int tim = 0;
	cout<<"lol";
	dfs(start,end,vec,vis,0,tim);

	cout<<ans<<endl;
}

//////////////
////////////////
