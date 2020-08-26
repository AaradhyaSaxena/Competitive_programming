//// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0/
//// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int sum, int n){ 
    // The value of subset[i][j] will be true if 
    // there is a subset of set[0..j-1] with sum equal to i 
    bool subset[n + 1][sum + 1]; 
  
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < arr[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= arr[i - 1]) 
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]]; 
        } 
    }
    return subset[n][sum]; 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, sum=0, target, temp =0; 
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        sum += arr[i];
	    }
	    if(sum%2!=0){
	        cout<<"NO"<<endl;
	    }else{
	        target = sum/2;
	        int flag = 0;
	        flag = isSubsetSum(arr,target,n); 
	        if(flag==0){
	            cout<<"NO"<<endl;
	        }else{
	            cout<<"YES"<<endl;
	        }
	    }
	    
	}
	return 0;
}

//////////////////////

bool isSubsetSum(int arr[], int sum, int n){ 
    if (sum == 0) return true; 
    if (n == 0 && sum != 0) return false; 
  
    // If last element is greater than sum, then ignore it 
    if (set[n - 1] > sum) return isSubsetSum(arr, n - 1, sum); 
  
    /* check if sum can be obtained by:
      (a) including the last element 
      (b) excluding the last element   */
    return isSubsetSum(arr, n - 1, sum) 
           || isSubsetSum(arr, n - 1, sum - arr[n - 1]); 
} 