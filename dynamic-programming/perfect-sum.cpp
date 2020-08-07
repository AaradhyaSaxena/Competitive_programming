/// https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0

#include <bits/stdc++.h>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, sum; cin >> n;
	    
	    vector<int> v(n);
	    for(int i = 0; i < n; i++) cin >> v[i];
	    cin >> sum;
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
	    
	    for(int i = 0; i <= n; i++) dp[i][0] = 1; 
	    for(int j = 1; j <= sum; j++) dp[0][j] = 0;
	    
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= sum; j++){
	            if(v[i-1] > j) dp[i][j] = dp[i-1][j];
	            else{
	                dp[i][j] = (dp[i-1][j - v[i-1]] + dp[i-1][j])%1000000007;
	            }
	        }
	    }
	    cout << dp[n][sum]%1000000007 << endl;
	}
	return 0;
}

///////////////////////

// #include <bits/stdc++.h>
// using namespace std;

// int dp[1001][1001];
// int mod = 1000000007;

// int helper(int arr[], int sum, int n, int &cnt){
//     if(sum<0) return 0;
//     if(sum==0){
//         return cnt+1;
//     }
//     if(dp[sum][n]!= 0){
//         return dp[sum][n];
//     }
//     if(sum>0 and n>0){
//         dp[sum][n] = helper(arr,sum-arr[n-1],n-1,cnt) + helper(arr,sum,n-1,cnt);
//         return dp[sum][n]%mod;
//     }
// }

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n, sum, cnt=0;
// 	    cin>>n;
// 	    int arr[n];
// 	    for(int i=0;i<n;i++){
// 	        cin>>arr[i];
// 	    }
// 	    cin>>sum;
// 	    memset(dp,0,sizeof(dp));
	    
// 	    int ans = helper(arr,sum,n,cnt)%mod;
// 	    cout<<ans<<endl;
	    
// 	   // for(int i=0; i<=sum; i++){
// 	   //     for(int j=0; j<=n; j++){
// 	   //         cout<<dp[i][j]<<" ";
// 	   //     }cout<<endl;
// 	   // }
// 	}
// 	return 0;
// }

