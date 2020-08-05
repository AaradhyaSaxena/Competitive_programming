//// https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0

#include <bits/stdc++.h>
using namespace std;

int dp[21][21];

int helper(int m, int n){
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    dp[m][n] = helper(m-1,n) + helper(m,n-1);
    return dp[m][n];
}

int main() {
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<21;i++){
	    dp[1][i] = 1;
	    dp[i][1] = 1;
	}
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    cout<<helper(m,n)<<endl;
	}
	return 0;
}