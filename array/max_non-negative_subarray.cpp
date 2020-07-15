https://www.interviewbit.com/problems/max-non-negative-subarray/

// vector<int> Solution::maxset(vector<int> &A) {
//     int maxtillnow=0; int max=0;
//     int left=0; int right=0; int L=0; int R=0;
//     vector<int> B;
    
//     for(int i=0; i<A.size(); i++){
//         if(A[i]>=0){
//             maxtillnow = maxtillnow + A[i];
//             if(maxtillnow<0){
//                 maxtillnow =0;
//                 left = i;
//             }
//             else if(maxtillnow>max){
//                 max = maxtillnow;
//                 L = left;
//                 right = i;
//                 R = right;
//             }
//         }
//         else{
//             left = i+1;
//             right = i;
//             maxtillnow = 0;
//         }
//     }
//     // cout<<L<<R<<endl;
//     for(int i=L;i<=R;i++){
//         if(A[i]>=0){
//             B.push_back(A[i]); 
//         }
//     }
//     return B;
    
// }
vector<int> Solution::maxset(vector<int> &A) {
    int i=0,l=0,r=0,L=0,R=0;
    long long int s=0,max=-1;
    while(i<A.size())
    {
        if(A[i]>=0)
        {
            s+=A[i];
            r++;
        }
        else
        {
                l=i+1;
                r=i+1;
                s=0;
        }
        if(s>=max)
        {
            if((R-L<r-l) || max<s)
            {
                R=r;
                L=l;
            }
            max=s;
        }
        i++;
    }
    vector<int> ans;
    for(i=L;i<R;i++)
    {
        ans.push_back(A[i]);
    }
    return ans;
}

