/// https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

#include <iostream>
using namespace std;

int helper(string a){
    int acount = 0, bcount = 0, ccount = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i]=='a'){
            acount = 1 + 2*acount;
        }if(a[i]=='b'){
            bcount = acount + 2*bcount;
        }if(a[i]=='c'){
            ccount = bcount + 2*ccount;
        }
    }
    return ccount;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<helper(s)<<endl;
	}
	return 0;
}

/////////////////
/////// dp 

int main() {
    int t;
    cin>>t;
    string s;
    cin>> s;

    int n = s.length();
    int dp[n+1][4];
    for(int i=0; i<=n; i++){
        for(int j=0; j<4; j++){
            dp[i][j] = 0;
        }
        if(j==0) dp[i][0] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<4; j++){
            if(j==1 and s[i-1]=='a'){
                dp[i][j] = 2*dp[i-1][j] + dp[i][j-1];
            }
            if(j==2 and s[i-1]=='b'){
                dp[i][j] = 2*dp[i-1][j] + dp[i][j-1];
            }
            if(j==3 and s[i-1]=='c'){
                dp[i][j] = 2*dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout<<dp[n][3]<<endl;

    return 0;
}




