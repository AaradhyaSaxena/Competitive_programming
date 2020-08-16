//////   https://atcoder.jp/contests/abc175
//// AtCoder Beginner Contest 175

/// p1

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	if(s=="RRR"){
		cout<<3<<endl;
	} 
	else if(s=="SRR" or s=="RRS"){
		cout<<2<<endl;
	} 
	else if(s=="RSS" or s=="SRS" or s=="SSR" or s=="RSR"){
		cout<<1<<endl;
	} 
	else{
		cout<<0<<endl;
	} 
	return 0;
}
*/

////// p2          / /////////////   and A[j]!=A[k] and A[i]!= A[k]

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n, x;
// 	cin>>n;
// 	vector<int> A;
// 	for(int i=0; i<n; i++){
// 		cin>>x;
// 		A.push_back(x);
// 	}
// 	sort(A.begin(),A.end());
// 	int cnt =0;
// 	for(int i=0; i<n; i++){
// 		for(int j=i+1; j<n; j++){
// 			if(A[i] == A[j]){
// 				continue;
// 			}
// 			for(int k=j+1; k<n; k++){
// 				if(A[j] == A[k]){
// 					continue;
// 				}
// 				if(A[i] + A[j] > A[k]){
// 					cnt++;
// 				}
// 			}
// 		}
// 	}
// 	cout<<cnt<<endl;
// }


/// p3

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

// 	long long int x,k,d,ans,temp;
// 	cin>>x>>k>>d;

// 	if(x > k*d){
// 		ans =  x - k*d;
// 	}


// }

//// p4

// #include<bits/stdc++.h>
// using namespace std;

// int N = 50001;
// long long int move[N], points[N];

// long long int helper(int dp[N][], int i, int k){
// 	if(dp[i][k] != INT_MIN){
// 		return dp[i][k];
// 	}else{
// 		dp[i][k] = helper()
// 	}
// }

// int main(){
// 	long long int n,k;
// 	cin>>n>>k;

// 	for(int i=0; i<n; i++){
// 		cin>>move[i];
// 	}
// 	for(int i=0; i<n; i++){
// 		cin>>points[i];
// 	}
// 	int dp[n][k+1];
// 	memset(dp,INT_MIN,sizeof(dp));

// 	long long int tempk=0, tempc=INT_MIN, cost=INT_MIN;
// 	for(int i=0; i<n; i++){
// 		tempc = helper(i,k);
// 		cost = max(cost,tempc);
// 	}
// 	cout<<cost<<endl;
// }


