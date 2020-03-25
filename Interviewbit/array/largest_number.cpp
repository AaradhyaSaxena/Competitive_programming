https://www.interviewbit.com/problems/largest-number/

// string Solution::largestNumber(const vector<int> &A) {
    
//     int len(int n);
//     int l; int l1; int temp;
//     for(int k = 0; k< n-1; k++) {
//         // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

//         for(int i = 0; i < n-k-1; i++) {
//             if( (A[i]/pow(10,l-1)) > (A[i+1]/pow(10,l1-1)) ){
//                 temp = A[i+1];
//                 A[ i ] = A[ i+1 ];
//                 A[ i + 1] = temp;
//             }
//             else if((A[i]/pow(10,l-1)) == (A[i+1]/pow(10,l1-1))){
//                 l--; 
//                 l1--;
                
                
//             }
//             //////////
//             // if(A[ i ] > A[ i+1] ) {
//             //     // here swapping of positions is being done.
//             //     temp = A[ i ];
//             //     A[ i ] = A[ i+1 ];
//             //     A[ i + 1] = temp;
//             // }
//         }
//     }
// }

// int len(int n){
//     int temp = n;
//     int len = 0;
//     while(temp>0){
//         temp = temp/10;
//         len++;
//     }
//     return len;
// }

////////////////////////////////////
////////////////////////////////////

int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);
    // then append X at the end of Y
    string YX = Y.append(X);
    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> b;
    for(int i=0;i<A.size();i++){
        b.push_back(to_string(A[i]));
    }
    sort(b.begin(),b.end(),myCompare);
    string ans="";
    for(int i=0;i<b.size();i++){
        ans+= b[i];
    }
    int i=0;
    while(ans[i]=='0'){
        i++;
    }
    if(i==ans.length())
        ans="0";
    return ans;
}
