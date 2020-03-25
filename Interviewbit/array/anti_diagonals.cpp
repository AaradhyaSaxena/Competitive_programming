https://www.interviewbit.com/problems/anti-diagonals/

// vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
//     int n = A.size();
//     int row = 2*(A.size()) -1;
//     int colom[row];
//     int j=1; int i;
//     for(i=0; i<row; i++){
//         colom[i] = j;
//         if(i+1<n){
//             j++;
//         }
//         else{
//             j--;
//         }
//     }
//     int col;
//     vector<vector<int>> B(row);
//     for(int i=0; i<row; i++){
//         col = colom[i];
//         B[i] = vector<int> (col);
//     }
    
//     int ri; int ci;
//     int r=0; int c=0; 
//     for(int i=0; i<row; i++){
        
//         ri = r; ci =c;
        
//         for(int k=0; k<colom[i]; k++){
            
//             B[i][k] = A[ri][ci];
            
//             if(ri+1<n && ci-1>=0) { 
//                 ri +=1; 
//                 ci -= 1;
//             }
//         }
//         c++;
//         if(c==n){ 
//             c=n-1; 
//             r++;
//         }
//     }
    
//     return B;
// }

///////// above solution also works ////////////////////////////////
////////////////////////////////////////////////////////////////////

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int N = 2*(n-1) + 1;//number of vectors in ans
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            ans[i+j].push_back(A[i][j]);//sum of index values in 2d array gives the index in ans
    }
    return ans;
}

