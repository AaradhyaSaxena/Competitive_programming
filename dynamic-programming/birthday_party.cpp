/// https://www.interviewbit.com/problems/tushars-birthday-party/

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int cst[10000];
    memset(cst,-1,sizeof cst);
   
    cst[0]=0;
    int l = B.size();
    for(int i = 0; i < l; i++){
        for(int j = 1; j <=1000; j++){
            if(j-B[i]>=0 && cst[j-B[i]] != -1){
                if(cst[j]==-1){
                    cst[j] = cst[j-B[i]] + C[i];
                }else
                cst[j]=min(cst[j],cst[j-B[i]] + C[i]);
            }
        }
    }
    int ans = 0;
    for(int a : A){
        ans += cst[a];
    }
    return ans;
}