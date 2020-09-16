/////// https://practice.geeksforgeeks.org/problems/castle-run/0

///// Castle run

#include <iostream>
using namespace std;

/// check for Eular circuit
int main() {
	int t; cin>>t;
	while(t--){
	    int n, flag =1;
	    cin>>n;
	    int arr[n][n];
	    for(int i=0; i<n; i++){
	        int cnt = 0;
	        for(int j=0; j<n; j++){
	            cin>>arr[i][j];
	            if(arr[i][j]==1) cnt++;
	        }
	        if(cnt%2==1 or cnt==0){
	            flag = 0;
	        }
	    }
	    if(flag==1 or n==1){
	        cout<<"True"<<endl;
	    }else{
	        cout<<"False"<<endl;
	    }
	}
	return 0;
}

//////////

