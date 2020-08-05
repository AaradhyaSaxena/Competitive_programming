/// https://practice.geeksforgeeks.org/problems/skip-the-work/0

#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n], dp[n];
	    int i=0, ans = 0;
	    for(i=0; i<n; i++){
	        cin>>arr[i];
	        dp[i] = arr[i];
	    }
	    if(n==1){
	        ans = 0;
	    }else if(n==2){
	        ans = min(arr[0], arr[1]);
	    }else{
	        for(i = n-3; i>=0; i--){
	            dp[i] += min(dp[i+1], dp[i+2]);
	        }
	        ans = min(dp[0],dp[1]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}