///////https://practice.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1

/////max-sum-remove-1-elem

int maxSumSubarray(int arr[], int n){

    int fw[n], bw[n]; 
  	int cur_max = arr[0], max_so_far = arr[0]; 
  
    // calculating maximum sum subarrays in forward direction 
    fw[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        cur_max = max(arr[i], cur_max + arr[i]); 
        fw[i] = cur_max; 

        max_so_far = max(max_so_far, cur_max); 
    } 
  
    // calculating maximum sum subarrays in backward direction 
    cur_max = max_so_far = bw[n-1] = arr[n-1]; 
    for (int i = n-2; i >= 0; i--) 
    { 
        cur_max = max(arr[i], cur_max + arr[i]); 
        bw[i] = cur_max;

        max_so_far = max(max_so_far, cur_max);
    } 
  
    int fans = max_so_far; 
  
    for (int i = 1; i < n - 1; i++) 
        fans = max(fans, fw[i - 1] + bw[i + 1]); 
  
    return fans; 
} 