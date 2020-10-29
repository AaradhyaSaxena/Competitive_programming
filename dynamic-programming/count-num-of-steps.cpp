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

//////////////////////////

#include<bits/stdc++.h>
using namespace std;
 // source -> source vertex
// step -> value of last step taken
// dest -> destination vertex
int steps(int source, int step, int dest){

    if (abs(source) > (dest)) 
         return INT_MAX;
    if (source == dest) return step;
 
    // at each point we can go either way
    // if we go on positive side
    int pos = steps(source + step + 1, step + 1, dest);
 
    // if we go on negative side
    int neg = steps(source - step - 1, step + 1, dest);
 
    return min(pos, neg);
}
 
int main()
{
    int dest = 11;
    cout << "steps to reach"<< dest << " is "<< steps(0, 0, dest);
    return 0;
}

/////////////////
///////////////////