/////// Deutsche Bank

/////////////////////////
//// A digit or a letter

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int num1 = 0, num2 = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ) num2++;
        else if (s[i] <= '9' && s[i] >= '0') num1++;
    }
    cout << num1 << "\n" << num2 << "\n";
    return 0;
}

//////////////////////////
///// Maximum difference



////////////////////////
//// Two divisors

#include<bits/stdc++.h>
using namespace std;

int divv[1000007];

void initialize() { 
	for(int i=1; i<1000001; i++){
		divv[i] = 0;
	}
    for(int i=1; i<1000001; i++){
		for(int j=i; j<1000001; j+=i){
			divv[j] += 1;
		}
	}
} 

int main(){
	int n; cin>>n;
	int arr[n];
	int dp[n+1] = {0};
	initialize();
	for(int i=1; i<=n; i++){
		cin>>arr[i-1];
		int x = divv[arr[i-1]];
		if((x!=0  and (x&(x-1))==0) or x==1){
			dp[i] = dp[i-1]+1;
		}
		else{
			dp[i] = dp[i-1];
		}
	}
	for(int i=1; i<=n; i++){
		cout<<dp[i]<<" ";
	}cout<<endl;
}

//////////////////////////
//////// Optimum jump

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll nn; cin>>nn;
	ll arrr[nn];
	for(int i=0; i<nn; i++){
		cin>>arrr[i];
	}
	ll dp[nn+3];
	dp[0] = arrr[0];
	if(nn==1 or nn==2){
		cout<<dp[0]<<endl;;
	}
	else{
		dp[1] = dp[0]+arrr[1]+arrr[2];
		for(int i=2; i<nn; i++){
			if(i==nn-1){
				dp[i] = dp[i-2]+arrr[i];
			}
			else{
				dp[i] = min(dp[i-2]+arrr[i], dp[i-1]+arrr[i+1]+arrr[i]);
			}
		}
		cout<< min(dp[nn-1],dp[nn-2])<<endl;
	}
	return 0;
}

////////////////////////
/////// array reduction

#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	cin >> n;
	fo(i, n) cin >> a[i+1];
	sort(a+1, a+1+n);
	int lo = 0;
	Fo(i, 1, 1+n){
		a[i] += a[i-1];
		if(a[i+1] <= 2*a[i]);
		else lo = i;
	}
	cout << n-lo << endl;

	return 0;
}

/////////////////////
////// vis nodes

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Connection
{
    int corr;
    int pr;
    int dis;
};
bool CompConn(Connection a, Connection b)
{
    if (a.pr != b.pr )
        return a.pr > b.pr;

    return (a.dis < b.dis);
}
vector <Connection> adj[1000001]; //adjacency list
int vis[1000001]; //array for maintaining visited cities
ll Rtime[1000001]; //final answer for or Time to reach each of the cities

int main()
{
    int n,m,u,v,d;
    cin>>n>>m; //input for n and m
    int *p = new int[n+1]; //priority values
    for(int i=1; i<=n; i++)
        cin>>p[i];
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>d;
        adj[u].push_back({v,p[v],d});
        adj[v].push_back({u,p[u],d});
    }

    for(int i=0; i<=n; i++)
    {
        sort(adj[i].begin(),adj[i].end(),CompConn); //sorting the adjacency list according to priority and distance using CompConn
        reverse(adj[i].begin(),adj[i].end());
    }
    int nv = 0,curr=0;
    ll te=0;
    memset(Rtime,0,sizeof Rtime);
    memset(vis,0,sizeof vis);
    vis[0] = 1;
    stack < pair<int,int> > st; //stack for maintaing previous visited cities
    st.push({0,adj[0][0].dis});
    while(nv<n)   //loop until we have not visited all the N cities
    {
        int curr1 = curr;
        while(adj[curr].size()!=0)
        {
            if(!vis[adj[curr].back().corr])
            {
                st.push({curr,adj[curr].back().dis});
                te += adj[curr].back().dis;
                curr = adj[curr].back().corr;
                Rtime[curr] = te;
                nv++;
                vis[curr]=1;
                adj[curr1].pop_back();
                break;
            }
            else
            {
                adj[curr].pop_back();
            }
        }
        if(curr1 == curr)
        {
            curr = st.top().first;
            te += st.top().second;
            st.pop();
        }
    }
    for(int i=1; i<=n; i++)
        cout<<Rtime[i]<<" "; //output visiting time for all the n cities


    return 0;
}

/////////////////
///// two num

#include<bits/stdc++.h>
using namespace std;



int main() {

    long long n;
    int t;
    cin>>t;
    
    while(t--){

    
    cin>>n;
    long long  p  = ceil(sqrt(n));
    if(p*(p-1)>=n)

    cout<<(2*p-1)<<"\n";
    else
    cout<<2*p<<"\n";

    }
}

////////////////////
/////// parent node

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define M 1000000007
#define N 1000016
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define f first
#define s second
#define inf 9000000000000000000
vector<ll> adj[N], v[N];
ll val[N],sub[N],vis[N];

void dfs()
{
    stack<pair<ll, ll>> stac;
    stack<ll> st[26];
    stac.push({1, 0});
    while(!stac.empty())
    {
        while(!stac.empty() && vis[stac.top().f])
        {
            st[val[stac.top().f]].pop();
            stac.pop();
        }
        if(stac.empty())
            break;
        ll x = stac.top().f;
        ll par = stac.top().s;
        vis[x] = 1;
        if(!st[val[x]].empty())
        {
            v[x].push_back(st[val[x]].top());
            v[st[val[x]].top()].push_back(x);
        }

        st[val[x]].push(x);
        for(auto node: adj[x])
        {
            if(node==par)
                continue;
            stac.push({node, x});
        }
    }
}

void dfs2(ll x)
{
    stack<pair<ll, ll>> stac;
    stac.push({x, 0});
    while(!stac.empty())
    {
        while(!stac.empty() && vis[stac.top().f])
        {
            x = stac.top().f;
            sub[x] = 1;
            for(auto node: v[x])
                sub[x] += sub[node];

            stac.pop();
        }

        if(stac.empty())
            break;
        x = stac.top().f;
        ll par = stac.top().s;
        vis[x] = 1;

        for(auto node: v[x])
        {
            if(node==par)
                continue;
            stac.push({node, x});
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            adj[i].clear();
            v[i].clear();
            sub[i] = 0;
            vis[i] = 0;
        }

        char s;
        for(i=1; i<=n; i++)
        {
            cin>>s;
            val[i] = s - 'a';
        }
        for(i=1; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs();
        fill(vis, vis+n+1, 0);
        for(i=1; i<=n; i++)
        {
            if(!vis[i])
                dfs2(i);
        }
        for(i=1; i<=n; i++)
            cout<<sub[i]<<" ";
        cout<<"\n";
    }

    return 0;
}

/////////////


















