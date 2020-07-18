// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include<bits/stdc++.h> 
using namespace std;
int m[100][100];

long int MCM(int a[],int i,int j){  
    int k=0;

    if(i==j){
        m[i][j]=0;
    }

    if(m[i][j]!=-1) 
        return m[i][j];

    long int cost=INT_MAX;
    for(k=i;k<j;k++)
    {
        long int min_cost=MCM(a,i,k)+MCM(a,k+1,j)+a[i-1]*a[k]*a[j];
        if(min_cost<cost)
            cost=min_cost;
    }

    m[i][j]=cost;
    
    return cost;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        memset(m,-1,sizeof(m));
        cout<<MCM(a,1,n-1)<<endl;
    }
    return 0;
}


//////////////////

// int MatrixChainOrder(int p[], int i, int j){ 
//     if(i == j) return 0; 
//     int k; 
//     int min = INT_MAX; 
//     int count; 
  
//     for (k = i; k < j; k++){ 
//         count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
//         if (count < min) 
//             min = count; 
//     } 
//     return min; 
// } 
  
// int main() 
// { 
//     int t;
//     cin>>t;
//     while(t--){
//         int n; 
//         cin>>n;
//         int arr[n];
//         for(int i=0; i<n; i++){
//             cin>>arr[i];
//         }
//         cout<<MatrixChainOrder(arr, 1, n - 1)<<endl;
//     }
//     return 0; 
// } 
 