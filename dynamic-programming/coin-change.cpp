//// https://practice.geeksforgeeks.org/problems/coin-change/0/

#include <bits/stdc++.h>
using namespace std;

int helper(int arr[], int m, int n){
	int i,j;

	int dp[m+1][n];
	memset(dp,0,sizeof(dp));
	for(i=0; i<n; i++){
		dp[0][i] = 1;
	}
	for(i=1; i<=m; i++){
		for(j=0; j<n; j++){
			// including j 
			int x = (i - arr[j] >=0)? dp[i-arr[j]][j]: 0;
			// excluding j
			int y = (j>=1)? dp[i][j-1]: 0;
			dp[i][j] = x + y;
		}
	}
	return dp[m][n-1];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cin>>m;
	    cout<<helper(arr,m,n)<<endl;
	}
	return 0;
}


//////////////////

int helper(int arr[], int m, int n){
    if(m == 0) return 1;
    if(m < 0) return 0;
    if(m >= 1 and n <= 0) return 0;
    return helper(arr,m,n-1) + helper(arr,m-arr[n-1],n);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cin>>m;
	    cout<<helper(arr,m,n)<<endl;
	}
	return 0;
}

