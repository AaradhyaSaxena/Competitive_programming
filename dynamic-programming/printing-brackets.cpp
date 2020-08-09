//// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication/0

#include <bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &name){ 
    // If only one matrix left in current segment 
    if (i == j){ 
        cout << name++; return; 
    } 

    cout << "(";  
    // Note that "*((bracket+i*n)+j)" is similar to bracket[i][j] 
    // Put brackets from i to bracket[i][j].
    printParenthesis(i, *((bracket+i*n)+j), n, bracket, name); 
  
    // Put brackets from bracket[i][j] + 1 to j. 
    printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name); 
    cout << ")"; 
} 

void matrixChainOrder(int p[], int n) { 
    int m[n][n]; 
    int bracket[n][n]; 
  
    // cost is zero when multiplying one matrix. 
    for (int i=1; i<n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (int L=2; L<n; L++) 
    { 
        for (int i=1; i<n-L+1; i++) 
        { 
            int j = i+L-1; 
            m[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++) 
            { 
                // q = cost 
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) 
                { 
                    m[i][j] = q; 
                    bracket[i][j] = k; 
                } 
            } 
        } 
    } 
    // char name = 'A'; 
    // printParenthesis(1, n-1, n, (int *)bracket, name);
} 

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
        matrixChainOrder(arr,n);
        cout<<endl;
    }
    return 0;
}