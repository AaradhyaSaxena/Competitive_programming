// https://www.geeksforgeeks.org/edit-distance-dp-5/

#include <bits/stdc++.h> 
using namespace std; 
  
int min(int x, int y, int z){ 
    return min(min(x, y), z); 
} 

int dp[100][100];
  
int editDist(string str1, string str2, int m, int n) 
{ 
    if(m == 0){
        dp[m][n] = n;
        return n;
    }

    if(n == 0){
        dp[m][n] = m;
        return m;
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    // If last characters are equal, ignore them.
    if (str1[m - 1] == str2[n - 1]){
        return editDist(str1, str2, m - 1, n - 1); 
    }

    int dist = 1 + min(editDist(str1, str2, m, n - 1), // Insert 
                   editDist(str1, str2, m - 1, n), // Remove 
                   editDist(str1, str2, m - 1, n - 1) // Replace 
                   );
    dp[m][n] = dist;
    return dist;
} 

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string a, b;
        cin>>a>>b;
        memset(dp,-1,sizeof(dp));
        cout<<editDist(a, b, n, m)<<endl;;
    }
    return 0;
}