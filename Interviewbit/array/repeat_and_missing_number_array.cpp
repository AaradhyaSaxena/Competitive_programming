https://www.interviewbit.com/problems/repeat-and-missing-number-array/

//First approach: using xor
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int xo=0;
    for(int i=0;i<n;i++){
        xo=xo^A[i];
        xo=xo^(i+1);
    }
    int setbit=xo&(~(xo-1));
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(A[i]&setbit)
            x=x^A[i];
        else
            y=y^A[i];
        if((i+1)&setbit)
            x=x^(i+1);
        else y=y^(i+1);
    }
    vector<int> res(2);
    for(int i=0;i<n;i++){
        if(A[i]==x){
            res[0]=x;
            res[1]=y;
            break;
        }
        else if(A[i]==y){
            res[0]=y;
            res[1]=x;
            break;
        }
    }
    return res;
}

//Second approach: using sum of squares


vector<int> Solution::repeatedNumber(const vector<int> &A){
    long long int n = A.size();
    long long int sum_exp = n*(n+1)/2;
    long long int sum_sq_exp = sum_exp*(2*n + 1)/3;
    long long int sum=0; 
    long long int sum_sq=0;
    
    // for(long long int i=0; i<n; i++){
    //     sum += A[i];
    //     sum_sq += (A[i]*A[i]);
    // }
    // long long int p,q,c,d;
    // p = sum - sum_exp;
    // q = sum_sq - sum_sq_exp;
    
    for(int i=0;i<A.size(); i++){
      sum -= (long long int)A[i];
      sum_sq -= (long long int)A[i]*(long long int)A[i];
    }    
    
    c = (p+(q/p))/2;
    d = c - p;
    // return {c,d};
    
    vector <int> ans;
    ans.push_back(c);
    ans.push_back(d);
    return ans;
}

//////////////////////////////////////////////////////////////////////
//////////////////// Using factorials ~ overflow /////////////////////

// vector<int> Solution::repeatedNumber(const vector<int> &A) {
//     long long int len = A.size();
//     long long int sumOfN = (len * (len+1) ) /2, sumOfNsq = (len * (len +1) *(2*len +1) )/6;
//     long long int missingNumber1=0, missingNumber2=0;
    
//     for(int i=0;i<A.size(); i++){
//       sumOfN -= (long long int)A[i];
//       sumOfNsq -= (long long int)A[i]*(long long int)A[i];
//     }
    
//     missingNumber1 = (sumOfN + sumOfNsq/sumOfN)/2;
//     missingNumber2= missingNumber1 - sumOfN;
//     vector <int> ans;
//     ans.push_back(missingNumber2);
//     ans.push_back(missingNumber1);
//     return ans;
// }