///// https://practice.geeksforgeeks.org/problems/count-digit-groupings-of-a-number/0
////???????????????????????????
/// Count digit groupings 

#include<bits/stdc++.h>
using namespace std;
  
// Function to find the subgroups 
int countGroups(int position, int previous_sum, int length, string num){
    
    if (position == length) 
        return 1; 

    int res = 0;
    int sum = 0;

    // Traverse all digits from current position to rest of the length of string 
    for (int i = position; i < length; i++){ 
        
        sum += (num[i] - '0'); 
        // If forward_sum is greater than the previous sum, then call the method again 
        if (sum >= previous_sum) 
            res += countGroups(i + 1, sum, length, num); 
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        string A; 
        cin >> A;
        cout << countGroups(0, 0, n, A); 
    }
    return 0;
}
//////////////////////////////
//////////////////////////////
//////////////////////////////

#include<bits/stdc++.h>
using namespace std;
  
const int MAX = 100; 
  
// maximum sum will be 9 * length. 
int dp[MAX][9*MAX + 1]; 
  
int countGroups(int position, int previous_sum, int length, string num){ 
    
    if (position == length) 
        return 1; 
  
    // If already evaluated for a given sub problem then return the value 
    if (dp[position][previous_sum] != -1) 
        return dp[position][previous_sum];

    // countGroups for current sub-group is 0 
    dp[position][previous_sum] = 0; 
  
    int res = 0;  
    int sum = 0;  
  
    // Traverse all digits from current position to rest of the length of string 
    for (int i = position; i < length; i++){ 
        sum += (num[i] - '0'); 
        // If forward_sum is greater than the previous sum, then call the method again 
        if (sum >= previous_sum)
            res += countGroups(i + 1, sum, length, num); 
    } 
    dp[position][previous_sum] = res; 

    return res; 
} 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        string A; 
        cin >> A;
        memset(dp,-1,sizeof(dp));
        cout << countGroups(0, 0, n, A)<<endl; 
    }
    return 0;
}







