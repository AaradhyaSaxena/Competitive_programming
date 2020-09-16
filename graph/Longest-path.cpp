/////https://practice.geeksforgeeks.org/problems/save-winterfell/0

/// Longest-path

////////////

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int,int>> v[], int sta, bool vis[], int dis[]){
    vis[sta] = true;
    
    for(auto i:v[sta]){
        if(vis[i.first] == false)
        {
            dis[i.first] = dis[sta] + i.second;
            dfs(v,i.first,vis,dis);
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    vector<pair<int,int>> v[n+1];
	    for(int i=1; i<n; i++){
	        int x, y, k;
	        cin>>x>>y>>k;
	        v[x].push_back(make_pair(y,k));
	        v[y].push_back(make_pair(x,k));
	    }
	    int max = 0;
	    bool vis[n+1];
	    memset(vis, false, sizeof(vis));
	    int dis[n+1];
	    int point;
	    dis[1] = 0; 
	    
	    dfs(v,1,vis,dis);
	    for(int i=1; i<=n; i++)
	    	if(dis[i] > max){
	    	    max = dis[i];
	    	    point = i;
	    	}

	    memset(vis,false,sizeof(vis));
	    memset(dis,0,sizeof(dis));
	    dfs(v,point,vis,dis);
	    max = 0;
	    for(int i=1; i<=n; i++)
	    	if(dis[i] > max){
	        	max = dis[i];
	          	point = i;
	     	}
        cout<<max<<endl;
	}
	return 0;
}


///////////////

/*

First use DFS using any vertice to calculate longest distance,
then again do DFS for vertex having longest distance in first iteration.

Double-dfs >> tree for longest path. 

*/

////////////////////
////////////////////

#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int>mp;
int ans;

int dfs(vector<int>adj[], int v, int parent)
{
    int first = 0;
    int second = 0;

    for(int i=0; i<adj[v].size(); i++){
        if(adj[v][i] != parent)
        {
            int dist = mp[{v, adj[v][i]}] + dfs(adj, adj[v][i], v);
            if(dist > first)
            {
                second = first;
                first = dist;
            }
            else if(dist > second)
                second = dist;
        }
    }
    if(ans < first + second)
      	ans = first + second;
    
    return first;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> adj[n+1];
	    int i = 1;
	    ans = 0;
	    mp.clear();
	    while(i<n)
	    {
	        int x, y, z;
	        cin>>x>>y>>z;
	        adj[x].push_back(y);
	        adj[y].push_back(x);
	        mp[{x,y}] = z;
	        mp[{y,x}] = z;
	        i++;
	    }
	    dfs(adj,1,0);
	    cout<<ans<<endl;
	}
	return 0;
}

////////////
////////////