///////https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/

///// Articulation-points ans bridges

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

void dfs(int u, vector<vector<int> >& adjList, vector<int>& disc, 
			vector<int>& low, vector<bool>& visited, vector<bool>& ap,
			vector<pair<int, int> >& bridges, int parent)
{
	static int time = 1;
	disc[u] = low[u] = time++;
	
	int child = 0;
	visited[u] = true;
	
	for (auto& to: adjList[u])
	{
		if (!visited[to])
		{
			child++;
			dfs(to, adjList, disc, low, visited, ap, bridges, u);
			low[u] = min(low[u], low[to]);

			if (parent == -1 && child > 1) 
				ap[u] = true;

			else if (parent != -1 && low[to] >= disc[u]) 
				ap[u] = true;
		
			if (low[to] > disc[u]) ///  this is (>) the other one (>=);
				bridges.push_back({u, to});
		}
		else if (to != parent)
		{
			low[u] = min(low[u], disc[to]);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjList(n);

	for (int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	vector<bool> visited(n, false);
	vector<bool> ap(n, false);
	vector<pair<int, int> > bridges;
	vector<int> disc(n, INT_MAX);
	vector<int> low(n, INT_MAX);

	int count=0;
	for (int i=0;i<n;i++){
		if (!visited[i])
			dfs(i, adjList, disc, low, visited, ap, bridges, -1);
	}
	
	for (int i=0;i<n;i++){
		if (ap[i]) 
			count++;
	}
	cout << count << endl;
	
	for (int i=0;i<n;i++){
		if (ap[i]) 
			cout << i << " ";
	}
	cout << endl;
	
	auto compare = [&](auto a, auto b)
	{
		return a.first<b.first || (a.first==b.first && a.second<b.second);
	};
	
	sort(bridges.begin(), bridges.end(), compare);
	cout << bridges.size() << endl;
	
	for (auto& ele: bridges)
	{
		cout << ele.first << " " << ele.second << endl;
	}

	return 0;
}

//////

/*
https://www.hackerearth.com/practice/notes/nj/
*/

/////// incorrect

#include<bits/stdc++.h>
using namespace std;

bool visited[20];
int low[20];
int pos[20];
int adj[20][20];
int ticker;
vector<vector<int>> br;
vector<int> pt;

void dfs(int s, int parent){
	visited[s] = true;
	low[s] = pos[s] = ticker++;
	int children =0;
	for(int i=0; i<20; i++){
		int to = i;
		if(adj[s][i]==0) continue;
		if(to==parent) continue;
		if(visited[to]==true){
			low[to] = min(pos[to], low[s]);
		}
		else{
			dfs(to,s);
			low[s] = min(low[s], low[to]);
			if(low[to] > pos[s] ){
				vector<int> vec;
				vec.push_back(s); 
				vec.push_back(to);
				br.push_back(vec);
			}
			if(low[to] >= pos[s] and parent != -1){
				pt.push_back(s);
			}
			children++;
		}
	}
	if(parent==-1 and children>1){
		pt.push_back(s);
	}
}

int main(){
	int n, m, x, y;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			adj[i][j] = 0;
		}
	}
	for(int i=0; i<m; i++){
		cin>>x>>y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
	for(int i=0; i<n; i++){
		visited[i] = false;
		low[i] = pos[i] = 0;
	}
	ticker = 0;
	for(int i=0; i<n; i++){
		if(visited[i]==false){
			dfs(i, -1);
		}
	}
	cout<<pt.size()<<endl;
	for(int i=0; i<pt.size(); i++){
		cout<<pt[i]<<endl;
	}
	sort(br.begin(), br.end());
	cout<<br.size()<<endl;
	for(int i=0; i<br.size(); i++){
		cout<<br[i][0]<<" "<<br[i][1]<<endl;
	}
}
///////////
