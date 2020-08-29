//////// https://practice.geeksforgeeks.org/problems/convert-to-strictly-increasing-array/0

//// strictly increasing

#include <bits/stdc++.h> 
using namespace std; 
  
int minRemove(int arr[], int n) 
{ 
    int LIS[n], len = 0; 
  
    for (int i = 0; i < n; i++) 
        LIS[i] = 1; 
  
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < i; j++) { 
            if (arr[i] > arr[j] && (i-j)<=(arr[i]-arr[j])){ 
                LIS[i] = max(LIS[i], LIS[j] + 1); 
            } 
        } 
        len = max(len, LIS[i]); 
    } 

    return n - len; 
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
	    cout<<minRemove(arr, n)<<endl; 
	}
	return 0;
} 
