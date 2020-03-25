https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    if(slow==0) return -1;
    return slow;
}
/*
loop detection in linked list, where you use fast and slow pointers.
There are n+1 numbers between 1 and n. Therefore one number must be repeating 
hence creating a loop.
The traversal is 0, A[0], A[A[0]], A[A[A[0]]], A[A[A[A[0]]]] … .
*/
//////////////////////////////////////////////
//// Not working for multiple missing numbers

// int Solution::repeatedNumber(const vector<int> &A) {
    
//     int i,xor1=0,xor2=1;
//     for(i=0;i<A.size();i++)
//     {
//         xor1^=A[i];
//     }
//     int n=A.size();
//     for(i=2;i<=(n-1);i++)
//     {
//         xor2^=i;
//     }
    
//     int repeat;
//     repeat=xor1^xor2;
    
//     return repeat;
// }

