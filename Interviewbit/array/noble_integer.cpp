https://www.interviewbit.com/problems/noble-integer/

int Solution::solve(vector<int> &A) {
    
    sort(A.begin(), A.end());
    
    for(int i=0; i<A.size(); i++){
        if(A[i] == (A.size() -1 -i)){

            if( (i+1<A.size()) && (A[i] != A[i+1])){
                return 1;
            }
            else if(A[A.size() -1]==0){
                return 1;
            }
            // cout<<A[i]<<endl;
        }
    }
    // for(int i=0; i<A.size(); i++){
    //     cout<<A[i]<<" ";
    // }
    // cout<<endl;
    return -1;
}