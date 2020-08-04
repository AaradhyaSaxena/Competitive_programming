/// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    int dp[n];
	    dp[n-1] = 0;
	    int min_jump;
	    for(int i=n-2; i>=0; i--){
	        if(arr[i]==0) dp[i] = INT_MAX;
	        if(arr[i] >= n-1-i){
	            dp[i] = 1;
	        }else{
	            min_jump = INT_MAX;
	            for(int j=i+1; j<=i+arr[i] && j<n; j++ ){
	                if(dp[j] < min_jump) min_jump = dp[j];
	            }
	            ////// mistake*
	            if(min_jump != INT_MAX){
	            	dp[i] = 1 + min_jump;
	            }else{
	            	dp[i] = INT_MAX;
	            }
	        }
	    }
	    if(dp[0] != INT_MAX){
	        cout<<dp[0]<<endl;
	    }else{
	        cout<<-1<<endl;
	    }
	    
	}
	return 0;
}

/////////////////////////
/*
In place of command:

if(min_jump != INT_MAX){
	dp[i] = 1 + min_jump;
}else{
	dp[i] = INT_MAX;
}

i wrote:
dp[i] = 1 + min_jump;

but that gave me an error
because INT_MAX + 1 = INT_MIN.
overflow!!

*/
