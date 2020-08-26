///https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

///Egg-dropping

#include <bits/stdc++.h>
using namespace std;
  
int eggDrop(int n, int k) { 
    /// minimum number of trials needed for n eggs and k floors
    int eggFloor[n + 1][k + 1]; 
    int res; 
    int i, j, x;

    // We need one trial for one floor and 0 trials for 0 floors 
    for (i = 1; i <= n; i++) { 
        eggFloor[i][1] = 1; 
        eggFloor[i][0] = 0; 
    } 
    // We always need j trials for one egg and j floors. 
    for (j = 1; j <= k; j++) 
        eggFloor[1][j] = j; 
  
    // Fill rest of the entries in table using optimal substructure property 
    for (i = 2; i <= n; i++) 
    { 
        for (j = 2; j <= k; j++) 
        { 
            eggFloor[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) 
            { 
                res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]); 
                
                if (res < eggFloor[i][j]) 
                    eggFloor[i][j] = res; 
            } 
        } 
    } 
  
    // eggFloor[n][k] holds the result 
    return eggFloor[n][k]; 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    cout<<eggDrop(n, k)<<endl;
	}
}


/////////////
// recursive

int eggDrop(int n, int k) { 
    if (k == 1 || k == 0) 
        return k; 
    if (n == 1) 
        return k; 
    int min = INT_MAX, x, res; 

    for (x = 1; x <= k; x++) { 
        res = max( eggDrop(n - 1, x - 1), eggDrop(n, k - x)); 
        if (res < min) 
            min = res; 
    }
    return min + 1; 
} 

