//////// KMP more

///// https://csacademy.com/contest/archive/task/prefix-matches/statement/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5;

int n;
int A[MAX_N];

int main() {
    cin >> n;
    assert(2 <= n && n <= MAX_N);
    
    queue<int> q;
    for (int i = 2; i <= n; ++i) {
        cin >> A[i];
        if (A[i]) {
            if (!q.size() || A[q.back()] + q.back() < A[i] + i) {
                q.push(i);
            }
        }
        if (q.size() && A[q.front()] + q.front() <= i) {
            q.pop();
        }
        if (q.size()) {
            cout << i - q.front() + 1 << " ";
        } else {
            cout << "0 ";
        }
    }    
}

////////////////////////////
/// my soln -incorrect approach

// #include <iostream>
// using namespace std;

// int main() {
//     int n; cin >> n;
//     int b[n];
//     for(int i=0; i<n-1; i++){
//         cin>>b[i];
//     }
//     char arr[n+1];
//     arr[0] = 'a';
    
//     int j=0, i=1;
//     while(i<n){
//         if(b[i-1]==0){
//             j++;
//             arr[i] = char(j+97);
//             i++;
//         }
//         if(b[i-1]>0){
//             int temp = b[i-1];
//             int loop = 0;
//             while(temp-- and loop<n){
//                 arr[i] = (char(arr[loop]));
//                 loop++;
//                 i++;
//             }
//         }
        
//     }
//     for(int i=0; i<=n; i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
    
//     return 0;
// }

///////////////
///////////////////////
//////////////////////




