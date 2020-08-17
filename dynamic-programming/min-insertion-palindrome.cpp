///// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

/// palindrome

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	int n;
    	scanf("%d",&n);
    	string a;
    	cin>>a;
    	int dp[n+1][n+1];
    	memset(dp,0,sizeof(dp));
    	int cnt=0;
    	for(int i=n-1;i>=1;i--)
    	{
    	    for(int j=i+1;j<=n;j++)
    	    {
    	        if(a[i-1]==a[j-1])
    	        {
    	            if(j-i==1 || j-i==2)
    	                dp[i][j]=1;
    	            else
    	                dp[i][j] = dp[i+1][j-1];
    	            (dp[i][j] == 1) ? (++cnt) : cnt;
    	        }
    	    }
    	}
    cout<<cnt<<endl;
    }
}





