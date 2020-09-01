//////////https://practice.geeksforgeeks.org/problems/longest-zig-zag-sub-sequence/0

//// zigzag sequence

#include <bits/stdc++.h> 
using namespace std;
    
int zzis(int arr[], int n) 
{ 
	/// Z[i][0] = Length of the longest Zig-Zag subsequence ending at index i and last element is greater than its previous element 
	/// Z[i][1] = Length of the longest Zig-Zag subsequence ending at index i and last element is smaller than its previous element 

    int dp[n][2]; 
    for (int i = 0; i < n; i++) 
        dp[i][0] = dp[i][1] = 1; 
    
    int res = 1; 
    
    for (int i = 1; i < n; i++) 
    { 
        for (int j = 0; j < i; j++) 
        { 
            if (arr[j] < arr[i] && dp[i][0] < dp[j][1] + 1) 
                dp[i][0] = dp[j][1] + 1; 
  
            if( arr[j] > arr[i] && dp[i][1] < dp[j][0] + 1) 
                dp[i][1] = dp[j][0] + 1; 
        } 
  
        if (res < max(dp[i][0], dp[i][1])) 
            res = max(dp[i][0], dp[i][1]); 
    } 

    return res; 
} 


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    } 
	    cout<<zzis(arr, n)<<endl;
	}
	return 0;
}




