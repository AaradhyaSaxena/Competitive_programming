https://www.interviewbit.com/problems/maximum-unsorted-subarray/

// vector<int> Solution::subUnsort(vector<int> &A) {
    
//     int n = A.size();
//     int temp; 
//     vector <int> index;
//     index.reserve(n);
//     for(int k=0; k<n-1; k++){
//         for(int i=0; i<n-k-1; i++){
//             if(A[i]>A[i+1]){
//                 temp = A[i+1];
//                 A[i+1] = A[i];
//                 A[i] = temp;
//                 index.push_back(i);
//                 index.push_back(i+1);
//             }
//         }
//     }
//     if(index.empty()){
//         index.push_back(-1);
//         return index;
//         }
//     sort(index.begin(), index.end());
//     // for(int i=0; i<index.size(); i++){
//     //     cout<<index[i]<<" ";
//     // }
//     // cout<<endl;
//     return {index[0], index[index.size()-1]};
    
// }


vector<int> Solution::subUnsort(vector<int> &A){
    vector<int> ans;
    int n = A.size();
    int i = 0, j = n-1;
    while(i < n - 1 and A[i] <= A[i + 1]){
        i++;
    }
    while(j > 0 and A[j] >= A[j - 1]){
        j--;
    }
    if(i == n - 1){ // if array is already sorted, output -1
        ans.push_back(-1);
        return ans;
    }
    int mn = A[i + 1], mx = A[i + 1];
    for(int k = i; k <= j; k++){
        mx = max(mx, A[k]);
        mn = min(mn, A[k]);
    }
    int l = 0, r = n - 1;
    while(A[l] <= mn and l <= i){
           l++;
    }
    while(A[r] >= mx and r >= j){
        r--;
    }
    ans.push_back(l);
    ans.push_back(r);
    if(ans.size()>= 6){
        ans.push_back(10);
    }
    // 
    return ans;
}


