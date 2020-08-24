/////////https://practice.geeksforgeeks.org/problems/champagne-overflow/0

//// Water-overflow

#include <bits/stdc++.h>
using namespace std;

float findWater(int i, int j, float X){
 
    // There will be i*(i+1)/2 glasses till ith row (including ith row) 
    float glass[i * (i + 1) / 2]; 
  
    // Initialize all glasses as empty 
    memset(glass, 0, sizeof(glass)); 
  
    // Put all water in first glass 
    int index = 0; 
    glass[index] = X; 
  
    // Now let the water flow to the downward glasses  
    // till the row number is less than or/ equal to i (given row)  
    // correction : X can be zero for side glasses as they have lower rate to fill 
    for (int row = 1; row <= i ; ++row) 
    { 
        // Fill glasses in a given row. Number of columns in a row is equal to row number 
        for (int col = 1; col <= row; ++col, ++index) 
        { 
            // Get the water from current glass 
            X = glass[index]; 
  
            // Keep the amount less than or equal to capacity in current glass 
            glass[index] = (X >= 1.0f) ? 1.0f : X; 
  
            // Get the remaining amount 
            X = (X >= 1.0f) ? (X - 1) : 0.0f; 
  
            // Distribute the remaining amount to the down two glasses 
            glass[index + row] += X / 2; 
            glass[index + row + 1] += X / 2; 
        } 
    } 
    // The index of jth glass in ith row will be i*(i-1)/2 + j - 1 
    return glass[i*(i-1)/2 + j - 1]; 
} 


int main() {
	int t;
	cin>>t;
	while(t--){
	    int i,j;
	    float k;
	    cin>>k>>i>>j;
	    cout<<findWater(i,j,k)<<endl;
	}
	return 0;
}