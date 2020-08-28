/////// https://practice.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/0

////Count of n digit numbers whose sum of digits equals to given sum

#include<bits/stdc++.h> 
using namespace std; 
  
unsigned long long int lookup[101][501]; 

#define mod 1000000007
 
// Recursive function to count 'n' digit numbers with sum of digits as 'sum'. 
// This function considers leading 0's also as digits, that is why not directly called  
unsigned long long int countRec(int n, int sum) { 
    
    if (n == 0) return sum == 0; 
  
    if (lookup[n][sum] != -1) return lookup[n][sum]; 
  
    unsigned long long int ans = 0; 
  
    for (int i=0; i<10; i++){
    	if (sum-i >= 0) 
        	ans = (ans + countRec(n-1, sum-i)%mod)%mod; 
    } 

    return lookup[n][sum] = ans%mod; 
} 
 
// This is mainly a wrapper over countRec. 
// It explicitly handles leading digit and calls countRec() for remaining n. 
unsigned long long int finalCount(int n, int sum) 
{ 
    memset(lookup, -1, sizeof lookup); 
  	unsigned long long int ans = 0; 
  
    // Traverse through every digit from 1 to 9 and count numbers beginning with it 
    for (int i = 1; i <= 9; i++){
    	if (sum-i >= 0) 
        	ans += countRec(n-1, sum-i)%mod; 
    } 
    	
    return ans%mod; 
} 
  
int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		int n, sum;
		cin>>n>>sum; 
    	cout << finalCount(n, sum)<<endl; 
	}
    return 0; 
} 

//////////////
////////////////