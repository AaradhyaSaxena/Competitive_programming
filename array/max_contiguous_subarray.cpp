https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    int n=A.size();
    if(n==1){
        return A[0];
    }
    int maxi = *max_element(A.begin(), A.end());
    // cout<<max<<
    if(maxi<0){
        return maxi;
    }
    int sum=0, max =0;
    for(int i=0; i<n; i++){
        sum += A[i];
        if(sum>max){
            max = sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max;
}
