//// https://practice.geeksforgeeks.org/problems/minimal-moves-to-form-a-string/0

#include <bits/stdc++.h>
using namespace std;

int helper(string str, int &cnt){
    if(str.length()==1){
        cnt++;
        return cnt;
    }
    cnt++;
    if(str.length()%2 == 0 and str.substr(0, str.length()/2) == str.substr(str.length()/2, str.length())){
        str = str.substr(0, str.length()/2);
    }
    else{
        str = str.substr(0, str.length()-1);
    }
    helper(str,cnt);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int cnt = 0;
	    helper(str,cnt);
	    cout<<cnt<<endl;
	}
	return 0;
}
