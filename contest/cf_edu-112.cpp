//////// cf edu 112

//////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
void solve(int tc = 0) {
	ll n;
	cin >> n;
	if(n<6){
		cout<<15<<endl;
	}
	else if(n%2==0){
		cout<<(n/2)*5<<endl;
	}
	else{
		cout<<((n+1)/2)*5<<endl;
	}
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

////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

bool checkifPossible(ll wn, ll hn, ll wo, ll ho, ll W, ll H){
	if(wn+wo<=W or hn+ho<=H){
		return true;
	}
	return false;
}
     
void solve(int tc = 0) {
	ll W,H, x1, y1, x2, y2, wn, hn, wo, ho;
	cin >>W>>H>>x1>>y1>>x2>>y2>>wn>>hn;
	wo = x2-x1, ho = y2-y1;
	if(!checkifPossible(wn,hn,wo,ho,W,H)){
		cout<<-1<<endl;
	}
	else{
		// when we dont have to move
		ll sl = x1, sr = W-x2, st = H-y2, sb = y1;
		if(wn<=sl or wn<=sr or hn<=st or hn<=sb){
			cout<<0.000000000<<endl;
		}
		else{
			// fit to left
			ll ans = INT_MAX;
			if(wn+wo<=W){
				ans = min(ans,(wn-x1));
			}
			// fit to bottom
			if(hn+ho<=H){
				ans = min(ans,(hn-y1));
			}
			// fit to right
			if(wn+wo<=W){
				ans = min(ans,(x2- (W-wn)));
			}
			// fit to top
			if(hn+ho<=H){
				ans = min(ans,(y2- (H-hn)));
			}
			cout<<ans<<endl;
		}
	}
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

///////// C

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
void solve(int tc = 0) {
	ll m;
	cin >> m;
	ll arr[2][m];
	for(ll i=0; i<m; i++){
		cin>>arr[0][i];
	}
	for(ll i=0; i<m; i++){
		cin>>arr[1][i];
	}
	ll sumleft[2][m+2];
	ll sumright[2][m+2];
	sumleft[0][0] = 0;
	sumleft[1][0] = 0;
	sumleft[0][1] = arr[0][0];
	sumleft[1][1] = arr[1][0];
	for(ll i=1; i<m; i++){
		sumleft[0][i+1] = sumleft[0][i] + arr[0][i]; 
		sumleft[1][i+1] = sumleft[1][i] + arr[1][i]; 
	}
	sumright[0][m+1] = 0;
	sumright[1][m+1] = 0;
	sumright[0][m] = arr[0][m-1];
	sumright[1][m] = arr[1][m-1];
	for(ll i=m-2; i>=0; i--){
		sumright[0][i+1] = sumright[0][i+2] + arr[0][i]; 
		sumright[1][i+1] = sumright[1][i+2] + arr[1][i]; 
	}

	ll ans[2][m];
	for(ll i=0; i<m; i++){
		ans[0][i] = 0;
		ans[1][i] = 0;
	}
	for(ll i=0; i<m; i++){
		ans[0][i] = sumright[0][i+2];
		ans[1][i] = sumleft[1][i];
	}
	
	ll finalans = INT_MAX;
	for(ll i=0; i<m; i++){
		finalans = min(finalans, max(ans[0][i], ans[1][i]));
	}
	cout<<finalans<<endl;
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

////// D

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;

// int dp[1001][1001];
// string ss;

// bool isPal(string s, int i, int j){
//     if (i > j) return 1;
//     if (dp[i][j] != -1) return dp[i][j];
//     if (s[i] != s[j]) return dp[i][j] = 0;
//     return dp[i][j] = isPal(s, i + 1, j - 1);
// }
 
// void countSubstrings(string s){
//     memset(dp, -1, sizeof(dp));
//     int n = s.length();
//     int count = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             if (isPal(s, i, j)) count++;
//         }
//     }
// }

// void solve(int tc = 0) {
// 	ll l,r;
// 	cin>>l>>r;
// 	cout<<dp[l][r]<<endl;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     ll n, m;
// 	cin>>n>>m;
// 	cin>>ss;
// 	countSubstrings(ss);
//     while(m--){
// 		solve();
//     }
//     return 0;
// }

/////////////////////////////

/// why only 3 characters 

#include<bits/stdc++.h>
#define N	200000
#define INF	0x3f3f3f3f
 
int min(int a, int b) { return a < b ? a : b; }
 
char ss[][4] = { "abc", "acb", "bac", "bca", "cab", "cba" };
 
int main() {
	static char cc[N + 1];
	static int pp[6][N];
	int n, m, h, i;
 
	scanf("%d%d%s", &n, &m, cc);
	for (h = 0; h < 6; h++)
		for (i = 0; i < n; i++)
			pp[h][i] = (i == 0 ? 0 : pp[h][i - 1]) + (cc[i] != ss[h][i % 3]);
	while (m--) {
		int l, r, ans;
 
		scanf("%d%d", &l, &r), l--, r--;
		ans = INF;
		for (h = 0; h < 6; h++)
			ans = min(ans, pp[h][r] - (l == 0 ? 0 : pp[h][l - 1]));
		printf("%d\n", ans);
	}
	return 0;
}

//////////////
