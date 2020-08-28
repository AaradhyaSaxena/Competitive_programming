//////https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number/0
 
/// count num of steps

#include <bits/stdc++.h>
using namespace std;

int reachTarget(int target){
    // Handling negatives by symmetry
    target = abs(target);
    
    // Keep moving while sum is smaller or difference is odd.
    int sum = 0, step = 0;
    while (sum < target || (sum - target) % 2 != 0) {
        step++;
        sum += step;
    }
    return step;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout << reachTarget(n)<<endl;
	}
	return 0;
}