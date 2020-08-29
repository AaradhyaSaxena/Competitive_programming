///////// https://practice.geeksforgeeks.org/problems/number-formation/0

//// Number formation

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define max 1000000007

lld dp[101][101][101],cnt[101][101][101];

int main()
{
    int t;
    cin>>t;
    for(int i1=0;i1<101;i1++)
    {
        for(int i2=0;i2<101;i2++)
        {
            for(int i3=0;i3<101;i3++)
            {
                dp[i1][i2][i3]=0;
                cnt[i1][i2][i3] = (!i1 && !i2 && !i3);
                if(i1)
                {
                    dp[i1][i2][i3] = ( dp[i1][i2][i3] + 10*dp[i1-1][i2][i3] + 4*cnt[i1-1][i2][i3] )%1000000007;
                    cnt[i1][i2][i3] = ( cnt[i1][i2][i3] + cnt[i1-1][i2][i3] )%1000000007;
                }
                if(i2)
                {
                    dp[i1][i2][i3] = (dp[i1][i2][i3] + 10*dp[i1][i2-1][i3] + 5*cnt[i1][i2-1][i3])%1000000007;
                    cnt[i1][i2][i3] = (cnt[i1][i2][i3] + cnt[i1][i2-1][i3])%1000000007;
                }
                if(i3)
                {
                    dp[i1][i2][i3] = (dp[i1][i2][i3] + 10*dp[i1][i2][i3-1] + 6*cnt[i1][i2][i3-1])%1000000007;
                    cnt[i1][i2][i3] = (cnt[i1][i2][i3] + cnt[i1][i2][i3-1])%1000000007;
                }
            }
        }
    }
    for(int iter=0;iter<t;iter++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        lld sum=0;
        for(int i1=0;i1<=x;i1++)
        {
            for(int i2=0;i2<=y;i2++)
            {
                for(int i3=0;i3<=z;i3++)
                {
                sum=(sum+dp[i1][i2][i3])%1000000007;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

// adding 45 and 54 gives same result as adding 44 and 55.

///////////////////////

/*

Let us consider f(x,y,z)  represents the sum of all numbers formed using  number of 4's,  number of 5's and number of 6's.
So, the required value can be calculated as given below.

for (int i = 0; i <= x; ++ i) 
    for (int j = 0; j <= y; ++ j) 
      for (int k = 0; k <= z; ++ k) 
            ans+=f(i,j,k);


Now, let us see how to calculate the value of f(x,y,z). Let us consider that g(x,y,z) represents number of numbers which
have x number of 4's, y number of 5's and z number of 6's.


recurrence relation is:

f(x,y,z)=A+B+C

where

A=10*f(x-1,y,z)+4*g(x-1,y,z)
B=10*f(x,y-1,z)+5*g(x,y-1,z)
C=10*f(x,y,z-1)+6*g(x,y,z-1)

*/







