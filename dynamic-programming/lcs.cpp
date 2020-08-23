////https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0

/// Longest-common-subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m,l,maxx=0;
	    cin>>n>>m>>l;
	    int dp[n+1][m+1][l+1];
	    memset(dp,0,sizeof(dp));
	    string a,b,c;
	    cin>>a>>b>>c;
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	            for(int k=1; k<=l; k++){
	                if(i==0 || j==0 || k==0){
	                    dp[i][j][k] = 0;
	                }else if(a[i-1]==b[j-1] and a[i-1]==c[k-1]){
	                    dp[i][j][k] = 1+ dp[i-1][j-1][k-1];
	                }else{
	                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
	                }    
	            }
	        }
	    }
	    cout<<dp[n][m][l]<<endl;
	}
	return 0;
}