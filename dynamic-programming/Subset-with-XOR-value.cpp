//////https://practice.geeksforgeeks.org/problems/subsets-with-xor-value/0

/// Subset with XOR value

#include <bits/stdc++.h>
using namespace std;

int helper(int arr[], int n, int k){
    if(n==1 and arr[0]!=k) return 0;
    int maxx = INT_MIN;
    for(int i=0; i<n; i++){
        maxx = max(maxx, arr[i]);
    }
    int m = pow(2, log2(maxx)+1);
    if(k>m){
        return 0;
    }
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];
        }
    }
    return dp[n][k];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cout<<helper(arr,n,k)<<endl;
	}
	return 0;
}










