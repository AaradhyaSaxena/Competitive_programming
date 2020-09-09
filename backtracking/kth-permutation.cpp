////https://www.interviewbit.com/problems/kth-permutation-sequence/

/// kth-permutation

int fact(int a){
    if(a>12) return INT_MAX;
    if(a==0) return 1;
    
    return a*fact(a-1);
}

string helper(int k, vector<int> vec){
    int n = vec.size();
    if(n==0) return "";
    string str;
    int f = fact(n-1);
    int pos = k/f;
    str += to_string(vec[pos]);
    k %= f; 
    vec.erase(vec.begin() + pos);
    return str+helper(k,vec);
}

string Solution::getPermutation(int A, int B) {
    vector<int> vec;
    for(int i=1; i<=A; i++){
        vec.push_back(i);
    }
    return helper(B-1, vec);
}

///