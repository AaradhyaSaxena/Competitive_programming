//////////https://codeforces.com/contest/1552/problem/0

///////// cf gr round 15

////// p1

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
		ll n; cin>>n;
		string ss;
		cin>>ss;
		string ff = ss;
		sort(ff.begin(), ff.end());
		ll cnt = 0;
		for(ll i=0; i<n; i++){
			if(ss[i] != ff[i]) cnt++;
		}
		cout<<cnt<<endl;
    }
    return 0;
}

///// p2

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
		int n; cin>>n;
		int arr[n][5];
		for(int i=0; i<n; i++){
			for(int j=0; j<5; j++){
				cin>>arr[i][j];
			}
		}
		vector<int> best;
		for(int i=0; i<5; i++){
			best.push_back(arr[0][i]);
		}
		int index = 1;
		for(int i=1; i<n; i++){
			int cnt = 0;
			for(int j=0; j<5; j++){
				if(best[j] < arr[i][j]) cnt += 1;
				else cnt -= 1;
			}
			if( cnt < 0){
				best.clear();
				for(int j=0; j<5; j++){
					best.push_back(arr[i][j]);
				}
				index = i+1;
			}
		}
		// confirmation round
		for(int i=0; i<n; i++){
			int cnt = 0;
			for(int j=0; j<5; j++){
				if(best[j] <= arr[i][j]) cnt += 1;
				else cnt -= 1;
			}
			if( cnt < 0){
				index = -1;
				break;
			}
			if(cnt== -1){
				break;
			}
		}
		cout<<index<<endl;
    }
    return 0;
}

/////// p4

//// incorrect 
// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     ll t;
//     cin >> t;
//     while(t--){
// 		ll n; cin>>n;
// 		ll arr[n];
// 		for(ll i=0; i<n; i++){
// 			cin>>arr[i];
// 		}
// 		set<ll> ss;
// 		ss.insert(0);
// 		bool flag = false;
// 		if(n==1) flag = true;
// 		for(ll i=0; i<n; i++){
// 			for(ll j=i+1; j<n; j++){
// 				if( ss.find(arr[i]-arr[j])!= ss.end() || ss.find(arr[j]-arr[i])!= ss.end()){
// 					flag = true;
// 					break;
// 				}
// 				ss.insert(arr[i]- arr[j]);
// 				ss.insert(arr[j]- arr[i]);
// 				ss.insert(arr[j]+ arr[i]);
// 			}
// 			if(flag) break;
// 		}
// 		if(flag) cout<<"YES"<<endl;
// 		else cout<<"NO"<<endl;
//     }
//     return 0;
// }

/// p4 correct

#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    int three2n = 1;
    for (int i = 1; i <= n; i++)
        three2n *= 3;
 
    for (int k = 1; k < three2n; k++) {
        int k_cp = k;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int s = k_cp % 3;
            k_cp /= 3;
            if (s == 2) s = -1;
            sum += s * a[i];
        }
        if (sum == 0) {
            cout << "YES" << endl;
            return;
        }
    }
 
    cout << "NO" << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    for (int i = 1; i <= t; i++)
        solve();
 
    return 0;
}

////////// p3

#include <iostream>
#include <vector>
 
using namespace std;
 
bool intersect(pair<int, int> c, pair<int, int> d) {
    if (c.first > d.first) swap(c, d);
    return c.second > d.first and c.second < d.second;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<pair<int, int>> chords;
    vector<bool> used(2 * n + 1, false);
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        chords.push_back(make_pair(x, y));
        used[x] = used[y] = true;
    }
 
    vector<int> unused;
    for (int i = 1; i <= 2 * n; i++)
        if (!used[i]) unused.push_back(i);
 
    for (int i = 0; i < n - k; i++)
        chords.push_back(make_pair(unused[i], unused[i + n - k]));
 
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += intersect(chords[i], chords[j]);
 
    cout << ans << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    for (int i = 1; i <= t; i++)
        solve();
 
    return 0;
}

////// p3 healthy_ug

/// sol used pnc

// void solve(){
// 	int n;
// 	cin >> n;
// 	int k;
// 	cin >> k;
	
// 	rep(i,1,2*n+1){
// 		f[i] = 1;
// 	}
	
// 	int free = n * 2;
// 	rep(i,0,k){
// 		cin >> a[i] >> b[i];
// 		free -= 2;
// 		f[a[i]] = 0;
// 		f[b[i]] = 0;
// 	}
	
// 	int ans = (n - k) * (n - k - 1) / 2;
// 	rep(i,0,k){
// 		int x = a[i];
// 		int y = b[i];
// 		if(y < x){
// 			swap(x,y);
// 		}
// 		int cnt = 0;
// 		rep(j,x+1,y){
// 			cnt += f[j];
// 		}
// 		ans += min(cnt,free - cnt);
// 		rep(j,i+1,k){
// 			int u = a[j], v = b[j];
// 			if((x < u && u < y) ^ (x < v && v < y)){
// 				ans++;
// 			}
// 		}
// 	}
// 	cout << ans << "\n";
// }
