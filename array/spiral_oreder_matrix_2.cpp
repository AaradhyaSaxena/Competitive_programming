https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    
    int dir = 1; int i;int j=1;
    vector<vector<int> >M(A,vector<int>(A));
    int rmin = 0; int cmin=0;
    int rmax = A-1; int cmax= A-1;
    
    while(j<=A*A && rmin<=rmax && cmin<=cmax){
        // LOOP:
        if(dir==1 && j<=A*A){
            for( i=cmin; i<=cmax; i++){
                M[rmin][i] = j;
                j++;
                if(i == (cmax)){
                    // cmax = cmax-1;
                    rmin = rmin +1;
                }
            }
            dir = 2;
        }
        else if(dir==2 && j<=A*A){
            for( i=rmin; i<=rmax; i++){
                M[i][cmax] = j;
                j++;
                if(i == rmax){
                    // rmax = rmax -1;
                    cmax = cmax -1;
                }
            }
            dir = 3;
        }
        else if(dir==3 && j<=A*A){
            for(i=cmax; i>=cmin; i--){
                M[rmax][i] = j;
                j++;
                if(i==cmin){
                    rmax = rmax -1;
                }
            }
            dir =4;
        }
        else if(dir==4 && j<=A*A){
            for(i=rmax; i>=rmin; i--){
                M[i][cmin] = j;
                j++;
                if( i==rmin){
                    cmin = cmin+1;
                }
            }
            dir =1;
        }
        // goto LOOP;
    }
    return M;
}
