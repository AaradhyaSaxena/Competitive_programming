/// https://practice.geeksforgeeks.org/problems/distinct-transformations/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    
	    int n = b.length(), m = a.length();
	    int dp[n+1][m+1];
	    int i=0,j=0;

	    memset(dp,0,sizeof(dp));
	    for(j=0; j<=m; j++){
	        dp[0][j] = 1;
	    }

	    for(i=1; i<=n; i++){
	        for(j=1; j<=m; j++){
	            if(b[i-1]!=a[j-1]){
	                dp[i][j] = dp[i][j-1];
	            }else{
	                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
	            }
	        }
	    }

	    cout<<dp[n][m]<<endl;
	}
	return 0;
}

/*Here we construct a matrix matrixDP, 
where each cell matrixDP[i][j] represents the number of solutions of placing substring B[0..i] with A[0..j];

Case 1). matrixDP[0][j] = 1, since placing B = “” with any substring of A
 would have only 1 solution which is to delete all characters in A.

Case 2). when i > 0, matrixDP[i][j] can be derived by two cases:

    case 2[a]). if B[i] != A[j], then the solution would be to ignore the character A[j]
     and align substring B[0..i] with A[0..(j-1)]. Therefore, matrixDP[i][j] = matrixDP[i][j-1].

    case 2[b]). if B[i] == A[j], then first we could have the solution in case a), 
    but also we could match the characters B[i] and A[j] and 
    place the rest of them (i.e. B[0..(i-1)] and A[0..(j-1)]. 
    As a result, matrixDP[i][j] = matrixDP[i][j-1] + matrixDP[i-1][j-1]

*/


// int find(int posa,int posb,string &a,string &b){
//     int ans = 0;
//     if(posb >=b.size()) return 1;
//     if(posa >=a.size()) return 0;
//     if(a[posa] == b[posb]) ans += find(posa+1,posb+1,a,b);
//     ans += find(posa+1,posb,a,b);
//     return ans;
// }

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    string a,b;
// 	    cin>>a>>b;
// 	    int ans = find(0,0,a,b);
// 	    cout<<ans<<endl;
// 	}
// 	return 0;
// }