https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int i;
    int n = A.size();
    cout<<n<<endl;
    if(n==1){
        return 0;
    }
    else{
        int td = 0;
        for(i=0; i<n-1; i++){
            int dist =0;
            int x = A[i+1] - A[i];
            int y = B[i+1] - B[i];
        
            if(x<0){
                x = x*(-1);
            }
            if(y<0){
                y = y*(-1);
            }
            if(x<=y){
                dist = y;
            }
            else{
                dist = x;
            }
            td += dist;
        }
        return td;
    }
    // int td = 0;
    // for(i=0; i<n-1; i++){
    //     int dist =0;
    //     int x = A[i+1] - A[i];
    //     int y = B[i+1] - B[i];
        
    //     if(x<0){
    //         x = x*(-1);
    //     }
    //     if(y<0){
    //         y = y*(-1);
    //     }
    //     if(x<=y){
    //         dist = y;
    //     }
    //     else{
    //         dist = x;
    //     }
    //     td += dist;
    // }
    // return td;
}
