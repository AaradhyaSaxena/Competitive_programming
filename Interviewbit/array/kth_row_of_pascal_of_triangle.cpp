https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int A) {
    
    if(A==0){
        vector<int> P(A+1);
        return P;
    }
    
    int row = A;
    int colom[row];
    for(int i=1; i<=A; i++){
        colom[i-1] = i;
    }
    
    vector<vector<int> > P(row+1);  
    for (int i=0; i<row; i++) { 
        int col;  
        col = colom[i];
        P[i] = vector<int>(col); 
    }
    
    if(A==1){
        P[0][0] = 1;
    }
    else{
        P[0][0] = 1;
        P[1][0] = 1; P[1][1] = 1;
        for(int i=2; i<A; i++){
            for(int j=0; j<i; j++){
                P[i][j] = P[i-1][j] + P[i-1][j-1];
            }
            P[i][i] =1;
        }
    }
    
    return P[A];

}

//////////////////////////////////////////////

// vector<int> Solution::getRow(int k) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//     vector<int> v(k+1);
//     if(k==0){
//         v[0]=1;
//         return v;
//     }
//     int c=1;
//     v[0]=c;
//     for(int j=1;j<=k;j++){
//         v[j]=c*(k-j+1)/j;
//         c=v[j];
//     }
//     return v;
// }