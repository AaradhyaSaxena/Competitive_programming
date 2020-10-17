///// sapient jumpstart

//// p1

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((A[i][0]+A[j][0])*(A[i][1]+A[j][1])==B){
                ans++;
            }
        }
    }
    return ans;
}

///////////

bool comp(vector<int>A, vector<int>B){
    return(A[0]*A[1]<B[0]*B[1]);
}

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int ans=0;
    // if(B==0 or n==0) return 0;
    sort(A.begin(), A.end());
    for(int i=0; i<n; i++){
        if(4*A[i][0]*A[i][1]>B) break;
        for(int j=i+1; j<n; j++){
            if((A[i][0]+A[j][0])*(A[i][1]+A[j][1])==B){
                ans++;
            }
            if((1+A[j][0])*(1+A[j][1]>B)) break;
            if((A[i][0]+A[j][0])*(A[i][1]+A[j][1])>B){
                break;
            }
        }
    }
    return ans;
}

//// p2

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()  {
    double x,y;
    cin>>x>>y;
    if(x==0 or y==0) return 0;
    double ans;
    ans = ((2*acos(0.0))*(x/2.0)*(x/2.0)*(1/2.0))/(x*y);
    cout.precision(8);
    cout<<1-ans<<endl;
    return 0;
}

////// p3

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size(), m = B.size();
    // cout<<n<<" "<<m<<" "<<C<<endl;
    if(m==0) return 0;
    if(n==0) return (m*C);
    long long int dp[2][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i%2!=0){
                if(A[i-1]==B[j-1]){
                    dp[i%2][j] = 1+dp[i%2-1][j-1];
                }
                else{
                    dp[i%2][j] = max(dp[i%2-1][j],dp[i%2][j-1]);
                }
            }
            else{
                if(A[i-1]==B[j-1]){
                    dp[i%2][j] = 1+dp[i%2+1][j-1];
                }
                else{
                    dp[i%2][j] = max(dp[i%2+1][j],dp[i%2][j-1]);
                }
            }
        }
    }
    int lcs = dp[n%2][m];
    return (m-lcs)*C;
}

///////