///// LIS not lcs

/// https://www.geeksforgeeks.org/minimize-elements-to-be-added-to-a-given-array-such-that-it-contains-another-given-array-as-its-subsequence-set-2/

/*
Consider elements of array B[] which are present in the array A[], 
and store the indices of each element of the array A[] in a Map
Then, find the LIS array subseq[] using Binary Search which consists of the indices in increasing order.
Finally, the minimum number of elements to be inserted into array B[] is equal to N – len(LIS), 
where len(LIS) is calculated using Binary Search in the above steps.
*/

#include <bits/stdc++.h>
using namespace std;
 
int minElements(int A[], int B[], int N, int M){

  map<int, int> map;
  // Iterate over the array
  for (int i = 0; i < N; i++){
    // Store the indices of
    // the array elements
    map[A[i]] = i;
  }
 
  // Stores the LIS
  vector<int> subseq;
 
  int l = 0, r = -1;
 
  for (int i = 0; i < M; i++) 
  {
    // Check if element B[i]
    // is in array A[]
    if (map.find(B[i]) != 
        map.end()) 
    {
      int e = map[B[i]];
 
      // Perform Binary Search
      while (l <= r) 
      {
        // Find the value of
        // mid m
        int m = l + (r - l) / 2;
 
        // Update l and r
        if (subseq[m] < e)
          l = m + 1;
        else
          r = m - 1;
      }
 
      // If found better element
      // 'e' for pos r + 1
      if (r + 1 < subseq.size()) 
      {
        subseq[r + 1] = e;
      }
 
      // Otherwise, extend the
      // current subsequence
      else
      {
        subseq.push_back(e);
      }
 
      l = 0;
      r = subseq.size() - 1;
    }
  }
 
  // Return the answer
  return N - subseq.size();
}
 
// Driver code 
int main()
{
  // Given arrays
  int A[] = {1, 2, 3, 4, 5};
  int B[] = {2, 5, 6, 4, 9, 12};
 
  int M = sizeof(A) / 
          sizeof(A[0]);
  int N = sizeof(B) /
          sizeof(B[0]);
 
  // Function Call
  cout << minElements(A, B, 
                      M, N);
 
  return 0;
}



















