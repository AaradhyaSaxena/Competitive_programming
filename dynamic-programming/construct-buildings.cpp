//////https://www.geeksforgeeks.org/count-possible-ways-to-construct-buildings/

/// construct buildings

#include<iostream> 
using namespace std; 
  
int countWays(int N) 
{ 
    // Base case 
    if (N == 1) 
        return 4;  // 2 for one side and 4 for two sides 
  
    // countB is count of ways with a building at the end 
    // countS is count of ways with a space at the end 
    // prev_countB and prev_countS are previous values of 
    // countB and countS respectively. 
  
    // Initialize countB and countS for one side 
    int countB=1, countS=1, prev_countB, prev_countS; 
  
    for (int i=2; i<=N; i++){

        prev_countB = countB; 
        prev_countS = countS; 
  
        countS = prev_countB + prev_countS; 
        countB = prev_countS; 
    } 
  
    int result = countS + countB; 
  
    return (result*result); 
} 
  
// Driver program 
int main() 
{ 
    int N = 3; 
    cout << "Count of ways for " << N 
         << " sections is " << countWays(N); 
    return 0; 
} 

/*
// A space can be added after a building or after a space.
countS(N) = countB(N-1) + countS(N-1)

// A building can only be added after a space.
countB[N] = countS(N-1)

// Result for one side is sum of the above two counts.
result1(N) = countS(N) + countB(N)

// Result for two sides is square of result1(N)
result2(N) = result1(N) * result1(N) 

*/










