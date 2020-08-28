///////https://practice.geeksforgeeks.org/problems/queries-on-strings/0

//// queries on strings

#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
#define INT(x) (int)(x - 'a')
#define MOD 1000000007
long long dp[MAX][26], n, m, t;

void distinct_char(string s){
    int n =s.length();
    memset(dp, 0, sizeof(dp));
    dp[1][INT(s[0])]++;
    for (int i=1; i<n; i++){
        for (int j=0; j<26; j++)
            dp[i+1][j] = dp[i][j];
        dp[i+1][INT(s[i])]++;
    }
    return ;
}

int main(){
    cin>>t;
    string s;
    while (t--){
        cin>>s;
        distinct_char(s);
        int q;
        cin>>q;
        while (q--){
            int l, r;
            cin>>l>>r;
            int ans=0;
            for (int i=0; i<26; i++)
                if (l == -1 && dp[r-1][i]>0){
                    ans++;
                }
                else if (dp[r][i]-dp[l-1][i]>0)
                    ans++;

            cout<<ans<<" ";

        }
        cout<<endl;
    }
}


/*

We take a 2D array dp of size n*26 such that dp[i][j] 
denotes the cumulative occurance of the jth character from index 1 to i of the string.

    for each i varying from 1 to n
		for each j varying from 1 to 26
        	dp[i][j]=dp[i-1][j]

    		then add the character at the ith position of the string
         	dp[i][str[i]-'a']+=1;

Now, to answer the queries we just use inclusion exclusion. 
So if       dp[r][i]-dp[l-1][i] > 0   then that character exists in the range l to r. 

*/






