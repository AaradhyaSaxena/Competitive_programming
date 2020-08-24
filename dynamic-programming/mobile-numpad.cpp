////////https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad/0

/// mobile keypad

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
    
        int keypad[4][3]={1,2,3,4,5,6,7,8,9,10,0,11};
        
        int I[5]={0,0,1,0,-1};
        int J[5]={0,-1,0,1,0};
            
        long long dp[10][n+1];
        
        for(int i=0;i<=9;i++){
            dp[i][1]=1;
            dp[i][0]=0;
        }
            
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(keypad[i][j]!=10 && keypad[i][j]!=11)
                    {
                        int num=keypad[i][j];
                        dp[num][len]=0;
                        for(int ij=0;ij<5;ij++)
                        {
                            int r=i+I[ij];
                            int c=j+J[ij];
                            if(r>=0 && r<4 && c>=0 && c<3 && keypad[r][c]!=10 && keypad[r][c]!=11)
                                dp[num][len]+=dp[keypad[r][c]][len-1];
                        }
                    }
                }
            }
        }
        long long res=0;
        for(int i=0;i<=9;i++)
        {
            res+=dp[i][n];
        }
        cout<<res<<endl;
    }
	return 0;
}

//// dfs
