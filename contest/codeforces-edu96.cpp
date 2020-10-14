////////// Edu round 96

/////// p1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int num;
    	cin>>num;
    	int flag = 0;
    	for(int i=0; i<=num/3; i++){
    		for(int j=0; j<=num/5; j++){
    			for(int k=0; k<=num/7; k++){
    				if(3*i + 5*j + 7*k == num){
    					cout<<i<<" "<<j<<" "<<k<<endl;
    					flag=1;
    					break;
    				}
    			}
    			if(flag==1) break;
    		}
    		if(flag==1) break;
    	}
    	if(flag==0){
    		cout<<-1<<endl;
    	}
    }
    return 0;
}

/// aliter

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int num;
    	cin>>num;
    	bool dp[1001];
    	memset(dp,false, sizeof(dp));
    	dp[0] = true;
    	for(int i=0; i<=1000; i++){
    		if(dp[i]==false) continue;
    		dp[i+3] = dp[i+5] = dp[i+7] = true;
    	}
    	
    	if(dp[num] == false){
    		cout<<-1<<endl;
    	}
    	else{
    		int count[3] = {0};
    		while(num>0){
    			if(dp[num-3]){
    				count[0]++;
    				num = num-3;
    			}
    			else if(dp[num-5]){
    				count[1]++;
    				num = num-5;
    			}
    			else{
    				count[2]++;
    				num = num - 7;
    			}
    		}
    		cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<endl;
    	}
    }
    return 0;
}


/////////////////// p2

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	ll n, k;
    	cin>>n>>k;
    	ll arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);
    	ll maxx = 0;
    	ll minn = 0;
    	for(int i=0; i<=k; i++){
    		maxx += arr[n-1-i];
    	}
    	cout<<(maxx-minn)<<endl;
    }
    return 0;
}


/////////// p3

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
    	ll n;
    	cin>>n;
    	ll arr[n+1];
    	for(ll i=0; i<=n; i++){
    		arr[i] = i;
    	}
    	if(n==2){
    		cout<<2<<endl;
    		cout<<1<<" "<<2<<endl;
    	}
    	else{
    	ll i = n, j=n-2;
    	vector<pair<ll,ll>> pr;
    	while(i>1){
    		if(i==j){
    			j--;
    			continue;
    		}
    		if(arr[i]%2 == arr[j]%2 and i!=j){
    			j = min(i,j);
    			i = max(i,j);
    			pr.push_back({arr[i],arr[j]});
    			arr[j] = (arr[i]+arr[j]+1)/2;
    		}
    		i = max(i,j);
    		i--;
    	}
    	cout<<arr[i]<<endl;
    	for(ll k=0; k<pr.size(); k++){
    		cout<<pr[k].first<<" "<<pr[k].second<<endl;
    	}
    	}
    }
    return 0;
}

/////////////// p5

//// https://www.youtube.com/watch?v=_Ib3EhfIwlE
//// tle
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin>>s;

    string rev = s;
    vector<int> str[30];
    for(int i=0; i<n; i++){
    	str[s[i]-'a'].push_back(i);
    }
    vector<int> cnt(30,0);

    int order[n+1];
    reverse(rev.begin(), rev.end());
    for(int i=0; i<n; i++){
    	int curr = (rev[i] - 'a');
    	order[i] = str[curr][cnt[curr]];
    	cnt[curr]++; 
    }

    int ans = 0;
    for(int i=n-1; i>=0; i--){
    	for(int j=i+1; j<n; j++){
    		if(order[i]>order[j]) ans++;
    	}
    }
    cout<<ans<<endl;

    return 0;
}

//// editorial

#include <bits/stdc++.h>
typedef long long li;
using namespace std;

#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
int n;
string s;
string revS;
vector<int> posS[30];
vector<int> posT[30];
int cnt[30];
int t[N];

inline int sum (int r) {
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

inline void inc (int i, int d) {
	for (; i < n; i = (i | (i+1)))
		t[i] += d;
}

int sum (int l, int r) {
	return sum (r) - sum (l-1);
}
     
inline void read() {	
	cin >> n >> s;
}

inline void solve() {
	revS = s;
	reverse(all(revS));
	for (int i = 0; i < sz(s); i++) {
		posS[s[i] - 'a'].pb(i);
		posT[revS[i] - 'a'].pb(i);
	}
	li ans = 0;
	for (int i = 0; i < sz(revS); i++) {
		int let = revS[i] - 'a';
		int cur = posS[let][cnt[let]];
		int oldC = cur;
		cur += sum(cur, n - 1);
		int need = i;
		ans += cur - need;
		inc(oldC, 1);
		cnt[let]++;
	}
	cout << ans << endl;
}

int main () { 
    read();
    solve();
}


///////// p4

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string str;
		cin>>str;

		int bank = 0;
		int idx = n-1;
		int turns = 0;

		while(idx>=0){
			int size = 0;
			int to_del = str[idx]-'0';

			while(idx>=0 and str[idx]-'0' == to_del){
				size++;
				idx--;
			}
			bank += size-1;
			
			turns++;
			if(bank==0 and idx==-1){
				break;
			}
			if(bank==0){
				idx--;
			}
			else{
				bank--;
			}
		}
		cout<<turns<<endl;
	}
}

////////// p6

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int arr[n][3];
    for(int i=0; i<n; i++){
    	for(int j=0; j<3; j++){
    		cin>>arr[i][j];
    	}
    }
    int i=0, flag = 0;
    while(i<n){
    	int time = arr[i][1] - arr[i][0] + 1;
    	int maxkills = time*k;
    	if(maxkills<arr[i][2]) flag = 1;
    	i++;
    }
    if(flag==1){
    	cout<<-1<<endl;
    }
    else{
    	ll ans = 0;
    	int time = bullets_available = bullets_left = bullets_fired = reloads = 0;
    	while(i<n){
    		
    		time = arr[i][1] - arr[i][0] + 1;
    		bullets_fired = arr[i][2];
    		reloads = arr[i][2]/k + (arr[i][2]%k)? 1: 0;

    		
    		i++;
    	}
    }

    return 0;
}

///// editorial

#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, k;
vector<int> l, r, a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	l.resize(n);
	r.resize(n);
	a.resize(n);
	fore(i, 0, n)
		cin >> l[i] >> r[i] >> a[i];
	return true;
}

inline void solve() {
	vector<li> d(n + 1, INF64);
	d[0] = 0;
	
	li ans = INF64;
	fore(i, 0, n) 
	{
		li rem = k, total = d[i];
		for (int j = i; j < n; j++) 
		{
			li cntReloads = (max(0LL, a[j] - rem) + k - 1) / k;
			if (cntReloads > r[j] - l[j])
				break;
			
			li newRem = (rem + cntReloads * k) - a[j];
			total += a[j];
			if (j + 1 < n) 
			{
				if (l[j] + cntReloads < l[j + 1])
					d[j + 1] = min(d[j + 1], total + newRem);
			} 
			else
				ans = min(ans, total);
			rem = newRem;
		}
	}
	if (ans > INF64 / 2)
		ans = -1;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	if(read())
		solve();

	return 0;
}

/*

Also, instead of keeping track of the remaining bullets, 
let's just look only at such indices of waves when we reloaded and threw remaining bullets before reaching them.

So, we can write the next dp: 
𝑑[𝑖] is the minimum number of bullets we spend dealing with the first 𝑖 waves 
and now we standing at the moment 𝑙𝑖 with full magazine. Obviously, 𝑑𝑝[0]=0.

*/

///////////////////

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){

//     }
//     return 0;
// }

///////////////////


