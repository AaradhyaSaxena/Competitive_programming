///// https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression/0

/// longest AP

#include<bits/stdc++.h>
using namespace std;

int n, a[10001];

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=0; i<n; i++)
            cin>>a[i];

        int global_ans=0, local_ans=0, n_term, common_diff;
        for (int i=0; i<n; i++){
            local_ans = 1;
            for (int j=i+1; j<n; j++){
                local_ans = 2;
                common_diff = a[j]-a[i];
                n_term = a[j];
                
                for (int k=j+1; k<n; k++){
                    if (n_term+common_diff == a[k]){
                        local_ans++;
                        n_term = a[k];
                    }
                }
                global_ans = max(global_ans, local_ans);
            }
            global_ans = max(global_ans, local_ans);
        }
        cout<<global_ans<<endl;
    }
}


//////////