https://www.interviewbit.com/problems/wave-array/

vector<int> Solution::wave(vector<int> &A) {
    
    int s = A.size() - A.size()%2;
    // cout<<s<<endl;
    
    sort(A.begin(), A.end());
    
    int B[s/2];
    int j=0;
    for(int i=0; i< s/2; i++){
        B[i] = A[j];
        j = j+2;
        // cout<<"a\n";
    }
    
    int C[s/2];
    int k=1;
    for(int i=0; i<(s/2); i++){
        C[i] = A[k];
        k= k+2;
        // cout<<"a\n";
    }
    
    int p=0;
    for(int i=0; i< s/2; i++){
        A[p] = C[i];
        p++;
        A[p] = B[i];
        p++;
        // cout<<"a\n";
    }
    // for(int i=0; i<A.size(); i++){
    //     cout<<A[i]<<" ";
    // }
    // cout<<endl;
    return A;
}
