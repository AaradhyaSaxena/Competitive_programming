//// https://practice.geeksforgeeks.org/problems/construct-binary-palindrome-by-repeated-appending-and-trimming/0

///// Construct binary palindrome

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], int ans[]){
    ans[i] = 1; // mark the character as 1
    
    for(int j=0; j < adj[i].size(); j++){
        if(ans[adj[i][j]]==0){
            dfs(adj[i][j],adj,ans);
        }
    }
}

void helper(int n, int k){
    int ans[n] ={0};
    vector<int> adj[n];

    /// connect i to i%k
    for(int i=0; i<n; i++){
        adj[i].push_back(i%k);
        adj[i%k].push_back(i);
    }

    /// connect i to n-1-i
    for(int i=0; i<n/2; i++){
        adj[i].push_back(n-1-i);
        adj[n-1-i].push_back(i);
    }

    dfs (0,adj, ans); /// mark the first character as 1;
    
    for(int i=0; i<n; i++){
        cout<<ans[i];
    }cout<<endl;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        helper(n,k);
    }
	return 0;
}

/////