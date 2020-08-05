//// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n], dp[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        dp[i] = arr[i];
	    }
	    int maxx = 0;
	    for(int i=n-2; i>=0; i--){
	        maxx = 0;
	        for(int j=i+1; j<n; j++){
	            if(arr[i]<arr[j] and dp[j]>=maxx){
	                dp[i] = dp[j] + arr[i];
	                maxx = dp[j];
	            }
	        }
	    }
	    maxx = 0;
	    for(int i=0; i<n; i++){
	        maxx = max(maxx,dp[i]);
	    }
	    cout<<maxx<<endl;
	}
	return 0;
}