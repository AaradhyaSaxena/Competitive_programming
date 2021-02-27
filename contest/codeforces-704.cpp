////// 704

////////////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(){
	ll p, a, b, c;
	cin>>p>>a>>b>>c;
	ll temp = INT_MAX;

	ll aa = 0, bb =0, cc =0;
	if(p%a != 0) aa = 1;
	if(p%b != 0) bb = 1;
	if(p%c != 0) cc = 1;
	temp = min(temp, ((p/a)+ aa)*a - p);
	temp = min(temp, ((p/b)+ bb)*b - p);
	temp = min(temp, ((p/c)+ cc)*c - p);

	cout<<temp<<endl;

	return;
}
 
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

///////////////////////

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(){
	ll x, y;
	cin >> x >> y;
	return;
}
 
int main(){
	int T ;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

////////////////////