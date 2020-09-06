/////////////////
//////////


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
    	int a,b;
    	cin>>a>>b;

    	int k = abs(b-a);
    	int cnt =0;
    	if(k==0){
    		cout<<0<<endl;
    	}else if(k<=10){
    		cout<<1<<endl;
    	}else{
    		cnt = k/10;
    		if(k%10){
    			cout<<cnt+1<<endl;	
    		}else{
    			cout<<cnt<<endl;
    		}
    	}
    }
    return 0;
}

////// p2

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
    	ll a,b,x,y,n;
    	cin>>a>>b>>x>>y>>n;
    	ll A = a-x, B = b-y;
    	if(n>= A+B)
    	{
    		cout<< (x*y) <<endl;
    	}
    	else{

    		ll minn = a*b;
    		if(n<=A){
    			minn = min(minn, ((a-n)*b));
    		}
    		if(n<=B){
    			minn = min(minn, ((b-n)*a));
    		}
    		if(n>A){
    			minn = min(minn, (x*(b-(n-A))));
    		}
    		if(n>B){
    			minn = min(minn, (y*(a-(n-B))));
    		}
    		cout<<minn<<endl;

    	}
    }
    return 0;
}

///// p3

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
    	int n,x,y;
    	cin>>n>>x>>y;
    	if(n==2){
    		cout<<x<<" "<<y<<endl;
    	}
    	else if((y-x)%(n-1)==0)
    	{
    		int d = (y-x)/(n-1);
    		for(int i=0; i<n; i++){
    			cout<<(x+ i*d)<<" ";
    		}cout<<endl;
    	}
    	else 
    	{
    		int flag = 0;
    		vector<int> vec;
    		int diff = 0;
    		int di = (y-x)/(n-1) + 1;
    		int dj = (y-x);
    		for(int i = di; i<=dj; i++){
    			if((y-x)%i==0){
    				if(y > (n-1)*i){
    					for(int j = y, cnt =0; j>0, cnt<n; j= j-i, cnt++){
    						vec.push_back(j);
    					}
    				}
    				else{
    					int minn = INT_MAX, real_min = 0;
    					for(int cnt=0; cnt<n; cnt++){
    						vec.push_back(y - i*cnt);
    						if(y - i*cnt>0){
    							minn = min(minn, y - i*cnt);
    						}
    					}
    					real_min = y- (n-1)*i;
    					diff = minn-real_min;
    					flag = 1;
    				}
    				break;
    			}
    		}
    		if(flag==1){
    			for(int i=0; i<n; i++){
    				vec[i] += diff;
    			}
    		}
    		reverse(vec.begin(),vec.end());
    		for(int i=0; i<vec.size(); i++){
    			cout<<vec[i]<<" ";
    		}cout<<endl;

    	}

    }
    return 0;
}

////////////////////////
///// p3 nicer version 

int bestA[n];

for(int start=0; start<=50; start++){
	for(int diff =1; diff<=50; diff++){
		int a[n];
		a[0] = start;
		for(int i=1; i<n; i++){
			a[i] = a[i-1] + diff;
		}

		bool hasX = false, hasY = false;
		for(int i:a){
			if(i==x) hasX=true;
			if(i==y) hasY=true;
		}
		if(hasX && hasY && a[n-1]<best){
			best = a[n-1];
			bestA = a;
		}
	}
}

////////////////////////

////// p4

#include <bits/stdc++.h>

using namespace std;

int sum(long long n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {	
	int t;
	cin >> t;
	while (t--) {
		long long n;
		int s;
		cin >> n >> s;
		long long ans = 0;
		if (sum(n) <= s) {
			cout << 0 << endl;
			continue;
		}
		long long pw = 1;
		for (int i = 0; i < 18; ++i) 
		{
			int digit = (n / pw) % 10;
			long long add = pw * ((10 - digit) % 10);
			n += add;
			ans += add;
			if (sum(n) <= s) {
				break;
			}
			pw *= 10;
		}
		cout << ans << endl;
	}
	return 0;
}


/////// p5

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> x(n), y(n);
		for (auto &it : x) 
			cin >> it;
		for (auto &it : y) 
			cin >> it;

		sort(x.begin(), x.end());
		int j = n - 1;

		vector<int> l(n), r(n);

		for (int i = n - 1; i >= 0; --i) {
			while (x[j] - x[i] > k) --j;

			r[i] = j - i + 1;
			if (i + 1 < n) 
				r[i] = max(r[i], r[i + 1]);
		}
		j = 0;
		for (int i = 0; i < n; ++i) {
			while (x[i] - x[j] > k) ++j;
			
			l[i] = i - j + 1;
			if (i > 0) 
				l[i] = max(l[i], l[i - 1]);
		}
		int ans = 1;
		for (int i = 0; i < n - 1; ++i) {
			ans = max(ans, r[i + 1] + l[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
 
/////////// p6

 
const int N = 205;
ll dp[N][N][N];

int _runtimeTerror_()
{
    // if t are equal
    ll n,k;
    string s,t;
    cin>>n>>k>>s>>t;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            for(int l=0;l<=k;++l)
                dp[i][j][l] = -INF;
 
    if(t[0]==t[1])
    {
        int cnt = 0;
        for(int i=0;i<n;++i)
            cnt += s[i]==t[0];
        ll x = min(n,cnt+k);
        cout<<(x*(x-1)/2)<<"\n";
        return 0;
    }
    dp[0][0][0] = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            for(int l=0;l<=k;++l)
            {
                if(dp[i][j][l] == -INF)
                    continue;
                // chod dia
                if(s[i]==t[1])
                    amax(dp[i+1][j][l],dp[i][j][l]+j);
                else if(s[i]==t[0])
                    amax(dp[i+1][j+1][l],dp[i][j][l]);
                else
                    amax(dp[i+1][j][l],dp[i][j][l]);
                if(l==k)
                    continue;
                // first me kara
                if(s[i]==t[1])
                    amax(dp[i+1][j+1][l+1],dp[i][j][l]);
                else if(s[i]!=t[0])
                    amax(dp[i+1][j+1][l+1],dp[i][j][l]);
                // second me kara
                if(s[i]==t[0])
                    amax(dp[i+1][j][l+1],dp[i][j][l]+j);
                else if(s[i]!=t[1])
                    amax(dp[i+1][j][l+1],dp[i][j][l]+j);
 
            }
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=0;j<=n;++j)
    //     {
    //         for(int l=0;l<=k;++l)
    //             cout<<dp[i][j][l]<<" ";
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    // }
    ll ans = 0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=k;++j)
            amax(ans,dp[n][i][j]);
    cout<<ans<<"\n";
    return 0;
}

////////////////

////// TEMPLATE

////////////////

#include<bits/stdc++.h>
using namespace std ;
     
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double
 
const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);
 
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
 
const int N = 205;
ll dp[N][N][N];
 
int _runtimeTerror_()
{
    /////////////////
    ///// TYPI
    //// TYPI
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}

////////////////////




















