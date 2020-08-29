/////////https://practice.geeksforgeeks.org/problems/max-absolute-difference/0

/////maximum absolute difference

#include <bits/stdc++.h> 
using namespace std; 
  
// Find maximum subarray sum for subarray [0..i] using standard Kadane's algorithm. 
int maxLeftSubArraySum(int a[], int size, int sum[]) { 
    int max_so_far = a[0]; 
    int curr_max = a[0]; 
    sum[0] = max_so_far; 
  
    for (int i = 1; i < size; i++) { 
        curr_max = max(a[i], curr_max + a[i]); 
        max_so_far = max(max_so_far, curr_max); 
        sum[i] = max_so_far; 
    } 
  
    return max_so_far; 
} 
  
// Find maximum subarray sum for subarray [i..n] using Kadane's algorithm.
int maxRightSubArraySum(int a[], int n, int sum[]){ 
    int max_so_far = a[n]; 
    int curr_max = a[n]; 
    sum[n] = max_so_far; 
  
    for (int i = n-1; i >= 0; i--) { 
        curr_max = max(a[i], curr_max + a[i]); 
        max_so_far = max(max_so_far, curr_max); 
        sum[i] = max_so_far; 
    } 
  
    return max_so_far; 
} 
  
int findMaxAbsDiff(int arr[], int n) 
{ 
    // create and build an array that stores maximum sums of subarrays that lie in arr[0...i] 
    int leftMax[n]; 
    maxLeftSubArraySum(arr, n, leftMax); 
  
    // create and build an array that stores maximum sums of subarrays that lie in arr[i+1...n-1] 
    int rightMax[n]; 
    maxRightSubArraySum(arr, n-1, rightMax); 
  
    // Invert array (change sign) to find minumum sum subarrays. 
    int invertArr[n]; 
    for (int i = 0; i < n; i++) 
        invertArr[i] = -arr[i]; 
  
    // create and build an array that stores minimum sums of subarrays that lie in arr[0...i] 
    int leftMin[n]; 
    maxLeftSubArraySum(invertArr, n, leftMin); 
    for (int i = 0; i < n; i++) 
        leftMin[i] = -leftMin[i]; 
  
    // create and build an array that stores minimum sums of subarrays that lie in arr[i+1...n-1] 
    int rightMin[n]; 
    maxRightSubArraySum(invertArr, n - 1, rightMin); 
    for (int i = 0; i < n; i++) 
        rightMin[i] = -rightMin[i]; 
  
    int result = INT_MIN; 
    for (int i = 0; i < n - 1; i++){

        int absValue = max(abs(leftMax[i] - rightMin[i + 1]), 
                        abs(leftMin[i] - rightMax[i + 1])); 
        if (absValue > result) 
            result = absValue; 
    } 
  
    return result; 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    cout<<findMaxAbsDiff(arr, n)<<endl;
	}
	return 0;
}



/////////////////

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    int max_so_far = INT_MIN;
	    int sum = 0;
	    for(int i=0; i<n; i++){ 
	        sum = max(sum+arr[i], arr[i]);
	        max_so_far = max(max_so_far, sum);
	        if(sum<0){
	            sum = 0;
	        }
	    }
	    int min_so_far = INT_MAX;
	    sum = 0;
	    for(int i=0; i<n; i++){ 
	        sum = min(sum+arr[i], arr[i]);
	        min_so_far = min(min_so_far, sum);
	        if(sum>0){
	            sum = 0;
	        }
	    }
	    cout<<(max_so_far - min_so_far)<<endl;
	}
	return 0;
}

/*
This won't work when all numbers are positive or negative.
*/