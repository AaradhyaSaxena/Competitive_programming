////// https://practice.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins/0

//// number of paths
#include<bits/stdc++.h> 
#define R 200
#define MAX_K 200 
using namespace std; 
  
int dp[R][R][MAX_K]; 
  
int pathCountDPRecDP(int mat[][R], int m, int n, int k) 
{ 
    // Base cases 
    if (m < 0 || n < 0) return 0; 
    if (m==0 && n==0) return (k == mat[m][n]); 
  
    // If this subproblem is already solved 
    if (dp[m][n][k] != -1) return dp[m][n][k]; 
  
    // (m, n) can be reached either through (m-1, n) or 
    // through (m, n-1) 
    dp[m][n][k] = pathCountDPRecDP(mat, m-1, n, k-mat[m][n]) + 
                  pathCountDPRecDP(mat, m, n-1, k-mat[m][n]); 
  
    return dp[m][n][k]; 
} 
  
// This function mainly initializes dp[][][] and calls 
// pathCountDPRecDP() 
int pathCountDP(int mat[][R], int k, int r) 
{ 
    memset(dp, -1, sizeof dp); 
    return pathCountDPRecDP(mat, r-1, r-1, k); 
} 

int main() {
    int t;
    cin>>t;
    while(t--){
        int k,r;
        cin>>k>>r;
        int arr[R][R];
        for(int i=0; i<r;i++){
            for(int j=0; j<r; j++){
                cin>>arr[i][j];
            }
        }
        cout<<pathCountDP(arr,k,r)<<endl;        
    }
    return 0;
}


//////////////////////
#include<bits/stdc++.h> 
using namespace std; 
  
struct node
{
    int x,y,val;
};
int main()
 {
    int t;
    cin >> t;
    while(t--)
    {
        int k,n,count=0;
        cin >> k >> n;
        int mat[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> mat[i][j];
        struct node temp;
        temp.x = 0;temp.y=0;temp.val = mat[0][0];
        queue<node>q;
        q.push(temp);
        while(!q.empty())
        {
            struct node t = q.front();
            if(t.val==k && t.x == n-1 && t.y == n-1)
            {
                //cout << t.x << " " << t.y << " " << t.val << "\n";
                count++;
            }
            q.pop();
            if(t.x+1 < n)
            {
                temp.x = t.x+1;
                temp.y = t.y;
                temp.val = t.val+mat[temp.x][temp.y];
                q.push(temp);
            }
            if(t.y+1 < n)
            {
                temp.x = t.x;
                temp.y = t.y+1;
                temp.val = t.val+mat[temp.x][temp.y];
                q.push(temp);
            }
        }
        cout << count << "\n";
    }
    return 0;
}
/////////////////////////////////////////

using namespace std;
int a[20][20];
int dp[20][20][20];
int count(int a[][20],int r,int c,int k,int n )
{
    if(r>n-1|c>n-1)
    return 0;
    if(r==n-1&&c==n-1)
     return (k==a[r][c]);
     if(dp[r][c][k]!=-1)
     return dp[r][c][k];
     
     dp[r][c][k]= count(a,r+1,c,k-a[r][c],n)+count(a,r,c+1,k-a[r][c],n);
     return dp[r][c][k];
     
}
int main()
 {
   int t;
   cin>>t;
   
   while(t--)
   {
       memset(dp,-1,sizeof dp);
       int k;
       cin>>k;
       int n;
       cin>>n;
       for(int i=0;i<n;i++)
       {  for(int j=0;j<n;j++)
           cin>>a[i][j];
       }
  cout<<count(a,0,0,k,n)<<endl;
      
   }
}

//////////////////