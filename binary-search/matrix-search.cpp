///// https://www.interviewbit.com/problems/matrix-search/

//// matrix search

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size(), m = A[0].size();
    
    int start = 0, end = n-1, ans =0;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(A[mid][0]<= B){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    // cout<<ans<<endl;
    if(A[ans][0]==B) return 1;
    
    start = 0, end = m-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(A[ans][mid]== B){
            return 1;
        }
        else if(A[ans][mid] > B){
            end = mid-1;
        }
        else{
            start = mid +1;
        }
    }
    return 0;
}

///