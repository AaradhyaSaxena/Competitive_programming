//////// https://practice.geeksforgeeks.org/problems/modify-array-to-maximize-sum-of-adjacent-differences/0
/// Assembly-line


#include <bits/stdc++.h>
using namespace std;

int maximumDifferenceSum(int arr[], int N){
    int dp[N][2];
    for (int i = 0; i < N; i++)
        dp[i][0] = dp[i][1] = 0;

    for (int i=0; i<(N-1); i++){

        dp[i + 1][0] = max(dp[i][0], dp[i][1] + abs(1-arr[i]));

        dp[i + 1][1] = max(dp[i][0] + abs(arr[i+1] - 1), dp[i][1] + abs(arr[i+1] - arr[i]));
    }
    return max(dp[N-1][0], dp[N-1][1]);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cout<<maximumDifferenceSum(arr, n)<<endl;
	}
	return 0;
}

