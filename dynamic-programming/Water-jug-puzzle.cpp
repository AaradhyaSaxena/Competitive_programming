///////https://www.geeksforgeeks.org/two-water-jug-puzzle/

//// water-jug puzzle

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){

    if (b==0) 
       return a; 
    return gcd(b, a%b); 
} 
  
/// fromCap -- Capacity of jug from which water is poured 
/// toCap   -- Capacity of jug to which water is poured 
/// d       -- Amount to be measured 
int pour(int fromCap, int toCap, int d){

    int from = fromCap; 
    int to = 0; 
  
    int step = 1; // Needed to fill "from" Jug 
  
    // Break the loop when either of the two jugs has d litre water 
    while (from != d && to != d){

        // Find the maximum amount that can be poured 
        int temp = min(from, toCap - to); 
  
        // Pour "temp" liters from "from" to "to" 
        to   += temp; 
        from -= temp; 
  
        // Increment count of steps 
        step++; 
  
        if (from == d || to == d) 
            break; 
  
        // If first jug becomes empty, fill it 
        if (from == 0){ 
            from = fromCap; 
            step++; 
        } 
  
        // If second jug becomes full, empty it 
        if (to == toCap){ 
            to = 0; 
            step++; 
        } 
    } 
    return step; 
} 
  
// Returns count of minimum steps needed to measure d liter 
int minSteps(int m, int n, int d){

    // To make sure that m is smaller than n 
    if (m > n) 
        swap(m, n); 
  
    // For d > n we cant measure the water using the jugs 
    if (d > n) 
        return -1; 
  
    // If gcd of n and m does not divide d then solution is not possible 
    if ((d % gcd(n,m)) != 0) 
        return -1; 
  
    return min(pour(n,m,d),   // n to m 
               pour(m,n,d));  // m to n 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n,d;
	    cin>>m>>n>>d;
	    cout<<minSteps(m, n, d)<<endl;
	}
	return 0;
}



