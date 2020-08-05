/// https://practice.geeksforgeeks.org/problems/reach-a-given-score/0

#include<bits/stdc++.h>
using namespace std;

int dp[1001][3];

int main() {
	int t,n,x,y;
	cin>>t;
	int arr[3] = {3,5,10};
	memset(dp,0,sizeof(dp));
	for(int j=0;j<=3; j++){
	    dp[0][j] = 1;
	}
	for(int i=1; i<1001; i++){
	    for(int j=0; j<3; j++){
	    	// including num
	        x = (i-arr[j] >= 0)? dp[i-arr[j]][j]: 0;
	        // excluding num
	        y = (j>=1)? dp[i][j-1]: 0;
	        dp[i][j] = x+y;
	    }
	}
	while(t--){
	    cin>>n;
	    cout<<dp[n][2]<<endl;
	}
	return 0;
}