//////////https://codeforces.com/contest/1418

///////// cf round 95

////// p1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
    	ll x,y,k;
    	cin>>x>>y>>k;

    	if((k + k*y - 1) % (x-1) == 0)
    	{
    		ll ans = (k+ k*y - 1)/(x-1) + k;
    		cout<<ans<<endl;
    	}
    	else
    	{
    		ll ans = (k+ k*y - 1)/(x-1) + k + 1;
    		cout<<ans<<endl;
    	}
    }
    return 0;
}


/////////////////// p3

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int dp[1000001];

int helper(int i, int arr[], int n){
	if(i == n-1){
		if(arr[i]==1){
			dp[i] = 1 + dp[i+1];	
		}
	}
	if(i+1 < n){
		if(arr[i]==1 and arr[i+1]==0){
			dp[i] = min(1 + dp[i+4], 1 + dp[i+3]);
		}
		else if(arr[i]==1 and arr[i+1]==1){
			dp[i] = min(1 + dp[i+3], 2 + dp[i+4]);
		}
		else if(arr[i]==0 and arr[i+1]==0){
			dp[i] = min(min(dp[i+4], dp[i+3]), dp[i+2]);
		}
		else if(arr[i]==0 and arr[i+1]==1){
			dp[i] = min(dp[i+3], 1 + dp[i+4]);
		}
	}
  return dp[i];
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, i;
    	cin>>n;
    	int arr[n];
    	for(i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	i=0;
    	int ans = 0;
      for(int i=0; i<n+5; i++){
        dp[i] = 0;
      }
      for(int i=n-1; i>=0; i--){
        dp[i] = helper(i,arr,n);
      }
      cout<<dp[0]<<endl;
    }
    return 0;
}
///////////////////


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



