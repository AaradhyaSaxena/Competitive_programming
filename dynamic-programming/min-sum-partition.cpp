//////https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

//// minimum sum partition

#include <bits/stdc++.h>
using namespace std;

int dp[51][10001];

int helper(int arr[], int n, int i, int diff){
    if(dp[i][diff] != -1){
        return dp[i][diff];
    }
    if(i==n) return diff;
    int temp1 = 0, temp2 = 0;
    dp[i][diff] = min(abs(helper(arr, n, i+1, diff+arr[i])), abs(helper(arr, n, i+1, diff-arr[i])));
    
    return dp[i][diff];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    sort(arr, arr+n);
	    memset(dp,-1,sizeof(dp));
	    cout<<abs(helper(arr,n,0,0))<<endl;
	}
	return 0;
}

////////////

