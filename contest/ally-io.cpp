//////https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
    for (int l = 0; l < col; ++l) {
        vector<int> sums(row, 0);
        for (int r = l; r < col; ++r) {
            for (int i = 0; i < row; ++i) {
                sums[i] += matrix[i][r];
            }
            
            // Find the max subarray no more than K 
            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            res = std::max(res, curMax);
        }
    }
    return res;
}

////////////////////////
////////////////////
/////https://www.geeksforgeeks.org/count-pairs-in-a-sorted-array-whose-product-is-less-than-k/

#include <bits/stdc++.h> 
using namespace std; 
  
// Function to count the pairs 
int fun(int A[], int n, int k) 
{ 
    // count to keep count of 
    // number of pairs with product 
    // less than k 
    int count = 0; 
    int i = 0; 
    int j = n - 1; 
  
    // Traverse the array 
    while (i < j) { 
  
        // If product is less than k 
        // then count that pair 
        // and increment 'i' 
        if (A[i] * A[j] < k) { 
            count += (j - i); 
            i++; 
        } 
  
        // Else decrement 'j' 
        else { 
            j--; 
        } 
    } 
  
    // Return count of pairs 
    return count; 
} 
  
// Driver code 
int main() 
{ 
  
    int A[] = { 2, 3, 4, 6, 9 }; 
    int n = sizeof(A) / sizeof(int); 
    int k = 20; 
    cout << "Number of pairs with product less than "
         << k << " = " << fun(A, n, k) << endl; 
  
    return 0; 
} 

/////////////////////









