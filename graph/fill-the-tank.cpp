//////https://practice.geeksforgeeks.org/problems/fill-the-tank/0

//// Fill the tank

#include<bits/stdc++.h>
using namespace std;

long long  int a[100001];
long long int maxim=1e18;
int flag;

long long int dfs(vector<int>adj[], int v, int parent)
{
	long long int maxi = 0;
    for(int i=0; i<adj[v].size(); i++){
        if(adj[v][i] != parent)
            maxi = max(maxi, dfs(adj, adj[v][i], v));
    }
    long long int ans;

    if(parent==0)
    	ans = a[v]+(adj[v].size()*maxi);
    else
    	ans= a[v]+((adj[v].size()-1)*maxi);

  	if(ans > maxim)
  	{
    	flag=1;
    	return 0;
  	}
  	else
    	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int s;
	    cin>>s;
	    vector<int>vec[n+1];
	    for(int i=1;i<=n;i++)
	  		cin>>a[i];
	    for(int i=1;i<n;i++){
			int x,y;
		    cin>>x>>y;
		    vec[x].push_back(y);
		    vec[y].push_back(x);
		}

		flag=0;
		long long int z = dfs(vec,s,0);
		
		if(flag)
			cout<<-1<<endl;
		else
			cout<<z<<endl;
	}
	return 0;
}

///////

/*

Solution: Looking at the constraints i.e, Amount of water avilable is (10)^18, 
So answer lies between 1 - (10)^18 and number of tanks is <= 100000, 
We can conclude that to find answer optimally we can do a binary search 
for the answer by simulating the process for each mid value.
After doing a binary search if the ans is 1e18+1 return -1. 
Simulation of pocess can be done by doing depth first search 

Computing the Time Complexity for the solution: 
Time taken for binary search is log2(1e18+1) and the process is simulated for these many times, 
Therefore total time taken is n*log(1e18+1), for t test cases it is t*n*log(1e18+1)

*/

/////// incorrect attempt

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;

// int helper(vector<vector<ll>> &adj, vector<ll> &cap, int n, int s, vector<bool> &vis, vector<ll> &added){
//     vis[s] = true;
//     ll temp = 0, maxx = INT_MIN;
//     for( auto to: adj[s]){
//         if(vis[to] == false){
//             temp = helper(adj,cap,n,to,vis,added);
//         }
//         maxx = max(maxx, temp);
//     }
//     added[s] = cap[s-1] + maxx*(adj[s].size());
//     return added[s];
// }

// int main() {
// 	ll t; cin>>t;
// 	while(t--){
// 	    ll n, s;
// 	    cin>>n>>s;
// 	    vector<ll> cap(n+1);
// 	    for(int i=0; i<n; i++){
// 	        cin>>cap[i];
// 	    }
// 	    vector<vector<ll>> adj(n+1);
// 	    for(int i=0; i<n-1; i++){
// 	        int x,y;
// 	        cin>>x>>y;
// 	        adj[x].push_back(y);
// 	    }
// 	    vector<bool> vis(n+1, false);
// 	    vector<ll> added(n+1,0);
// 	    int ans = helper(adj,cap,n,s,vis,added);
// 	    if(ans>1e18 or ans<0){
// 	        cout<<-1<<endl;
// 	    }else{
// 	        cout<<ans<<endl;    
// 	    }
// 	}
// 	return 0;
// }

//////////