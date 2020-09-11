/////// https://www.interviewbit.com/problems/search-in-bitonic-array/

/// Bitonic array

int helper(vector<int>& arr, int si, int ei){
    int mid = (si+ei)/2;
    
    if(arr[mid-1]<arr[mid] && arr[mid] > arr[mid+1]){
        return mid;
    }
    if(arr[mid-1]<arr[mid] && arr[mid] < arr[mid+1]){
        return helper(arr, mid+1, ei);
    }

    return helper(arr, si, mid-1);
}

int Solution::solve(vector<int> &A, int B) {
    int pos = helper(A, 0, A.size()-1);
    
    int index = lower_bound(A.begin(), A.begin()+pos, B) - A.begin();
    if(A[index]==B) return index;
    
    index = lower_bound(A.begin()+pos, A.end(), B, greater<int>()) - A.begin();
    if(A[index]==B) return index;
    
    return -1;
}

////