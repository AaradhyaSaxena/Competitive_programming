///// https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

/// form a palindrome

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string w=s;
		reverse(w.begin(),w.end());
		int n=s.size();
		int a[n+1][n+1];
		int count =0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				a[i][j]=0;
			}
		}

		// this loops for checking longest palindrome sequence in string ...
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i-1]==w[j-1])
					a[i][j] = 1 + a[i-1][j-1];
				else a[i][j] = max(a[i-1][j],a[i][j-1]);
			}
		}
		cout<<n-a[n][n]<<endl; 
	}
	return 0;
}

///////////////////////////

// #include <bits/stdc++.h>
// using namespace std;

// int helper(string s){
//     int n = s.length(), maxx=INT_MIN, len = 1;
//     int dp[n+1][n+1];
//     memset(dp,0,sizeof(dp));
//     for(int i=n-1; i>=0; i--){
//         for(int j=n; j>0, j>i-1; j--){
//             if(s[i]==s[j-1]){
//                 dp[i][j] = dp[i+1][j-1] + 1;
//                 maxx = max(maxx,dp[i][j]);
//                 if(maxx == dp[i][j] and maxx>1){
//                     if((i+j)%2 !=0){
//                         len = 2*maxx -1;
//                     }else{
//                         len = 2*(maxx-1);
//                     }
//                 }
//             }
//         }
//     }
//     // for(int i=0; i<n; i++){
//     //     for(int j=1; j<=n; j++){
//     //         cout<<dp[i][j]<<" ";
//     //     }cout<<endl;
//     // }
//     return len;
// }

// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
//         int n = s.length();
//         int ans = helper(s);
//         // cout<<ans<<endl;
//         cout<<n-ans<<endl;
//     }
// 	return 0;
// }