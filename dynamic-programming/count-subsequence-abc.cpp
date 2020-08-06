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