//////// codeforces 660

///// p4

/////// topological_sort

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;

// T = []
// visited = []

// topological_sort( cur_vert, N, adj[][] ){
//     visited[cur_vert] = true
//     for i = 0 to N
//         if adj[cur_vert][i] is true and visited[i] is false
//         topological_sort(i)
//     T.insert_in_beginning(cur_vert)
// }

     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//     	int n;
//     	cin>>n;
//     	int arr[n], b[n];
//     	for(int i=0; i<n; i++){
//     		cin>>a[i];
//     	}
//     	for(int j=0; j<n; j++){
//     		cin>>b[i];
//     	}
//     	int ans = 0;
//     	int dp[n];
//     	for(int i=0; i<n; i++){
//     		dp[i] = 0;
//     	}

//     	for(int i=n-1; i>=0; i--){
//     		int temp = a[i];
//     		if(b[i]==-1){
//     			dp[i] = temp;
//     			continue;
//     		}
//     		for(int j=i+1; j<n; j++){
//     			int index = ;

//     		}
//     	}
//     }
//     return 0;
// }

/////////////////////////
/////////////////////////
#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()

using namespace std;

vector <vector <int> > edge;
vector <ll> a;
vector <int> b, used;
vector <int> order[2];
ll ans;
inline void dfs (int v) {
    used[v] = 1;
    for (int to : edge[v]) {
        if (!used[to]) dfs(to);
    }
    ans += a[v];
    if (b[v] != -1 && a[v] > 0) {
        a[b[v]] += a[v];
    }
    if (a[v] > 0) {
        order[0].push_back(v);
    }
    else {
        order[1].push_back(v);
    }
}
inline void solve () {
    for (auto &i : edge) i.clear();
    edge.clear();
    a.clear();
    order[0].clear();
    order[1].clear();
    b.clear();
    used.clear();
    int n, x;
    cin >> n;
    edge.resize(n);
    a.resize(n);
    b.resize(n);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != -1) {
            --x;
            edge[x].push_back(i);
        }
        b[i] = x;
    }
    ans = 0;
    used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << ans << '\n';
    reverse(all(order[1]));
    for (auto &i : order[0]) cout << i + 1 << ' ';
    for (auto &i : order[1]) cout << i + 1 << ' ';
    cout << '\n';
}
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}



//// p3

///// dfs

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

vector < int > gr[N];
bool access = true;

int p[N], h[N], a[N], g[N];

void dfs(int v, int ancestor = -1) {
    a[v] = p[v];
    int sum_g = 0;
    for (int to : gr[v]) {
        if (to == ancestor) continue;
        dfs(to, v);
        sum_g += g[to];
        a[v] += a[to];
    }
    if ((a[v] + h[v]) % 2 == 0) {} // first
    else access = false;
    g[v] = (a[v] + h[v]) / 2;
    if (g[v] >= 0 && g[v] <= a[v]) {} // second
    else access = false;
    if (sum_g <= g[v]) {} // third
    else access = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> h[i];
        for (int i = 0; i < n - 1; ++i) {
            int a, b; cin >> a >> b;
            --a, --b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(0);
        cout << (access ? "YES" : "NO") << endl;
        access = true;
        for (int i = 0; i < n; ++i) gr[i].clear();
    }
}


/////// p2

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
    	int n;
    	cin>>n;
    	string s1 = "";
    	if(n%4==0)
    	{
    		for(int i=0; i<n-(n/4); i++){
    			s1 += "9";
    		}for(int i=0; i<n/4; i++){
    			s1 += "8";
    		}
    	}
    	else
    	{
    		for(int i=0; i<n-(n/4)-1; i++){
    			s1 += "9";
    		}
    		s1 += "8";
    		for(int i=0; i<n/4; i++){
    			s1 += "8";
    		}
    	}
    	cout<<s1<<endl;
    }
    return 0;
}

///////// p1

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
    	int n;
    	cin>>n;
    	if(n<31){
    		cout<<"NO"<<endl;
    	}else{
    		if(n==36){
    			cout<<"YES"<<endl;
    			cout<<"6 10 15 5"<<endl;
    		}
    		else if(n==40){
    			cout<<"YES"<<endl;
    			cout<<"6 10 15 9"<<endl;
    		}
    		else if(n==44){
    			cout<<"YES"<<endl;
    			cout<<"6 10 15 13"<<endl;
    		}
    		else{
    			cout<<"YES"<<endl;
    			cout<<"6 10 14 "<<n-30<<endl;	
    		}
    	}
    }
    return 0;
}


////////

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




