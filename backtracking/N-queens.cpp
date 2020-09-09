////////https://www.interviewbit.com/problems/nqueens/

/// N queens

bool isValid(vector<string> &temp,int x, int y){
    if(x<0 or x>temp.size() or y<0 or y>temp.size()){
        return false;
    }
    for(int i=0; i<temp.size(); i++){
        if(temp[i][y]=='Q')
            return false;
    }
    for(int i=0; i<temp.size(); i++){
        if(temp[x][i]=='Q')
            return false;
    }
    for(int i=x, j=y; i>0 and j>0; i--, j--){
        if(temp[i][j]=='Q')
            return false;
    }
    for(int i=x, j=y; i<temp.size() and j>0; i++, j--){
        if(temp[i][j]=='Q')
            return false;
    }
    return true;
}

void helper(vector<vector<string>> &ans, vector<string> &temp, int y){
    if(y>=temp.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int k=0; k<temp.size(); k++){
        if(isValid(temp,k,y)){
            temp[k][y] = 'Q';
            helper(ans,temp,y+1);
            temp[k][y] = '.';
        }
    }
}


vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> ans;
    vector<string> temp;
    
    string str = "";
    for(int i=0; i<A; i++){
        str += '.';
    }
    for(int i=0; i<A; i++){
        temp.push_back(str);
    }
    
    helper(ans,temp,0);
    return ans;
}

/////

