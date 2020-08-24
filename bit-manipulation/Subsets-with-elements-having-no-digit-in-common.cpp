//////https://practice.geeksforgeeks.org/problems/mike-and-photographic-memory/0

/// Mike and photographic memory

#include<bits/stdc++.h>
using namespace std;

int toBits(int n) {
    int mask = 0;
    while (n > 0) {
        mask |= 1 << (n%10);
        n /= 10;
    }
    return mask;
}

int find(int n, int a[]) {
    vector<int> dp(1 << 10, 0);
    for (int i = 0; i < n; i++) {
        for (int j = dp.size()-1; j >=0; j--) {
            auto m = toBits(a[i]);
            if ((m&j) == m) {
                dp[j] = std::max(dp[j], dp[m^j] + a[i]);
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++)
	    	cin >> a[i];

	    cout << find(n,a) << '\n';
	}
	return 0;
}

////////////////////////


/*
Tags : Dp , bitmask 
Task : output the maximum subset sum obtained, such that no two elements in the subset may have any digit common. 
How to solve ? Any valid subset may contains any set of digits used. 

For example : {12 , 445 }  : it involves digits { 1 , 2 , 4 , 5 } { 23 , 11 } : digits used : { 1 , 2 , 3 } 
It means, total posibilities of digit used are (2^10 - 1) 

let dp[i] = maximum sum obtained using digits involved int set bit [ binary representation of i] 

Suppose i = 5 , then digits used are  {101} : { 0 , 2 } 

Now for each elements X , we can append this X in those states where  0 <= state < 2^10 , 
and  digits used in state and X are disjoint , means no common digit. 
Supose, state and X have no common digit. 

then dp[(convert(X) | state] = max( dp[convert(X) | state] , dp[state] + X ) 
We simply add X in those state where they have no common digit and 
then update the new state with maximum value 

Where convert(X) is an integer where 0 <= integer < 2^10 , 
and only those bits are active in binary representation of integer which are involved in X. 
For example convert(112) = 6  in binary representaion [ 1 1 0 ]. 

Time Complexity : N * 2^10 Space Complexity : N  
*/




