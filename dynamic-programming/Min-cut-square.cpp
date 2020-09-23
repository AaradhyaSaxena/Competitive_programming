//////https://practice.geeksforgeeks.org/problems/min-cut-square/0

/// MIN cut square

#include <bits/stdc++.h>
using namespace std;

const int MAX = 300; 
int dp[MAX][MAX]; 
  
int minimumSquare(int m, int n) 
{ 
    int vertical_min = INT_MAX; 
    int horizontal_min = INT_MAX; 
      
    if (m == n) 
        return 1; 
      
    if (dp[m][n]) 
            return dp[m][n]; 
      
    // The rectangle is cut horizontally and vertically into two parts and the cut with minimum value is found.
    for (int i = 1; i<= m/2; i++){ 
        horizontal_min = min(minimumSquare(i, n) + minimumSquare(m-i, n), horizontal_min);  
    } 
      
    for (int j = 1; j<= n/2; j++){ 
        vertical_min = min(minimumSquare(m, j) + minimumSquare(m, n-j), vertical_min); 
    } 
    dp[m][n] = min(vertical_min, horizontal_min);  
          
    return dp[m][n]; 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    cout<<minimumSquare(a,b)<<endl;
	}
	return 0;
}