/////

/// Sudoku

bool notInRow(vector<vector<char> > A,int row,char ch){
    for(int i=0;i<9;++i){
        if(A[row][i]==ch) return false;
    }
    return true;
}

bool notInCol(vector<vector<char> > A,int col,char ch){
    for(int i=0;i<9;++i){
        if(A[i][col]==ch) return false;
    }
    return true;
}

bool notInBox(vector<vector<char>> A, int row, int col, char ch){
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(ch == A[i+row][j+col]) return false;
        }
    }
    return true;
}

bool isvalid(vector<vector<char> > A, int row, int col, char ch){
    return (A[row][col]=='.' && notInRow(A,row,ch) 
            && notInCol(A,col,ch) && (notInBox(A,row-row%3,col-col%3,ch)));
}

bool findNextPosition(vector<vector<char> > A,int & row,int & col,int r,int c){
    for(col=c;col<9;++col)if(A[row][col]=='.')
        return true;
    for(row=r+1;row<9;++row)
    {
        for(col=0;col<9;++col)
        {
            if(A[row][col]=='.')
                return true;
        }
    }
    return false;
}

bool solve(vector<vector<char> > & A,int r,int c){
    int row=r,col=c;
    bool next=findNextPosition(A,row,col,r,c);
    if(!next)return true;
    for(int i=1;i<=9;++i)
    {
        if(isvalid(A,row,col,char(i+48)))
        {
            A[row][col]=char(i+48);
            bool done = solve(A,row,col);
            if(done)return true;
            A[row][col]='.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    solve(A,0,0);
}

////////