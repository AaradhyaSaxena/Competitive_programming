https://www.interviewbit.com/problems/square-root-of-integer/

// int Solution::sqrt(int A) {
//     int i=1, j=A, mid; 
//     int ans = 0;
    
//     while(i<=j){
//         mid = (i+j)/2;
//         if(mid*mid <=A && (mid+1)*(mid+1) > A){
//             return mid;
//         }
//         else if(mid*mid<A){
//             i = mid+1;
//         }
//         else{
//             j = mid-1;
//         }
//     }
//     return ans;
// }

int Solution::sqrt(int A){
    long long int i=1, j=A, mid; 
    long long int ans = 0;
    
    while(i<=j){
        mid = (i+j)/2;
        if(mid*mid <=A){
            ans = mid;
            i = mid+1;
            // return mid;
        }
        else{
            j = mid-1;
        }
    }
    return ans;    
}