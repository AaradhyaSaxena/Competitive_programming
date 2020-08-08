//// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0

#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];

int helper(int arr[], int i, int j, int s){
    if(i>j) return 0;
    if(dp[i][j][s]) return dp[i][j][s];
    if(s==0){
        dp[i][j][s] = max(arr[i] + helper(arr, i+1, j, 1), 
                            arr[j] + helper(arr, i, j-1, 1));
    }else{
        dp[i][j][s] = min(helper(arr, i+1, j, 0), helper(arr, i, j-1, 0));
    }
    return dp[i][j][s];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        int arr[n];
        int sum1 = 0, sum2 = 0, sum = 0;
        int i,j;
        for(i=0; i<n; i++){
            cin>>arr[i];
        }
        memset(dp,0,sizeof(dp));
        cout<<helper(arr,0,n-1,0)<<endl;
    }
    return 0;
}