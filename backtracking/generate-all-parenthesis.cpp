/////////https://www.interviewbit.com/problems/generate-all-parentheses-ii/

//// Generate all parenthesis

vector<string> ans;

void helper(int A, int open, int close, string str){
    if(close==A){
        ans.push_back(str);
        return;
    }
    else{
        if(A>open){
            str += "(";
            helper(A,open+1,close,str);
            str.pop_back();
        }
        if(open>close){
            str += ")";
            helper(A,open,close+1,str);
            str.pop_back();
        }
    }
}

vector<string> Solution::generateParenthesis(int A) {
    ans.clear();
    string str = "";
    helper(A, 0, 0, str);
    
    return ans;
}

///////