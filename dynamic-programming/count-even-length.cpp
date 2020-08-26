/////https://practice.geeksforgeeks.org/problems/count-even-length/0

///// Count Even Length

#include<bits/stdc++.h> 
using namespace std; 
  
int countSeq(int n, int diff){ 
    // We can't cover difference of more than n with 2n bits 
    if (abs(diff) > n) 
        return 0; 
  
    // n == 1, i.e., 2 bit long sequences 
    if (n == 1 && diff == 0) 
        return 2; 
    if (n == 1 && abs(diff) == 1) 
        return 1; 
  
    int res = // First bit is 0 & last bit is 1 
              countSeq(n-1, diff+1) + 
  
              // First and last bits are same 
              2*countSeq(n-1, diff) + 
  
              // First bit is 1 & last bit is 0 
              countSeq(n-1, diff-1); 
  
    return res; 
} 
  
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<countSeq(n, 0)<<endl; 
    }
    return 0; 
} 

////////////////

/*
The idea is to fix first and last bits and then recur for n-1, i.e., remaining 2(n-1) bits. 
There are following possibilities when we fix first and last bits.
1) First and last bits are same, remaining n-1 bits on both sides should also have the same sum.
2) First bit is 1 and last bit is 0, sum of remaining n-1 bits on left side should be 1 less than the sum n-1 bits on right side.
2) First bit is 0 and last bit is 1, sum of remaining n-1 bits on left side should be 1 more than the sum n-1 bits on right side.

Based on above facts, we get below recurrence formula.
*/

////////////////

#define MAX 1000 
int lookup[MAX][MAX]; 
  
int countSeqUtil(int n, int dif) 
{ 
    if (abs(dif) > n) 
        return 0; 
    if (n == 1 && dif == 0) 
        return 2; 
    if (n == 1 && abs(dif) == 1) 
        return 1; 
  
    if (lookup[n][n+dif] != -1) 
        return lookup[n][n+dif]; 
  
    int res = countSeqUtil(n-1, dif+1) + 
              2*countSeqUtil(n-1, dif) + 
              countSeqUtil(n-1, dif-1); 
  
    return lookup[n][n+dif] = res; 
} 
  
int countSeq(int n) { 
    memset(lookup, -1, sizeof(lookup)); 
    return countSeqUtil(n, 0); 
} 

////// bEst Solution

int countSeq(int n) 
{ 
    int nCr=1, res = 1; 
  
    // Calculate SUM ((nCr)^2) 
    for (int r = 1; r<=n ; r++) 
    { 
        // Compute nCr using nC(r-1) 
        // nCr/nC(r-1) = (n+1-r)/r; 
        nCr = (nCr * (n+1-r))/r;    
  
        res += nCr*nCr; 
    } 
  
    return res; 
}

//////








