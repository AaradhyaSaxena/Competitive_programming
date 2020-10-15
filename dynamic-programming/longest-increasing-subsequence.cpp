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

//////////////////
///// nlog(n)

#include<bits/stdc++.h> 
using namespace std;  
  
int LongestIncreasingSubsequenceLength(std::vector<int>& v)  
{  
    vector<int> seq;
    seq.push_back(0);
 
    for (int i = 1; i < v.size(); i++) {  
        if(seq.back() < v[i]){
            seq.push_back(v[i]);
        }
        else{
            int idx = lower_bound(seq.begin(), seq.end(), v[i]) - seq.begin();
            seq[idx] = v[i];
        }
    }

    return seq.size();  
}  

int main()  
{  
    vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };  
    cout << "Length of Longest Increasing Subsequence is "
            << LongestIncreasingSubsequenceLength(v);  
    return 0;  
}  

/*
The lower_bound() method in C++ is used to return 
an iterator pointing to the first element in the range [first, last) 
which has a value not less than val. 

This means that the function returns the index of the next smallest number just greater than or equal to that number. 
If there are multiple values that are equal to val, lower_bound() returns the index of the first such value.
*/

/////////////////////////////////
////////////////////

///// aliter without lower bound

#include <iostream> 
#include <vector> 
  
// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
  
int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
  
        // new smallest value 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
  
        // v[i] extends largest subsequence 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
  
        // v[i] will become end candidate of an existing 
        // subsequence or Throw away larger elements in all 
        // LIS, to make room for upcoming grater elements 
        // than v[i] (and also, v[i] would have already 
        // appeared in one of LIS, identify the location 
        // and replace it) 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
} 
  
int main() 
{ 
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
    std::cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasingSubsequenceLength(v) << '\n'; 
    return 0; 
} 

/////////////////

//////////////
