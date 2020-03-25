https://www.interviewbit.com/problems/flip/

// vector<int> Solution::flip(string A) {
//     int L=0;
//     int R=0;
//     int count=0;
//     int indexl=0;
//     int size = A.size();

//     for(int i = 0; i<size; i++){
//         if(A[i]=='0')
//             A[i] = 1;
//         else
//             A[i] = -1;
//     }

//     int max_so_far = 0, max_ending_here = 0; 
//     for (int i = 0; i < size; i++) {
//         max_ending_here = max_ending_here + A[i]; 
//         if (max_ending_here < 0){
//             max_ending_here = 0;
//             indexl = i+1;
            
//         }
//         else if (max_so_far < max_ending_here){
//             max_so_far = max_ending_here;
//             L = indexl+1;
//             R = i+1;
//         }
//     }
    
//     if(L==0 && R==0){
//         return {};
//     }
//     return {L,R}; 
// }

vector<int> Solution::flip(string A) {
    int n = A.size();
    int flag = 1;
    for(int i=0; i<n; i++){
        if (A[i] == '0'){
            flag = 0;
            A[i] = 1;
        }
        else{
            A[i] = -1;
        }
    }
    if (flag){
        return {};
    }
    int prev=0, l=0, r=0, sum=0, max=0;
    for (int i=0; i<n; i++){
        sum += A[i];
        if (sum > max){
            max = sum;
            r = i;
            l = prev;
        }
        if (sum<0){
            prev = i+1;
            sum = 0;
        }
    }
    return {l+1, r+1};
}
