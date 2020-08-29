////https://practice.geeksforgeeks.org/problems/minimum-number-of-elements-which-are-not-part-of-increasing-or-decreasing-subsequence/0

//// longest increasing and decreasing subsequence

#include<bits/stdc++.h> 
#define MAX 102 
using namespace std; 
  
// Return minimum number of elements which is not part of any of the sequence. 
int countMin(int arr[], int dp[MAX][MAX][MAX], int n, int dec, int inc, int i) 
{ 
    if (dp[dec][inc][i] != -1) 
        return dp[dec][inc][i]; 
  
    if (i == n) 
        return 0; 
  
    // calculating by considering element as part of decreasing sequence. 
    if (arr[i] < arr[dec]) 
        dp[dec][inc][i] = countMin(arr, dp, n, i, inc, i + 1); 
  
    // calculating by considering element as part of increasing sequence. 
    if (arr[i] > arr[inc]) { 
        // If cannot be calculated for decreasing sequence. 
        if (dp[dec][inc][i] == -1) 
            dp[dec][inc][i] = countMin(arr, dp, n, dec, i, i + 1); 
  
        // After considering once by decreasing sequence, now try for increasing sequence. 
        else
            dp[dec][inc][i] = min(countMin(arr, dp, n, dec, i, i + 1), dp[dec][inc][i]); 
    } 
  
    // If element cannot be part of any of the sequence. 
    if (dp[dec][inc][i] == -1) 
        dp[dec][inc][i] = 1 + countMin(arr, dp, n, dec, inc, i + 1); 
  
    // After considering element as part of increasing and decreasing sequence trying as not part of any of the sequence. 
    else
        dp[dec][inc][i] = min(1 + countMin(arr, dp, n, dec, inc, i + 1), dp[dec][inc][i]); 
  
    return dp[dec][inc][i]; 
} 
  
// Wrapper Function 
int wrapper(int arr[], int n) { 
    // Adding two number at the end of array, so that increasing and decreasing sequence can be made. 
    // MAX - 2 index is assigned INT_MAX for decreasing sequence because/ next number of sequence must be less than it. 
    // Similarly, for Increasing sequence INT_MIN is assigned to MAX - 1 index. 
    arr[MAX - 2] = INT_MAX; 
    arr[MAX - 1] = INT_MIN; 
  
    int dp[MAX][MAX][MAX]; 
    memset(dp, -1, sizeof dp); 
  
    return countMin(arr, dp, n, MAX - 2, MAX - 1, 0); 
} 
  
// Driven Program 
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
	    cout << wrapper(arr, n) << endl;
	}
	return 0;
}



/*
The idea is to make a decision on each index, starting from index 0, one by one. 
For each index there can be three possibilities, first, it can belong to increasing sequence, 
second, it can belong to decreasing sequence, third, it does not belong to any of these sequences.
So, for each index, check for the optimal answer (minimum element which is not part of any of the subsequences)
by considering it once as a part of increasing subsequence or as a part of decreasing subsequence. 
If the optimal answer cannot be achieved by them then leave it as the element which is not part of any of the sequence.

To decrease the complexity (using Dynamic Programming), 
we can store the number of elements which are not part of any of the subsequences using 3D array dp[x][y][z], 
where x indicates the decision index, y indicates the last index of decreasing sequence, 
z indicates the last index of increasing sequence.

*/










