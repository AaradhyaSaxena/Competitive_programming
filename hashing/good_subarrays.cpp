/////////// https://codeforces.com/contest/1398/problem/C

#include<bits/stdc++.h>
using namespace std;

int T,n;
string s;
map<int,int>mp;

int main(){
	cin>>T;
	while(T--){
		mp.clear(); 
		cin>>n>>s;
		mp[0]++;
		long long ans=0,sum=0;
		for(int i=0;i<n;i++){
			sum+=s[i]-'1'; 
			ans+=mp[sum];
			mp[sum]++;
		}
		cout<<ans<<endl;
	}
}