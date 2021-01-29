//////// cf edu 103

//////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
void solve(int tc = 0) {
	ll n, k;
	cin >> n >> k;
	ll x = (n + k - 1) / k;
	x *= k;
	cout << (x + n - 1) / n << '\n';
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
//////////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

void solve(int tc = 0) {
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0, sum = a[0];
	for (ll i = 1; i < n; i++) 
	{
		ll req = (100 * a[i] + k - 1) / k; /// ceiling function
		ans = max(ans, max(0LL, req - sum));
		sum += a[i];
	}	
	cout << ans << '\n';
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}


/////////// C

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

void solve(int tc = 0) {
	ll n;	cin >> n;
	ll a[n], b[n], c[n];
	for (ll i = 0; i < n; i++) cin >> c[i];
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> b[i];
	
	ll ans = 0;
	ll tot = c[n - 1];
	for (ll i = n - 1; i >= 1; i--) {
		tot += 2;
		if (a[i] > b[i]) swap(a[i], b[i]);
		ans = max(ans, tot + b[i] - a[i] - 1);
		
		if (a[i] == b[i]) {
			tot = c[i - 1];
		} else {
			tot += (c[i - 1]-1 - (b[i]-a[i]));
		}	
		tot = max(tot, c[i - 1]);
	}
	cout << ans << '\n';
}

     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);    cout.tie(0);
    int t;    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
/////////////////

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;
     
// void solve(int tc = 0) {
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int t; cin >> t;
//     while(t--){
// 		solve();
//     }
//     return 0;
// }

/////////