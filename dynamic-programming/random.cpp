///////// rough work

/////

#include <bits/stdc++.h>
using namespace std;

#define maxx 1001
int dp[maxx][maxx][maxx];

int helper(int arr[], int n, int i, int inc, int dec){
	if(i==n){
		return 0;
	}
	// if(dp[i][inc][dec] != -1){
	// 	return dp[i][inc][dec];
	// }
	// int temp1 = 0, temp2 = 0, temp3 = 0;
	// if(arr[inc]<arr[i]){
	// 	temp = helper(arr,n,i+1,i,dec);
	// }
	// if(arr[dec]>arr[i]){
	// 	temp = helper(arr,n,i+1,inc,i);
	// }
	// temp = helper(arr,n,i+1,inc,dec);

	// dp[i][inc][dec] = max(temp1,max(temp2,temp3));

	// return dp[i][inc][dec];
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
		// memset(dp,-1,sizeof(dp));
		// for(int i=0; i<maxx; i++){
		// 	dp[i][0][0] = 0;
		// }
		// helper(arr,n,2,1,0);
	}
	return 0;
}