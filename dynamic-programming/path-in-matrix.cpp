//// https://practice.geeksforgeeks.org/problems/path-in-matrix/0

#include<bits/stdc++.h>
using namespace std;

int maxx(int a, int b, int c){
    return max(max(a,b),c);
}

int main() {
	int t, n;
	cin>>t;
	while(t--){
	cin>>n;
	int arr[n+2][n+2];
	memset(arr,0,sizeof(arr));
	for(int i=1; i<n+1; i++){
	    for(int j=1; j<n+1; j++){
	        cin>>arr[i][j];
	    }
	}
	for(int i=n; i>0; i--){
	    for(int j=n; j>0; j--){
	        arr[i][j] += maxx(arr[i+1][j-1],arr[i+1][j],arr[i+1][j+1]);
	    }
	}
	
	int ans = 0;
	for(int j=1; j<n+1; j++){
	    if(ans<arr[1][j]){
	        ans = arr[1][j];
	    }
	}
	cout<<ans<<endl;
	}
	return 0;
}