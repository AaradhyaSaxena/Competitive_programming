/////// standard chartered

// https://www.geeksforgeeks.org/minimum-time-required-to-transport-all-the-boxes-from-source-to-the-destination-under-the-given-constraints/

#include <bits/stdc++.h> 
using namespace std; 
  
bool isPossible(int box[], int truck[],int n, int m, int min_time) 
{ 
    int item = 0; 
    int count = 0; 
  
    while (count < m) { 
        for (int j = 0; j < min_time && item < n && truck[count] >= box[item]; j += 2) {
            item++; 
        }
        count++; 
    } 
    // If all the boxes can be transported in the given time 
    if (item == n) 
        return true; 
    // If all the boxes can't be transported in the given time 
    return false; 
} 
  
// Function to return the minimum time required 
int minTime(int box[], int truck[], int n, int m){ 
  
    sort(box, box + n); 
    sort(truck, truck + m); 
  
    int l = 0; 
    int h = 2 * n; 
  
    // Stores minimum time in which all the boxes can be transported 
    int min_time = 0; 
  
    // Check for the minimum time in which all the boxes can be transported 
    while (l <= h) { 
        int mid = (l + h) / 2; 
  
        // If it is possible to transport all the boxes in mid amount of time 
        if (isPossible(box, truck, n, m, mid)) { 
            min_time = mid; 
            h = mid - 1; 
        } 
        else
            l = mid + 1; 
    } 
  
    return min_time; 
} 
  
int main() 
{ 
    int box[] = { 10, 2, 16, 19 }; 
    int truck[] = { 29, 25 }; 
  
    int n = sizeof(box) / sizeof(int); 
    int m = sizeof(truck) / sizeof(int); 
  
    printf("%d", minTime(box, truck, n, m)); 
  
    return 0; 
} 

//////////////////
////////////////////

///// Market

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool helper(ll mid, ll arr[], ll n, ll tot){
	ll cnt = 0;
	ll item = 0;
	ll sum = 0;
	for(ll i=0; i<n; i++){
		sum += arr[i];
	}
	if(tot/sum >= mid){
		return true;
	}
	return false;
}

int main()
{
	ll n, tot;
	cin>>n>>tot;
	ll arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);

	ll st = 0, end = tot;
	ll ans = 0;
	while(st<end){
		ll mid = st + (end-st)/2;
		if(helper(mid, arr, n, tot)){
			st = mid+1;
			ans = mid;
		}
		else{
			end = mid-1;
		}
	}

	ll sum = 0;
	for(ll i=0; i<n; i++){
		sum += arr[i];
	}

	ll residual = tot - ans*sum;
	ll i=0, cnt=0;
	while(residual>0 and i<n){
		residual -= arr[i];
		i++; cnt++;
	}

	cout<<(ans*sum)+(cnt-1)<<endl;
}

///////////////
/////////////////////

///// dora - explorer

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
     
bool used[20][20];
bool a[20][20];
ll d[20][(1 << 20)], n, m, start; // d[last][Mask]
     
inline bool one (int mask, int p) {
    return (mask & (1 << p));
}
     
ll get (int l, int mask) {
    // cout << Mask (mask) << endl; 
    ll &t = d[l][mask];
        
    if (~t)
        return t;
            
    t = (a[l][start] && __builtin_popcount (mask) > 2);
     
    for(int i = start+1; i != n; i += 1) {
        if (!one (mask, i) && a[l][i])
            t += get (i, mask | (1 << i));
    }
    return t;   
}
     
int main () {

	cin>>n>>m; 
    memset (d, 255, sizeof d);
    
    while (m--) {
        int x, y;
        cin>>x>>y;
        x--, --y;
        a[x][y] = true;
        a[y][x] = true;
    }
     
    ll res = 0;
    
    for(int i = 0; i<n; i++){
        start = i;
        res += get (i, (1 << i));
    }
    
    cout<<(res >> 1)<<endl;
    return 0;
}

///////////////////////
////////////////////
///////////////////////////

//// metro station

#include<bits/stdc++.h>
using namespace	std;

void dfs(int i, vector<vector<int>> adj, vector<int> vis){
	vis[i] =1;
	int n = adj.size()-1;
	for(int j=1; j<=n; j++){
		if(adj[i][j]>0 and vis[j]==0){
			dfs(j,adj,vis);
		}
	}
}

int main(){
	int n,e; cin>>n>>e;
	vector<vector<int>> adj(n+1, vector<int> (n+1, 0));
	for(int i=0; i<e; i++){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x][y] = z;
		adj[y][x] = z;
	}
	vector<int> vis(n+1,0);
	int cnt =0;
	for(int i=1; i<=n; i++){
		if(vis[i]==0){
			dfs(i,adj,vis);
			cnt++;
		}
	}
	if(cnt>1){
		cout<<0<<endl;
	}
	else{
		cout<<1<<endl;
		//// apply kruskals
	}

}

///////////////
/////////////////
///////////////////










