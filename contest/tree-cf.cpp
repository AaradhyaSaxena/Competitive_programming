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


////////////////

