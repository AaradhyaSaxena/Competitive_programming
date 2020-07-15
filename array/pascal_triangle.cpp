https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    
    if(A==0){
        vector<vector<int> > P;
        return P;
    }
    
    int row = A;
    int colom[row];
    for(int i=1; i<=A; i++){
        colom[i-1] = i;
    }
    
    vector<vector<int> > P(row);  
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
    
    return P;
}
