//// https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &A) {
    int n = A.size(), maxx = 0;
    if(n==0) return 0;
    if(n==1) return 1;
    int dp[n] = {0};
    dp[n-1] = 1;
    for(int i = n-2; i>=0; i--){
        maxx = 0;
        for(int j=i+1; j<n; j++){
            if(A[i]<A[j] and dp[j]>=maxx){
                maxx = dp[j];
            }
        }
        dp[i] = maxx + 1;
    }
    int ans =0;
    for(int i=0; i<n; i++){
        if(dp[i]>ans)
            ans = dp[i];
    }
    return ans;
}