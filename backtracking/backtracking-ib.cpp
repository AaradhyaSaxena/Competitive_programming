//////////// Backtracking

// Given a set of distinct integers, S, return all possible subsets.

vector<vector<int>> ans;
vector<int> vec;

void helper(vector<int> &A, int i){
    if(i>A.size()) return;
    ans.push_back(vec);
    
    for(int k=i; k<A.size(); k++){
        vec.push_back(A[k]);
        helper(A,k+1);
        vec.pop_back();
    }
    return;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    ans.clear();
    vec.clear();
    sort(A.begin(), A.end());
    helper(A,0);
    return ans;
}

////////////////////////////

///// https://www.interviewbit.com/problems/combinations/
// Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

vector<vector<int>> ans;
vector<int> vec;

void helper(int A, int B, int i){
    if(vec.size()==B){
        ans.push_back(vec);
    }
    if(i>A) return;
    for(int k=i; k<=A; k++){
        vec.push_back(k);
        helper(A,B,k+1);
        vec.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    ans.clear();
    vec.clear();
    
    helper(A,B,1);
    sort(ans.begin(),ans.end());
    return ans;
}
/// this solution more similar to regular dfs

void combinations(vector<vector<int>> &ans, vector<int> t, int i, int N, int K) {
    if (K == 0) {
        ans.push_back(t);
        return;
    }
    if (i > N) return;
    t.push_back(i);
    combinations(ans, t, i+1, N, K-1); // include the current element 
    t.pop_back();
    combinations(ans, t, i+1, N, K);// don't include the curr element
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> ans;
    combinations(ans, vector<int>(), 1, A, B);
    return ans;
}
/// structure more similar to recursive function

///////////////////////////

/// https://www.interviewbit.com/problems/combination-sum/

vector<vector<int>> ans;
vector<int> vec;

void helper(vector<int> &A, int B, int i){
    if(B==0){
        ans.push_back(vec);
        return;
    }
    if(B < 0 or i > A.size()) return;
    
    for(int k=i; k<A.size(); k++){
        vec.push_back(A[k]);
        helper(A,B-A[k],k);
        vec.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    ans.clear();
    vec.clear();
    
    sort(A.begin(), A.end());
    
    helper(A,B,0);
    sort(ans.begin(), ans.end());
    
    vector<vector<int>> unique_ans;
    for(int i=0; i<ans.size(); i++){
        if(i==0 or ans[i] != ans[i-1]){
            unique_ans.push_back(ans[i]);
        }
    }
    return unique_ans;
}

///////////////////////



















/*
Backtracking is trying out all possibilities using recursion, exactly like bruteforce.
Suppose you have to make a series of decisions, among various choices, where :

  * You don’t have enough information to know what to choose
  * Each decision leads to a new set of choices
  * Some sequence of choices (possibly more than one) may be a solution to your problem

*/