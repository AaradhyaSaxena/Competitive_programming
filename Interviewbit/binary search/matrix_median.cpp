https://www.interviewbit.com/problems/matrix-median/

int Solution::findMedian(vector<vector<int> > &A) {
    
    int s = INT_MAX;
    int e = INT_MIN;
    //find min and max element in matrix
    
    for(int i = 0 ; i<A.size(); i++){
        s = min(s,A[i][0]);
        e = max(e,A[i][A[0].size()-1]);
    }
    
    int k = (A.size()*A[0].size() + 1)/2;
    //find the element pwho is >= k elements
    
    while(s<e){
        int m = s + (e-s)/2;
        int count = 0;
        for(int i=0;i<A.size();i++){
            count += upper_bound(A[i].begin(),A[i].end(),m)-A[i].begin();
        }
        if(count<k){
            s = m+1;
        }else if(count>k){
            e = m;
        }
    }
    return s;
}
