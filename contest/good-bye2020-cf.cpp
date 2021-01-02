/////////////////////////
///////// goodbye 2020

///// A
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
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		set<int> st;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				st.insert(arr[j]-arr[i]);
			}
		}
		cout<<st.size()<<endl;
    }
    return 0;
}

//////////// B
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
    	int arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	sort(arr, arr+n);
    	int max_same=1, max_inc=1;
    	int ts, ti;
    	for(int i=1; i<n; i++){
    		ts = max_same; ti = max_inc;
    		if(arr[i]-arr[i-1]>=2){
    			max_same = max(ts, ti)+1;
    		}
    		else if(arr[i]-arr[i-1]==1){
    			max_same = max(ts+1,ti);
    			max_inc = max(ts,ti)+1;
    		}
    		else if(arr[i]==arr[i-1]){
    			max_inc = max(ts+1, ti);
    			max_same = ts;
    		}
    	}
    	cout<<max(max_same,max_inc)<<endl;
    }
    return 0;
}

//////// C

#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 7;
int n;
char in[N];
bool used[N];

void solve(){
	scanf("%s", in + 1);
	n = strlen(in + 1);

	for(int i = 1; i <= n; ++i){
		used[i] = false;
	}

	int ans = 0;
	for(int i = 2; i <= n; ++i){
		bool use_need = false;
		if(in[i] == in[i - 1] && !used[i - 1]){
			use_need = true;
		}
		if(i > 2 && in[i] == in[i - 2] && !used[i - 2]){
			use_need = true;
		}
		used[i] = use_need;
		ans += used[i];
	}
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	while(cases--){
		solve();
	}
	return 0;
}


////////// D

#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N = 100 * 1000 + 7;
int n;
int w[N];
int deg[N];

void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
        deg[i] = 0;
    }
    
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++; deg[v]++;
    }
    
    LL ans = 0;
    vector <int> to_sort;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < deg[i]; ++j)
            to_sort.push_back(w[i]);
        ans += w[i];
    }
    sort(to_sort.begin(), to_sort.end());
    reverse(to_sort.begin(), to_sort.end());
    
    for(auto &v: to_sort) {
        printf("%lld ", ans);
        ans += v;
    }
    printf("%lld\n", ans);
}

int main() {
    int cases;
    scanf("%d", &cases);
    
    while(cases--)
        solve();
    return 0;
}
/////////// E

#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N = 500 * 1000 + 7;
const int P = 60;
const int MX = 1e9 + 7;

int n;
LL in[N];
int cnt[P];

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < P; ++i)
        cnt[i] = 0;
    
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &in[i]);
        for(int j = 0; j < P; ++j)
            cnt[j] += in[i] >> j & 1;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        LL exp_or = 0, exp_and = 0;
        for(int j = 0; j < P; ++j){
            if(in[i] >> j & 1){
                exp_or += (1LL << j) % MX * n;
                exp_and += (1LL << j) % MX * cnt[j];
            }
            else
                exp_or += (1LL << j) % MX * cnt[j];
        }
        
        exp_and %= MX, exp_or %= MX;
        ans = (ans + 1LL * exp_or * exp_and) % MX;
    }
    
    printf("%d\n", ans);
}

int main(){
    int cases;
    scanf("%d", &cases);
    
    while(cases--)
        solve();
    return 0;
}
//////////////////////

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
