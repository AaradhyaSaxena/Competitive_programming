///////https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0

//// evaluate expression to true

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mpa make_pair
#define ff first
#define ss second
#define MOD 1003

map<pair<int, int>, int> _True;
map<pair<int, int>, int> _False;

int Tr(int i, int j, string exp){
    int Fa(int i, int j, string exp);
    if(i > j)
        return 0;
    if(i == j)
        return exp[i] == 'T';
        
    if(_True.count(mpa(i, j)))
        return _True[mpa(i, j)];
            
    int ans = 0;
    for(int k = i; k < j; ++k) {
        if(exp[k] == '&') 
            ans = ans + (Tr(i, k - 1, exp) * Tr(k + 1, j, exp));
                
        if(exp[k] == '|') 
            ans = ans + (Tr(i, k - 1, exp) * Tr(k + 1, j, exp)) + (Tr(i, k - 1, exp) * Fa(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Tr(k + 1, j, exp));  // beacuase T OR T = > T  T OR F = > T  F OR T => T
                
        if(exp[k] == '^') 
            ans = ans + (Tr(i, k - 1, exp) * Fa(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Tr(k + 1, j, exp));
        if(ans >= MOD)
            ans %= MOD;
    }
    return _True[mpa(i, j)] = ans;
}

int Fa(int i, int j, string exp){
    if(i > j)
        return 0;
    if(i == j)
        return exp[i] == 'F';
    
    if(_False.count(mpa(i, j)))
        return _False[mpa(i, j)];    
        
    int ans = 0;
    for(int k = i; k < j; ++k) {
        if(exp[k] == '&') 
            ans = ans + (Tr(i, k - 1, exp) * Fa(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Tr(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Fa(k + 1, j, exp));
                
        if(exp[k] == '|') 
            ans = ans + (Fa(i, k - 1, exp) * Fa(k + 1, j, exp)); 
            
        if(exp[k] == '^') 
            ans = ans + (Tr(i, k - 1, exp) * Tr(k + 1, j, exp)) + (Fa(i, k - 1, exp) * Fa(k + 1, j, exp));
        if(ans >= MOD)
            ans %= MOD;
    }
    return _False[mpa(i, j)] = ans;
}

int cnttrue(string str){
    _True.clear();
    _False.clear();
    int N = str.size();
    int ans = Tr(0, N - 1, str);
    return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s1;
		cin>>s1;
		cout<<cnttrue(s1)<<endl;
	}
}

////////////////////////////

#include <bits/stdc++.h>
using namespace std;

int dp[202][202][2];

int solve(string s,int i,int j,int istrue)
{
    if(dp[i][j][istrue]!=-1)
        return dp[i][j][istrue];
    if(i>j)
        return dp[i][j][istrue] =  0;
    if(i==j)
    {
        if(istrue==1)
        {
            if(s[i]=='T')
              dp[i][j][istrue] = 1;
            else
              dp[i][j][istrue] = 0;
        }
        else
        {
            if(s[i]=='F')
              dp[i][j][istrue] = 1;
            else
              dp[i][j][istrue] = 0;
        }
        return dp[i][j][istrue];
    }
    int ans = 0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt,lf,rt,rf;
            if(dp[i][k-1][1]!=-1)
                lt = dp[i][k-1][1];
            else
            {
                lt = solve(s,i,k-1,1);
                dp[i][k-1][1] = lt;
            }

            if(dp[i][k-1][0]!=-1)
                lf = dp[i][k-1][0];
            else
            {
                lf = solve(s,i,k-1,0);
                dp[i][k-1][0] = lf;
            }

            if(dp[k+1][j][1]!=-1)
                rt = dp[k+1][j][1];
            else
            {
                rt = solve(s,k+1,j,1);
                dp[k+1][j][1] = rt;
            }

            if(dp[k+1][j][0]!=-1)
                rf = dp[k+1][j][0];
            else
            {
                rf = solve(s,k+1,j,0);
                dp[k+1][j][0] = rf;
            }

    if(s[k] == '|')
    {
      if(istrue == 1)
           ans += lt * rt + lf * rt + lt * rf;
      else
           ans += lf * rf ;
    }

    if(s[k] == '&')
    {
      if(istrue == 1)
           ans += lt * rt;
      else
           ans += lf * rf + lt * rf + lf * rt;
    }

    if(s[k] == '^')
    {
      if(istrue == 1)
           ans += lf * rt + lt * rf ;
      else
           ans += lt * rt + lf * rf;
    }
    }
        dp[i][j][istrue] = ans%1003;
        return dp[i][j][istrue];
}
int main()
{
      int t;
      cin >>t;
      while(t--)
      {
      string s;
      int n;
      cin >>n;
      cin >>s;
      memset(dp,-1,sizeof(dp));
      int ans = solve(s,0,n-1,1);
      cout<<ans<<endl;
      }
}
