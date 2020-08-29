/////////https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0

//// min points to reach the end

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int arr[n][m];
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin>>arr[i][j];
	        }
	    }
	    int dp[n][m];
	    if(arr[n-1][m-1]>0){
	        dp[n-1][m-1] = 1;
	    }else{
	        dp[n-1][m-1] = abs(arr[n-1][m-1]) + 1;
	    }
	    
	    for(int j=m-2; j>=0; j--){
	        dp[n-1][j] = max(dp[n-1][j+1]-arr[n-1][j], 1);
	    }
	    for(int i=n-2; i>=0; i--){
	        dp[i][m-1] = max(dp[i+1][m-1]-arr[i][m-1], 1);
	    }
	    for(int i=n-2; i>=0; i--){
	        for(int j=m-2; j>=0; j--){
	            int temp = min(dp[i+1][j], dp[i][j+1]);
	            dp[i][j] = max(temp-arr[i][j], 1);
	        }
	    }
	   // for(int i=0; i<n; i++){
	   //     for(int j=0; j<m; j++){
	   //         cout<<dp[i][j]<<" ";
	   //     }cout<<endl;
	   // }
	    cout<<dp[0][0]<<endl;
	}
	return 0;
}