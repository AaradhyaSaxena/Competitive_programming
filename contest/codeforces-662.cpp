//// Code_forces 662

///// problem E1
/// https://codeforces.com/contest/1393/problem/E1
/// solution ///

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int const maxn = 1e5 + 5, maxc = 1e6 + 5;
ll mod[2], P[2], p[2][maxc], rev_P[2];
vector < ll > h[2][maxn];
vector < int > sorted[maxn];
string s[maxn];
int nxt[maxc];
int a[maxc], dp[2][maxc], inf = 1e9 + 7;
int MOD = 1e9 + 7;

ll st(ll x, int y, int ok) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        ll d = st(x, y / 2, ok);
        return d * d % mod[ok];
    }
    return x * st(x, y - 1, ok) % mod[ok];
}

inline char get_c(int i, int x, int numb) {
    if (numb < x) return s[i][numb];
    if (numb + 1 < (int)s[i].size()) return s[i][numb + 1];
    return ' ';
}

inline ll get_hash(int t, int i, int x, int len) {
    if (len < x) return h[t][i][len];
    return (h[t][i][x] + (h[t][i][len + 1] - h[t][i][x + 1] + mod[t]) * rev_P[t]) % mod[t];
}

inline pair < ll, ll > get_h(int i, int x, int len) {
    return {get_hash(0, i, x, len), get_hash(1, i, x, len)};
}

inline int check(int i, int x, int j, int y) {
    int len1 = (int)s[i].size(), len2 = (int)s[j].size();
    if (x != len1) len1--;
    if (y != len2) len2--;
    int lef = 0, righ = min(len1, len2) + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (get_h(i, x, mid) == get_h(j, y, mid)) lef = mid;
        else righ = mid;
    }
    return get_c(i, x, lef) >= get_c(j, y, lef);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mod[0] = 1e9 + 7, mod[1] = 1e9 + 9, P[0] = 29, P[1] = 31, rev_P[0] = st(P[0], mod[0] - 2, 0), rev_P[1] = st(P[1], mod[1] - 2, 1);
    p[0][0] = 1, p[1][0] = 1;
    for (int i = 1; i < maxc; ++i) {
        for (int j = 0; j <= 1; ++j) p[j][i] = p[j][i - 1] * P[j] % mod[j];
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        for (int j = 0; j <= 1; ++j) {
            h[j][i].push_back(0);
            for (int pos = 0; pos < (int)s[i].size(); ++pos) {
                h[j][i].push_back((h[j][i][pos] + p[j][pos] * (s[i][pos] - 'a' + 1)) % mod[j]);
            }
        }
        nxt[(int)s[i].size() - 1] = (int)s[i].size() - 1;
        for (int pos = (int)s[i].size() - 2; pos >= 0; --pos) {
            if (s[i][pos] != s[i][pos + 1]) nxt[pos] = pos + 1;
            else nxt[pos] = nxt[pos + 1];
        }
        int l = 0, r = (int)s[i].size() - 1;
        for (int j = 0; j < (int)s[i].size(); ++j) {
            if (s[i][nxt[j]] <= s[i][j]) a[l++] = j;
            else a[r--] = j;
        }
        for (int j = 0; j < (int)s[i].size(); ++j) {
            sorted[i].push_back(a[j]);
            if (a[j] == (int)s[i].size() - 1) sorted[i].push_back((int)s[i].size());
        }
    }
    for (int i = 0; i <= (int)s[1].size(); ++i) {
        dp[0][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        int oks = (i - 1) % 2, ptr = 0, sum = 0, cur = -1;
        for (auto key : sorted[i]) {
            cur++;
            while (ptr < (int)sorted[i - 1].size() && check(i, key, i - 1, sorted[i - 1][ptr])) {
                sum += dp[(1^oks)][ptr];
                if (sum >= MOD) sum -= MOD;
                ptr++;
            }
            dp[oks][cur] = sum;
        }
    }
    int ans = 0;
    for (int i = 0; i <= (int)s[n].size(); ++i) {
        ans += dp[(n - 1) % 2][i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
    return 0;
}



////////////////////////////

    #include <bits/stdc++.h>
    constexpr int P = 1000000007;
    int norm(int x) {
        if (x < P) {
            return x;
        } else {
            return x - P;
        }
    }
    int main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int n;
        std::cin >> n;
        std::vector<std::string> s(n);
        std::vector<std::vector<int>> p(n), dp(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> s[i];
            int m = s[i].length();
            p[i].resize(m + 1);
            dp[i].resize(m + 1);
            std::iota(p[i].begin(), p[i].end(), -1);
            std::vector<int> lcp(m);
            for (int j = m - 2; j >= 0; --j)
                lcp[j] = (s[i][j] == s[i][j + 1]) ? 1 + lcp[j + 1] : 0;
            std::sort(p[i].begin(), p[i].end(), [&](int x, int y) {
                if (x == -1) {
                    return y + 1 + lcp[y] < m && s[i][y + lcp[y]] < s[i][y + 1 + lcp[y]];
                } else if (y == -1) {
                    return x + 1 + lcp[x] == m || s[i][x + 1 + lcp[x]] < s[i][x + lcp[x]];
                } else if (x < y) {
                    return x + lcp[x] < y && s[i][x + 1 + lcp[x]] < s[i][x + lcp[x]];
                } else {
                    return y + lcp[y] < x && s[i][y + lcp[y]] < s[i][y + 1 + lcp[y]];
                }
            });
        }
        for (int i = 0; i < n; ++i) {
            int m = s[i].length();
            if (i == 0) {
                for (int j = 0; j <= m; ++j)
                    dp[i][j] = 1;
                continue;
            }
            int xm = s[i - 1].length();
            s[i - 1] += char(0);
            s[i] += char(1);
            int res = 0;
            int mx = std::max(xm, m) + 1;
            int mn = std::min(xm, m) + 1;
            std::vector<int> lcp(mx + 1), lcps(mx + 1), lcpt(mx + 1);
            for (int j = mn - 1; j >= 0; --j)
                lcp[j] = (s[i - 1][j] == s[i][j]) ? 1 + lcp[j + 1] : 0;
            for (int j = std::min(xm, m - 1); j >= 0; --j)
                lcps[j] = (s[i - 1][j] == s[i][j + 1]) ? 1 + lcps[j + 1] : 0;
            for (int j = std::min(xm - 1, m); j >= 0; --j)
                lcpt[j] = (s[i - 1][j + 1] == s[i][j]) ? 1 + lcpt[j + 1] : 0;
            auto cmp = [&](int x, int y) {
                if (x == -1 && y == -1) {
                    return s[i - 1] < s[i];
                } else if (x == y) {
                    return lcp[0] < x ? s[i - 1][lcp[0]] < s[i][lcp[0]] : s[i - 1][x + 1 + lcp[x + 1]] < s[i][x + 1 + lcp[x + 1]];
                } else if (x == -1) {
                    return lcp[0] < y ? s[i - 1][lcp[0]] < s[i][lcp[0]] : s[i - 1][y + lcps[y]] < s[i][y + 1 + lcps[y]];
                } else if (y == -1) {
                    return lcp[0] < x ? s[i - 1][lcp[0]] < s[i][lcp[0]] : s[i - 1][x + 1 + lcpt[x]] < s[i][x + lcpt[x]];
                } else if (x < y) {
                    return lcp[0] < x ? s[i - 1][lcp[0]] < s[i][lcp[0]] : x + lcpt[x] < y ? s[i - 1][x + 1 + lcpt[x]] < s[i][x + lcpt[x]] : s[i - 1][y + 1 + lcp[y + 1]] < s[i][y + 1 + lcp[y + 1]];
                } else {
                    return lcp[0] < y ? s[i - 1][lcp[0]] < s[i][lcp[0]] : y + lcps[y] < x ? s[i - 1][y + lcps[y]] < s[i][y + 1 + lcps[y]] : s[i - 1][x + 1 + lcp[x + 1]] < s[i][x + 1 + lcp[x + 1]];
                }
            };
            for (int j = 0, k = 0; j <= m; ++j) {
                while (k <= xm && cmp(p[i - 1][k], p[i][j]))
                    res = norm(res + dp[i - 1][k++]);
                dp[i][j] = res;
            }
            s[i - 1].pop_back();
            s[i].pop_back();
        }
        int ans = std::accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0ll) % P;
        std::cout << ans << "\n";
        return 0;
    }

///// problem D
/// https://codeforces.com/contest/1393/problem/D


#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int64_t ans = 0;
    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i <= 1 || j == 0 || j == m - 1 || a[i][j] != a[i - 1][j] || a[i][j] != a[i - 2][j] || a[i][j] != a[i - 1][j - 1] || a[i][j] != a[i - 1][j + 1]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = std::min({dp[i - 1][j], dp[i - 2][j], dp[i - 1][j - 1], dp[i - 1][j + 1]}) + 1;
            }
            ans += dp[i][j];
        }
    }
    std::cout << ans << "\n";
    return 0;
}


//// problem C
/// https://codeforces.com/contest/1393/problem/C

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;     
ll n, b, cnt, dist;
     
int num[100005];
void solve()
{
	int n,b;
	cin >> n;
	memset(num, 0, sizeof(num));
	for(int i=0;i<n;i++)
	{
		cin >> b;
    	num[b]++;
    }
    cnt = 0; dist = 0;
    for (int i = 1; i <= n; i++)
    {
    	/// only thing that matters is the cnt of most frequent number
    	if(num[i] == cnt) dist++;
    	else if(num[i] > cnt) cnt = num[i], dist = 0;
    }
    cout << (n - cnt - dist) / (cnt - 1) << endl;     
}
     
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	ll T = 1;
	cin >> T;
	while(T--) solve();
}

///////////////////////////////////////////////

/// https://codeforces.com/contest/1393/problem/B
//// problem B

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	map<int,int> mp;
	map<int, int>::iterator itr; 
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(mp.find(arr[i])==mp.end()){
			mp[arr[i]] = 1;
		}else{
			mp[arr[i]]++;
		}
	}
	int t;
	cin>>t;
	int cnt4 = 0, cnt2 = 0;
	for(itr = mp.begin(); itr != mp.end(); ++itr) {
		int value = itr->second;
		cnt4 += value/4;
		cnt2 += (value%4)/2;
	}
	while(t--){
		char sign; int num;
		cin>>sign; cin>>num;
		if(sign=='+'){
			if(mp.find(num)==mp.end()){
				mp[num] = 1;
			}else{
				if(mp[num]%4==3){
					cnt4++;
				}
				if(mp[num]%4==1 and mp[num]%2==1){
					cnt2++;
				}
				mp[num]++;
			}
		}else{
			int prev = mp[num];
			if(mp[num]%4==0){
				cnt4--;
			}
			if(mp[num]%4 !=0 and mp[num]%2==0){
				cnt2--;
			}
			mp[num]--;
		}
		if(cnt4 >= 2){
			cout<<"YES"<<endl;
		}else if(cnt4 ==1 and cnt2 >= 2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

/////////////////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d, e, f;
     
int num[100005];
void solve()
{
	cin >> a;
	memset(num, 0, sizeof(num));
	while(a--)
	{
		cin >> b;
		num[b]++;
	}
	cin >> a;
	c = 0; d = 0;
	for (int i = 1; i <= 100000; i++)
	{
		c += num[i] / 4;
		d += num[i] % 4 / 2;
	}
	string z;
	while (a--)
	{
		cin >> z >> b;
		c -= num[b] / 4;
		d -= num[b] % 4 / 2;
		if (z == "-")num[b]--;
		else num[b]++;
		c += num[b] / 4;
		d += num[b] % 4 / 2;
		if (c >= 1 && (c - 1) * 2 + d >= 2)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
     
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	ll T = 1;
	//cin >> T;
	while (T--)solve();
}

////////////////////////////////////////////////
////////////////////////////////////////////////
///https://codeforces.com/contest/1393/problem/A

//// problem A
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, ans; 
		cin>>n;
		ans = (n/2)+1;
		cout<<ans<<endl;
	}
	return 0;
}

