////////// https://codeforces.com/contest/1430/problem/E

/////////////// p5
 
//// https://www.youtube.com/watch?v=_Ib3EhfIwlE
//// 2:00 hr 
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

//// edi

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


////////////////
/////// merge sort for inverting array

    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define x first
    #define y second
     
    const int MOD = 1e9, maxn = 1e5;
     
    vector<int> sum;
     
    void merge_sort(vector<pair<int, int> > &to_sort, vector<int> &inv, vector<int> &res, int l, int r)
    {
        if(r - l == 1)
            return;
        int m = (l + r) / 2;
        merge_sort(to_sort, inv, res, l, m);
        merge_sort(to_sort, inv, res, m, r);
        vector<pair<int, int> > tmp;
        tmp.reserve(r - l + 1);
        int it1 = l, it2 = m;
        int cnt = 0;
        while(it1 < m || it2 < r)
        {
            if(it2 == r || (it1 != m && to_sort[it1] < to_sort[it2]))
            {
                tmp.push_back(to_sort[it1]);
                cnt += inv[to_sort[it1].y];
                if(cnt > MOD) cnt -= MOD;
                it1++;
            }
            else
            {
                tmp.push_back(to_sort[it2]);
                res[to_sort[it2].y] += cnt;
                if(res[to_sort[it2].y] > MOD) res[to_sort[it2].y] -= MOD;
                it2++;
            }
        }
        for(int i = l; i < r; i++)
            to_sort[i] = tmp[i - l];
     
    }
     
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n, k;
        cin >> n >> k;
        vector<pair<int, int> > a(n);
        vector<int> b(maxn + 1, 1);
        for(int i = 0; i < n; i++)
            cin >> a[i].x, a[i].y = i;
        reverse(a.begin(), a.end());
        for(int i = 0; i < n; i++) a[i].y = i;
        for(int i = 1; i < k; i++)
        {
            vector<pair<int, int> > ta(a);
            vector<int> tb(maxn + 1, 0);
            merge_sort(ta, b, tb, 0, n);
            b = tb;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cnt += b[i];
            if(cnt > MOD) cnt -= MOD;
        }
        cout << cnt;
        return 0;
    }

/////////////
///////////



