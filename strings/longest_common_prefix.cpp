// //// https://www.interviewbit.com/problems/longest-common-prefix/

// string Solution::longestCommonPrefix(vector<string> &A) {
//     auto num = A.size();
//     int minimum = INT_MAX;
//     cout<<num<<endl;
    
//     for(int i=0; i<num; i++){
//         auto s = A[i].length();
//         if (minimum > s)
//             minimum = s;
//     }
//     cout<<minimum<<endl;
//     int cnt =0;
//     int j=0;
//     while(j<=minimum)
//     {
//     for(auto i=0; i<num-1; i++)
//     {
//         // cout<<"lol"<<endl;
//         if(A[i][j]!=A[i+1][j]){
//             cout<<"lol"<<endl;
//             goto end;
            
//         }
//     }
//     cnt++;
//     j++;
//     }
//     end: string ans;
//     // cout<<"lol"<<endl;
//     for(int i=0; i<cnt; i++){
//         ans.append(A[i]);
//     }
//     return ans;
// }

string Solution::longestCommonPrefix(vector<string> &A) {
    string result = "";
    auto n = A.size();
    int j = INT_MAX;  ///// smallest length of string in vector A
    for (auto i = 0; i<n; ++i){
        auto s = A[i].length();
        if (j > s)
            j = s;
    }
    for (auto i = 0; i<j; ++i){
        auto temp = A[0][i];
        int k = 1;
        while (k<n){
            if (temp==A[k][i])
                ++k;
            else
                return result;
        }
        result += temp; 
    }
    return result;
}
