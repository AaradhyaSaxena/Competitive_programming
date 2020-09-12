/////////https://codeforces.com/contests/1406

//// p1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n; cin>>n;
    	int arr[n];
    	int A[101] = {0};
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		A[arr[i]]++;
    	}
    	int sum = 0, flag = 0;
    	for(int i=0; i<=100; i++){
    		if(flag==2){
    			break;
    		}
    		if(A[i]==0 and flag==0){
    			sum += 2*i;
    			flag =2;
    			break;
    		}
    		if(A[i]==1 and flag==0){
    			sum += i;
    			flag = 1;
    		}
    		if(A[i]==0 and flag==1){
    			sum += i;
    			flag=2;
    			break;
    		}
    	}
    	cout<<sum<<endl;
    }
    return 0;
}

////////////////

//// p2

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	ll n; cin>>n;
    	ll arr[n];
    	for(ll i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	sort(arr, arr+n);
    	ll ans = arr[0]*arr[1]*arr[2]*arr[3]*arr[4];
    	if(n==5){
    		cout<<ans<<endl;
    	}
    	else{
    		ans = max(ans,arr[n-5]*arr[n-4]*arr[n-3]*arr[n-2]*arr[n-1]);
    		ans = max(ans,arr[0]*arr[1]*arr[n-3]*arr[n-2]*arr[n-1]);
    		ans = max(ans,arr[0]*arr[1]*arr[2]*arr[n-2]*arr[n-1]);
    		ans = max(ans,arr[0]*arr[1]*arr[2]*arr[3]*arr[n-1]);
    		cout<<ans<<endl;
    	}
    }
    return 0;
}

//////////////

////// p3

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, x, y; 
    	cin>>n;
    	int arr[n+1][2];
    	vector<int> gr[n+1];
    	for(int i=1; i<n; i++){
    		cin>>x>>y;
    		arr[i][0] = x;
    		arr[i][1] = y;
    		gr[x].push_back(y);
    		gr[y].push_back(x);
    	}
    	int dp[n] = {0};
    	int maxx = INT_MIN;
    	for(int i=1; i<=n; i++){
    		dp[i] = gr[i].size();
    		maxx = max(maxx,dp[i]);
    	}
    	int cnt = 0;
    	vector<int> centroid;
    	for(int i=1; i<=n; i++){
    		if(dp[i]==maxx){
    			cnt++;
    			centroid.push_back(i);
    		}
    	}
    	int flag = 0;
    	if(cnt==1){
    		cout<<arr[1][0]<<" "<<arr[1][1]<<endl;
    		cout<<arr[1][0]<<" "<<arr[1][1]<<endl;
    	}
    	else{
    		for(int i=0; i<centroid.size(); i++){
    			for(int j=i+1; j<centroid.size(); j++){
    				for(int k=0; k<gr[centroid[i]].size(); k++){
    					if(gr[centroid[i]][k]==centroid[j]){
    						cout<<centroid[i]<<" "<<centroid[j]<<endl;
    						if(k != 0) cout<<gr[centroid[i]][k-1]<<" "<<centroid[j]<<endl;
    						else cout<<gr[centroid[i]][k+1]<<" "<<centroid[j]<<endl;
    						flag =1;
    						break;
    					}
    					if(flag==1) break;
    				}
    				if(flag==1) break;
    			}
    			if(flag==1) break;
    		}
    	}
    }
    return 0;
}


///////////

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int helper(ll B[], ll C[]){

}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	ll n;
    	ll arr[n];
    	ll B[n]; ll C[n] = {0};
    	for(ll i=0; i<n; i++){
    		cin>>arr[i];
    		B[i] = arr[i];
    	}
    	

    }
    return 0;
}

///////////

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){

//     }
//     return 0;
// }

///////////////////

