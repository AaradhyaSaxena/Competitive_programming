////////////////////////////
/// Interview_bit //////////
////////////////////////////


// // int Solution::coverPoints(vector<int> &A, vector<int> &B) {
// //     int i;
// //     int n = A.size();
    
// //     int td = 0;
// //     for(i=0; i<n; i++){
// //         int dist =0;
// //         int x = A[i+1] - A[i];
// //         int y = B[i+1] - B[i];
        
// //         if(x<0){
// //             x = x*(-1);
// //         }
// //         if(y<0){
// //             y = y*(-1);
// //         }
// //         if(x<=y){
// //             dist = y;
// //         }
// //         else{
// //             dist = x;
// //         }
// //         td += dist;
// //     }
// //     return td;
// // }

// vector<int> Solution::plusOne(vector<int> &A) {
    
//     s = A.size();
    
//     if(A[s-1] != 9){
//         A[s-1] = A[s-1]+1;
//     }
//     else{
//         for(int i=s-1; i>=0; i--){
//             A[i] += 1; 
//             if(A[i]==10){
//                 A[i] = 0;
//                 carry = 1;
//             }
//             if(carry==0){
//                 return A;
//             }
//         }
//     }
//     return A
// }
// int func(int A[s]){
// 	if(A[s-1] != 9){
// 		A[s-1] = A[s-1]+1;
// 		return A;
// 	}
// 	else{
// 		for(int i=1; i<=s; i++){
// 			A[s-i] = 0;
// 			A[s-i-1] += 1;
// 		}
// 	}
// }

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
///////////// TLE ///////////////////////////////////

// int Solution::maxSubArray(const vector<int> &A) {
//     int sum =0;
//     int i=0;
//     int largest = *max_element(A.begin(),A.end());
    
//     // int new_max;
//     vector<int> B;

//     for(i=0; i<A.size(); i++){
//         B.push_back(A[i]);}

//     i=0;
//     int old, max_now, z, greater;
//     max_now = largest;

//     while(i+1 < B.size()){
        
//         if(B[i]>0){
//             old = B[i];
//             B[i] += B[i+1];
//             B.erase(B.begin()+i+1);
//             (old>B[i]) ? (greater=old) : (greater=B[i]);
//             (greater>max_now) ? (max_now=greater);
//         }
//         else{
//             i++;
//         }
//     }
//     // new_max = *max_element(B.begin(),B.end());
//     (max_now>largest) ? (z = max_now) : (z = largest);

//     return z;
// }
//////////////////////////////////////////////////
//////////optimal_solution////////////////////////
//////////////////////////////////////////////////

// int Solution::maxSubArray(const vector<int> &v) {
//             int result = INT_MIN;
//         int current = 0;

//         for (int i : v) {
//             current += i;

//             result = max(result, current);

//             if (current < 0) {
//                 current = 0;
//             }
//         }

//         return result;
// }
////////////////////////////////////
////////////////////////////////////
////////////////////////////////////

intervals

















