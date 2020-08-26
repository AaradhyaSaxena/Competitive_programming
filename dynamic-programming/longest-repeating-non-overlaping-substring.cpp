/////https://practice.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring/0

///// longest repeating non-overlaping substring

#include <bits/stdc++.h>
using namespace std;

string helper(string str){ 
    int n = str.length(); 
    int LCSRe[n+1][n+1]; 
  
    memset(LCSRe, 0, sizeof(LCSRe)); 
  
    string res; // To store result 
    int res_length  = 0; // To store length of result 
  
    int i, index = 0; 
    for (i=1; i<=n; i++) 
    { 
        for (int j=i+1; j<=n; j++) 
        { 
            // (j-i) > LCSRe[i-1][j-1] to remove overlapping 
            if (str[i-1] == str[j-1] && LCSRe[i-1][j-1] < (j - i)){
             
                LCSRe[i][j] = LCSRe[i-1][j-1] + 1; 
  
                if (LCSRe[i][j] > res_length){ 
                    res_length = LCSRe[i][j]; 
                    index = max(i, index); 
                } 
            } 
            else
                LCSRe[i][j] = 0; 
        } 
    } 
  
    if (res_length > 0) 
    	return str.substr(index-res_length, res_length);
    else{
        return "-1";
    }
    return res; 
} 

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<helper(s)<<endl;
	}
	return 0;
}

////////////////

