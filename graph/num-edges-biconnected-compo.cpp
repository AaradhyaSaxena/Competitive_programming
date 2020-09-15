/////// https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/

/// biconnected

#include <bits/stdc++.h>
using namespace std;

int odd=0;
int even=0;

void dfs(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low,
		int parent, stack<pair<int, int> >& stk, vector<vector<int> >& adjList){

	static int time = 1;
	disc[u] = low[u] = time++;
	visited[u] = true;
	int child = 0;
	int count = 0;
	for (auto& ele: adjList[u]){
		if ( !visited[ele] ){
			child++;
			stk.push({u, ele});
			dfs(ele, visited, disc, low, u, stk, adjList);
			low[u] = min(low[u], low[ele]);
		
			if ((parent == -1 && child > 1) || (parent != -1 && low[ele] >= disc[u])){
				while (stk.top().first != u && stk.top().second != ele){
					stk.pop();
					count++;
				}
				stk.pop();
				if (count&1) odd++;
				else even++;
			}
		}
		else if (ele != parent && disc[ele]<low[u]){
			low[u] = disc[ele];
			stk.push({u, ele});
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > adjList(n);
	for (int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	vector<bool> visited(n, false);
	vector<int> disc(n, INT_MAX);
	vector<int> low(n, INT_MAX);
	stack<pair<int, int> > stk;

	for (int i=0;i<n;i++){
		if (!visited[i]){
			int count=0;
			dfs(i, visited, disc, low, -1, stk, adjList);
			while (!stk.empty()){
				count++;
				stk.pop();
			}
			if (count != 0)
				if (count&1) odd++;
				else even++;
		}
	}
	cout << odd << " " << even << endl;
	return 0;
}

////////////
