/////https://practice.geeksforgeeks.org/problems/minimum-time/0

//// insert-remove-copy

#include <bits/stdc++.h>
using namespace std;

int minTimeForWritingChars(int N, int in, int rm, int cp){ 
    if (N == 0) 
       return 0; 
    if (N == 1) 
       return in; 
  
    int dp[N + 1]; 
    memset(dp, 0, sizeof(dp)); 
    dp[0] = 0; dp[1] = in;
  
    for (int i = 1; i <= N; i++){ 
        if (i % 2 == 0){
        	dp[i] = min(dp[i-1] + in, dp[i/2] + cp); 
        } 
        else{
            dp[i] = min(dp[i-1] + in, dp[(i+1)/2] + cp + rm); 
        }
    } 
    return dp[N]; 
} 
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,in,rm,cp;
	    cin>>n>>in>>rm>>cp;
	    cout<<minTimeForWritingChars(n,in,rm,cp)<<endl;
	}
	return 0;
}