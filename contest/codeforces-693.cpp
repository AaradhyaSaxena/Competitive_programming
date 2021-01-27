////////// codeforces 693

///// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

ll max(ll a, ll b){
    if(a>b)return a;
    else return b;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll w,h,n;
        cin>>w>>h>>n;
        ll cnt1=1, cnt2=1;
        while(w%2==0){
            cnt1 *= 2;
            w /=2;
        }
        while(h%2==0){
            cnt2 *= 2;
            h /=2;
        }
        if(cnt1*cnt2>=n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

/////////////// B

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
        int n; cin>>n;
        int temp = 0, c1 =0, c2 =0;
        for(int i=0; i<n; i++){
            cin>>temp;
            if(temp==1) c1++;
            else c2++;
        }
        if(c1%2==0 and c2%2==0) cout<<"YES"<<endl;
        else if(c2%2!=0 and c1==0) cout<<"NO"<<endl;
        else if(c1%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

///////////////
////C

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

ll helper(int n, vector<ll> vec){
    ll ans = 0;
    vector<ll> dp(n, 0);
    for(int i=n-1; i>=0; i--){
        dp[i] += vec[i];
        if(i+vec[i]<n){
            dp[i] += dp[i+vec[i]];
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin>>n;
        vector<ll> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        cout<<helper(n,vec)<<endl;
    }
    return 0;
}

///////////////
/// D

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
    ll arr[200005];
    while(t--){
        ll n; cin>>n; 
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        reverse(arr,arr+n);

        ll alice = 0, bob = 0;
        for(ll i=0; i<n; i++){
            if(i%2==0){
                if(arr[i]%2==0){
                    alice += arr[i];
                }
            }
            else{
                if(arr[i]%2 !=0){
                    bob += arr[i];
                }
            }
        }
        if(alice>bob){
            cout<<"Alice"<<endl;
        }
        else if(alice==bob){
            cout<<"Tie"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}

/////////////////
///// E

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <long long> vll;
typedef pair <long long, long long> pll;
#define pb push_back   
#define all(c) c.begin(), c.end()
#define For(i, a, b) for (long long i = a; i < b; ++i)
#define Forr(i, a, b) for (long long i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second
#define ll long long 
#define endl "\n"
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

void solve() {
    int n; cin >> n;
    pair <pii, int> arr[n];     
    For(i,0,n) {
        int a,b; cin >> a >> b;
        arr[i].first = {min(a,b), max(a,b)};
        arr[i].second = i;
    }
    sort(arr, arr+n);
    int min_val[n], min_index[n];

    For(i,0,n) {
        min_val[i] = arr[i].F.S;
        min_index[i] = arr[i].S;
    }
    int ans[n];
    For(i,0,n) {
        int it = lower_bound(arr, arr+n, make_pair(make_pair(arr[i].F.F, -1), -1)) - arr;
        --it;
        if (it >= 0 and min_val[it] < arr[i].F.S) {
            ans[arr[i].S] = min_index[it] + 1;
        }
        else {
            ans[arr[i].S] = -1;
        }
        if (i > 0 and min_val[i-1] <= min_val[i]) {
            min_val[i] = min_val[i-1];
            min_index[i] = min_index[i-1];
        }
    }
    For(i,0,n) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
 
int main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

////////////// F

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M_MAX = 200002;
 
int t;
int n, m;
 
struct Block{
    int a, b;
};
 
bool operator < (const Block &x, const Block &y){
    return x.b < y.b;
}
Block v[M_MAX];
 
int main(){{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            cin >> v[i].a >> v[i].b;
        }
        sort(v + 1, v + m + 1);
        bool complete = true;
        bool answer = true;
        for(int i = 1; i <= m && answer == true; i++)
        {
            if(v[i].b == v[i - 1].b)
                continue;
            if(i < m && v[i].b == v[i + 1].b)
            {
                answer = complete;
                continue;
            }
            if(complete == true)
            {
                complete = false;
                continue;
            }
            if(v[i].a == v[i - 1].a)
            {
                if((v[i].b - v[i - 1].b) % 2 == 0)
                    answer = false;
                else
                    complete = true;
            }
            else
            {
                if((v[i].b - v[i - 1].b) % 2 == 1)
                    answer = false;
                else
                    complete = true;
            }
        }
        if(complete == false)
            answer = false;
        if(answer == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

/////////////////////

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[y] |= (1 << (x - 1));
    }
    const int FULL = 3;
    v[2e9] = FULL;
    int hasLast = 0, lastColor = 0;
    for (auto[x, mask] : v) {
        if (mask != FULL && hasLast) {
            int color = (x + mask) % 2;
            if (lastColor == color) {
                cout << "NO\n";
                return;
            } 
            else {
                hasLast = false;
            }
        } 
        else if (mask == FULL && hasLast) {
            cout << "NO\n";
            return;
        } 
        else if (mask != FULL) {
            lastColor = (x + mask) % 2;
            hasLast = true;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/////////////////
/////////////////

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

/////////////////
