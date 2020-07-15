https://www.interviewbit.com/problems/maximum-absolute-difference/

// int Solution::maxArr(vector<int> &A) {
//     int out;
//     int max = 0;
//     int f_ij(int i, int j, vector<int> &A);
//     for(int i=0; i<A.size();i++){
//         for(int j=i; j<A.size();j++){
//             out = f_ij(i,j,A);
//             // cout<<out<<endl;
//             if(out>max){max = out;}
//         }
//     }
//     return max;
// }

// int f_ij(int i, int j, vector<int> &A){
    
//     return abs(A[i] - A[j]) + abs(i-j);
// }
/////////////////////////////////////////////////////////////

int Solution::maxArr(vector<int> &A) {
    int max1=INT_MIN,min1=INT_MAX,max2=INT_MIN,min2=INT_MAX;
    for(int i=0;i<A.size();i++){
        max1=max(max1,A[i]+i);
        min1=min(min1,A[i]+i);
        max2=max(max2,A[i]-i);
        min2=min(min2,A[i]-i);
    }
    int ans=INT_MIN;
    for(int i=0;i<A.size();i++){
        ans=max(ans,abs(max1-(A[i]+i)));
        ans=max(ans,abs(min1-(A[i]+i)));
        ans=max(ans,abs(max2-(A[i]-i)));
        ans=max(ans,abs(min2-(A[i]-i)));
    }
    return ans;
}