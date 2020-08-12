//// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0

#include <climits> 
#include <iostream> 
using namespace std; 
  
// function to calculate sum between two indices 
// in array 
int sum(int arr[], int from, int to) 
{ 
    int total = 0; 
    for (int i = from; i <= to; i++) 
        total += arr[i]; 
    return total; 
} 
  
// bottom up tabular dp 
int findMax(int arr[], int n, int k) 
{ 
    // initialize table 
    int dp[k + 1][n + 1] = { 0 }; 
  
    // base cases 
    // k=1 
    for (int i = 1; i <= n; i++) 
        dp[1][i] = sum(arr, 0, i - 1); 
  
    // n=1 
    for (int i = 1; i <= k; i++) 
        dp[i][1] = arr[0]; 
  
    // 2 to k partitions 
    for (int i = 2; i <= k; i++) { // 2 to n boards 
        for (int j = 2; j <= n; j++) { 
  
            // track minimum 
            int best = INT_MAX; 
  
            // i-1 th separator before position arr[p=1..j] 
            for (int p = 1; p <= j; p++)  
                best = min(best, max(dp[i - 1][p], 
                              sum(arr, p, j - 1)));        
  
            dp[i][j] = best; 
        } 
    } 
  
    // required 
    return dp[k][n]; 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
	    int k,n,x,i,j,sum=0, mid = 0;
	    cin>>k>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cout << findMax(arr, n, k) << endl;
	}
	return 0;
}

/////////////////////

#include <iostream>
#include <vector>
using namespace std;

vector<int> vec(51);

bool isPossible(int t, int n, int k){
	int maxx = 0, temp =0, i=0, j=0;
	for(i=0; i<n; i++){
	    if(j==k) break;
		if(temp+vec[i]<=t){
			temp += vec[i];
		}else{
			j++;
			temp = 0;
			if(temp+vec[i]<=t) temp += vec[i]; 
		}
	}
	if(i!=n) return false;
	return true;	
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int k,n,x,i,j,sum=0, mid = 0;
	    cin>>k>>n;
	    vec.clear();
	    for(int i=0; i<n; i++){
	        cin>>x;
	        vec.push_back(x);
	        sum += x;
	    }
	    int ans = sum;
	    i=0; j=sum;
	    while(i<j){
	    	mid = (i+j)/2;
	   // 	cout<<mid<<endl;cou
	    	if(isPossible(mid,n,k)){
	    	  //  cout<<mid<<endl;
	    		ans = min(ans,mid);
	    		j = mid-1;
	    	}else{
	    		i = mid+1;
	    	}
	    }
	cout<<ans<<endl;
	}
	return 0;
}

/////////////////////////////////

int partition(int arr[], int n, int k) 
{ 
    // base cases     
    if (k == 1) // one partition 
        return sum(arr, 0, n - 1);     
    if (n == 1)  // one board 
        return arr[0]; 
  
    int best = INT_MAX; 
  
    // find minimum of all possible maximum 
    // k-1 partitions to the left of arr[i], 
    // with i elements, put k-1 th divider  
    // between arr[i-1] & arr[i] to get k-th  
    // partition 
    for (int i = 1; i <= n; i++) 
        best = min(best, max(partition(arr, i, k - 1),  
                                sum(arr, i, n - 1))); 
  
    return best; 
} 
 