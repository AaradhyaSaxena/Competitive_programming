////// https://codeforces.com/contest/1391/problem/C

#include<iostream>
using namespace std;
#define ll long long
int mod = 1e9+7;

// first increasing then decreasing
// ans = n! - 2^(n-1)

int main (){
	int n;
	cin>>n; 
	ll fn = 1, pw = 1;
	for(int i=2; i<=n; i++){
		fn = fn*i%mod;
		pw = 2*pw%mod;
	}
	cout<<(fn+mod-pw)%mod<<endl;
}

// err (fn-pw)%mod >> (fn+mod-pw)%mod;
////https://www.youtube.com/watch?v=p_TwWyHnDi8