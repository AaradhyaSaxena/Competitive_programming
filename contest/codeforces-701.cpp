/////////////////

/////// A
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

ll helper(ll a, ll b, ll cnt){
	if(cnt>100) return 100;
	if(a==0) return cnt;
	if(a<b) return cnt+1;
	return min(helper(a/b,b,cnt+1), helper(a,b+1,cnt+1));
}

void solve(int tc = 0) {
	ll a,b,cnt =0; cin>>a>>b;
	if(a==0){
		cout<<cnt<<endl;
		return;
	}
	cnt = min(helper(a/b,b,1), helper(a,b+1,1));
	cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
		solve();
    }
    return 0;
}

///////////////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
void solve(int tc = 0) {
	ll n,q,k; cin>>n>>q>>k;
	ll arr[n], brr[n][3];
	for(ll i=0; i<n; i++){
		cin>>arr[i];
		brr[i][0] = brr[i][1] = brr[i][2] = 0;
	}
	brr[0][0] = arr[1]-2, brr[0][1] = arr[1]-2; 
	brr[0][2] = k-1;
	
	for(ll i=1; i<n-1; i++){
		brr[i][0] = arr[i+1] - 0 - 2;
		brr[i][1] = arr[i+1] - arr[i-1] - 2;
		brr[i][2] = k+1 - arr[i-1] - 2;
	}
	brr[n-1][0] = k-1; 
	brr[n-1][1] = k-arr[n-2]-1, brr[n-1][2] = k-arr[n-2]-1;

	for(ll i=1; i<n; i++){
		brr[i][1] += brr[i-1][1];
	}
	// for(int i=0; i<n; i++){
	// 	cout<<brr[i][0]<<" ";
	// }cout<<endl;
	// for(int i=0; i<n; i++){
	// 	cout<<brr[i][1]<<" ";
	// }cout<<endl;
	// for(int i=0; i<n; i++){
	// 	cout<<brr[i][2]<<" ";
	// }cout<<endl;

	ll cnt =0;
	ll left, right;
	for(ll i=0; i<q; i++){
		cnt =0;
		cin>>left>>right;
		left--; right--;
		cnt += brr[left][0];
		cnt += brr[right-1][1];
		cnt -= brr[left+1][1];
		cnt += brr[right][2];
		if(left==right){
			cnt = k-1;
		}
		cout<<cnt<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
		solve();
    }
    return 0;
}

/////////////////

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(){
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	for(ll i = 1; i*i < x; i++){
		ans += max( min(y, x/i -1) -i, 0LL);
	}
	cout << ans << endl;
	return;
}
 
int main(){
	int T = 1;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

///////////////D

#include <iostream>
using namespace std;
 
int main(){
	unsigned h,w,x,y,t;
	cin>>h>>w;
	for(y=0; y<h; ++y){
		for(x=0; x<w; ++x){
			cin>>t;
			if((x^y)&1)
				cout<<"720720 ";
			else cout<<720720+t*t*t*t<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
///////////////// F

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
 
#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010
 
ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b[maxn], tt;
map<ll, ll> mp;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n; mp.clear();
        for (i = 1; i <= n; i++) {
            cin >> b[i];
        }
        mp[0] = 1; tt = 1; k = 0;
        for (i = 1; i <= n; i++) {
            a = mp[k]; mp[k] = tt; k -= b[i];
            tt = (2 * tt - a + mod) % mod;
        }
        cout << tt << nl;
    }
    return 0;
}


//////////////
//////////////////