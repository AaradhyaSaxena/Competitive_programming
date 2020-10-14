/// bfs

//// https://codeforces.com/gym/102694/problem/B

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

///////////
