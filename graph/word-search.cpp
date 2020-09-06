//////https://www.interviewbit.com/problems/word-search-board/

//// word-search

bool dfs(vector<string> &A, string B, int i, int j, int index){
    if( i<0 || i>=A.size() || j<0 || j>=A[0].size() || A[i][j]!=B[index] ) 
    	return false;

    if(index==B.size()-1) 
    	return true;

    bool check = (dfs(A,B,i+1,j,index+1) || dfs(A,B,i-1,j,index+1) || dfs(A,B,i,j+1,index+1) || dfs(A,B,i,j-1,index+1)) ;
    return check ;
}

int Solution::exist(vector<string> &A, string B) {

    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].size(); j++){
            if( dfs(A,B,i,j,0)) return 1; 
        }
    }
    return 0 ;
}

///////////////////////////////

// int row, col, flag;
// int dx[4] = {-1,1,0,0};
// int dy[4] = {0,0,-1,1};

// bool isValid(int x, int y){
//     if(x<0 || x>=row || y<0 || y>=col){
//         return false;
//     }
//     return true;
// }

// void dfs(int x, int y, vector<string> &A, string B, int pos){
//     if(!(A[x][y]==B[pos])){
//         flag = 0; return;
//     }
//     if(pos == (B.length()-1)){
//         flag = 1; 
//         return;
//     }
//     for(int k=0; k<4; k++){
//         int i = x + dx[k];
//         int j = y + dy[k];
//         if(isValid(i,j)){
//             dfs(i,j,A,B,pos+1);
//             if(flag) return;
//         }
//     }
// }


// int Solution::exist(vector<string> &A, string B) {
//     row = A.size(), col = A[0].size();
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             if(A[i][j] == B[0]){
//                 flag =0;
//                 dfs(i,j,A,B,0);
//                 if(flag){
//                     return 1;
//                 }
//             }
//         }
//     }
//     return 0;
// }