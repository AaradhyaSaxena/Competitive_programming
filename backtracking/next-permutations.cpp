///// https://www.interviewbit.com/problems/permutations/

//// Next Permutations

void permutation(vector<int> &A, int st, vector<vector<int> > &v){
    if(st >= A.size()){
        v.push_back(A);
        return;
    }
    for(auto i=st; i<A.size(); i++){
        swap(A[st], A[i]);
        permutation(A, st+1, v);
        swap(A[st], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > v;
    permutation(A, 0, v);
    
    return v;
}

//