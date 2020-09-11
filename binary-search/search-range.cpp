/////https://www.interviewbit.com/problems/search-for-a-range/

/// Search a range

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    vector<int> vec(2, -1);
    int start = 0, end = n-1, ansA = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(A[mid] >= B){
            ansA = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    if(A[ansA]!=B){
        return vec;
    }else{
        vec[0] = ansA;
    }

    int ansB = -1;
    start = 0, end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(A[mid] <= B){
            ansB = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    vec[1] = ansB;
    return vec;
}


/////