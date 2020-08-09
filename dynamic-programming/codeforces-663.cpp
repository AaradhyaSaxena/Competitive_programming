///// problem C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int MOD = 1e9+7;   
ll power(ll x, ll n, ll m){
	if(n == 0) return 1;
	ll u = power(x,n/2,m);
	u = (u*u) % m;
	if(n%2) u = (u*x) % m;
	return u;
}

int main (){
    int n;
    cin>>n;
     
    ll ans = 0;
    ll i;
     
    ll fact[n+1];
    fact[0] = 1;
     
    for(i=1;i<=n;i++)
        fact[i] = (fact[i-1]*i)%MOD;
     
    ans = fact[n];
     
    ll num = power(2,n-1,MOD);
    ll temp = num;
     
    ans = (ans+MOD-temp)%MOD;
    cout<<ans<<endl;
}

////// problem B

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		char arr[n][m];
		int i,j, cnt = 0;
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				cin>>arr[i][j];
			}
		}
		i = n-1;
		for(j=0; j<m-1; j++){
			if(arr[i][j] != 'R') cnt++;
		}
		j=m-1;
		for(i=0; i<n-1; i++){
			if(arr[i][j] != 'D') cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}


////// problem A

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1; i<=n; i++){
			cout<<i<<" ";
		}cout<<endl;
	}
}

//////// problem D

// #include <bits/stdc++.h>
// #define IOS ios::sync_with_stdio(false), cin.tie(0)
// #define debug(a) cout << #a ": " << a << endl
// using namespace std;
// typedef long long ll;
// const int N = 1e6 + 7;
// vector<vector<int> > a(N);
// string s;
// int n, m;
// int solve(int pre1, int pre2){
//     int ans = 0;
//     if (n == 3){
//         for (int i = 1; i <= m; ++i){
//             int k1 = (a[1][i]+a[2][i])%2;
//             int k2 = (a[2][i]+a[3][i])%2;
//             if ((pre1^k1) && (pre2^k2)){
//                 pre1 ^= 1, pre2 ^= 1;
//             }else{
//                 ans++;
//                 pre1 ^= 1, pre2 ^= 1;
//             }
//         }
//     }else{
//         for (int i = 1; i <= n; ++i){
//             int k1 = (a[i][1]+a[i][2])%2;
//             int k2 = (a[i][2]+a[i][3])%2;
//             if ((pre1^k1) && (pre2^k2)){
//                 pre1 ^= 1, pre2 ^= 1;
//             }else{
//                 ans++;
//                 pre1 ^= 1, pre2 ^= 1;
//             }
//         }
//     }
//     return ans;
// }

// int main(void){ 
//     IOS;
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i){
//         cin >> s;
//         a[i].resize(m+1);
//         for (int j = 0; j < m; ++j) a[i][j+1] = s[j]-'0';
//     }
//     if (n >= 4 && m >= 4){
//         cout << -1 << endl;
//     }else if (n == 1 || m == 1){
//         cout << 0 << endl;
//     }else if (n == 2){
//         int pre = 0, cnt1 = 0, cnt2 = 0;
//         for (int i = 1; i <= m; ++i){
//             int k = (a[1][i]+a[2][i])%2;
//             if (pre == k) cnt1++;
//             pre = pre^1;
//         }
//         pre = 1;
//         for (int i = 1; i <= m; ++i){
//             int k = (a[1][i]+a[2][i])%2;
//             if (pre == k) cnt2++;
//             pre = pre^1;
//         }
//         cout << min(cnt1, cnt2);
//     }else if (m == 2){
//         int pre = 0, cnt1 = 0, cnt2 = 0;
//         for (int i = 1; i <= n; ++i){
//             int k = (a[i][1]+a[i][2])%2;
//             if (pre == k) cnt1++;
//             pre = pre^1;
//         }
//         pre = 1;
//         for (int i = 1; i <= n; ++i){
//             int k = (a[i][1]+a[i][2])%2;
//             if (pre == k) cnt2++;
//             pre = pre^1;
//         }
//         cout << min(cnt1, cnt2) << endl;
//     }else{
//         cout << min(min(solve(0, 0), solve(0, 1)), min(solve(1, 0), solve(1, 1))) << endl;
//     }
//     return 0;
// }