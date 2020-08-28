///////https://practice.geeksforgeeks.org/problems/little-murph-and-knots/0

//// permutation-dp

#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long int dp[1001][1001];

long long int sri(int n,int r){
    if(r==0 || n==r)
        return dp[n][r]=1;
    else if(dp[n][r]==-1)
        return dp[n][r]=(sri(n-1,r-1)%mod + sri(n-1,r)%mod)%mod;
    return dp[n][r];
}

int main(){
    for(int i=0;i<=1000;i++){
    	for(int j=0;j<=1000;j++){
    		dp[i][j]=-1;
        	sri(1000,1000);
    	}
    }
	int t;
	cin>>t;
	while(t--){
	    int m,n,k;
	    cin>>m>>n>>k;
	    long long int count=0;
	    count = ( sri(m,k)%mod * sri(n,k)%mod )%mod;
	    cout<<count<<endl;
	}
	return 0;
}


/*
We need to select K hooks from M hooks on wall A and K hooks from N hooks on wall B. 
This can be done in C(M, K)*C(N, K) where C(a, b) = Choose(a,b) = a!/(b!*(a-b)!).

We calculate all the combinations C(i, j) for 2<= i, j <= 1000 using the property C(i, j) = C(i-1, j) + C(i-1, j-1).         

After calculating all the combination values, the answers can be obtained in O(1) time complexity.

The values can also be obtained from Pascal’s triangle.
*/



