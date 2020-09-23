///// https://practice.geeksforgeeks.org/problems/maximum-profit/0

///max-profit

#include <bits/stdc++.h>
using namespace std; 
  
int maxProfit(int price[], int n, int k) { 
    
    int profit[k + 1][n + 1]; 
  
    // For day 0, you can't earn money irrespective of how many times you trade 
    for (int i = 0; i <= k; i++) 
        profit[i][0] = 0; 
    // profit is 0 if we don't do any transation (i.e. k =0) 
    for (int j = 0; j <= n; j++) 
        profit[0][j] = 0; 
  
    for (int i = 1; i <= k; i++) { 
        for (int j = 1; j < n; j++) { 
            int max_so_far = INT_MIN; 

            for (int m = 0; m < j; m++) 
                max_so_far = max(max_so_far, price[j] - price[m] + profit[i - 1][m]); 
  
            profit[i][j] = max(profit[i][j - 1], max_so_far); 
        } 
    }
    return profit[k][n - 1]; 
} 

int maxProfitFaster(int price[], int n, int k) 
{ 
    int profit[k + 1][n + 1]; 
    for (int i = 0; i <= k; i++) 
        profit[i][0] = 0; 
  	for (int j = 0; j <= n; j++) 
        profit[0][j] = 0; 
  
    for (int i = 1; i <= k; i++) { 
        int prevDiff = INT_MIN; 
        for (int j = 1; j < n; j++) { 
            prevDiff = max(prevDiff, profit[i - 1][j - 1] - price[j - 1]); 
            profit[i][j] = max(profit[i][j - 1], price[j] + prevDiff); 
        } 
    } 
  
    return profit[k][n - 1]; 
} 
  
int main(){
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>k>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cout<<maxProfit(arr, n, k)<<endl;
	}
	return 0;
}

