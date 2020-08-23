////https://practice.geeksforgeeks.org/problems/min-coin/0

/// min coin

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[101][100001];

ll count( ll S[], ll n, ll amt){
    if (amt == 0) 
    	return 0;
    if(dp[n][amt] != -1){
        return dp[n][amt];
    }
    if (amt < 0) 
    	return INT_MAX;
	if (n <= 0 && amt >= 1) 
		return INT_MAX;
	
	dp[n][amt] = min(count(S, n, amt-S[n-1])+1, count(S, n - 1, amt));
	
	return dp[n][amt];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll n, amt;
	    cin>>n>>amt;
	    ll arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    for(int i=0; i<n; i++){
	        dp[i][0] = 0;
	    }
	    
	    ll cnt = count(arr,n,amt);
	    if(cnt >= INT_MAX){
	        cout<<-1<<endl;
	    }else{
	        cout<<count(arr,n,amt)<<endl;
	    }
	}
	return 0;
}

//////// SLOW ////////////////
/////  probably incorrect//

#include <bits/stdc++.h>
using namespace std;

int count( int S[], int n, int amt, int cnt ){
    
    if (amt == 0) 
    	return cnt;
    if (amt < 0) 
    	return INT_MAX;
	if (n <=0 && amt >= 1) 
		return INT_MAX;
	
	return min(count(S, n - 1, amt, cnt),count(S, n, amt-S[n-1], cnt+1));
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, amt;
	    cin>>n>>amt;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    int cnt = count(arr,n,amt,0);
	    if(cnt==INT_MAX){
	        cout<<-1<<endl;
	    }else{
	        cout<<count(arr,n,amt,0)<<endl;
	    }
	}
	return 0;
}