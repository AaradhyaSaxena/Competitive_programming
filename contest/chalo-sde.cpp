/////// Chalo sde

#include<bits/stdc++.h>
#define ll long long
#define fin(x) scanf("%lld",&x)
#define fout(x) printf("%lld\n",x)
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)
#define cases int t;  scanf("%d",&t);   while(t--)
#define MOD 1000000007
#define MAXN 123456
using namespace std;

vector <ll> graph[MAXN];
ll vis[MAXN];

int main()
{
    ll n, m, k;
    fin(n); fin(m); fin(k);
    for(ll i = 0; i < m; i++)
    {
        ll x, y;
        fin(x); fin(y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    priority_queue <ll, vector <ll>, greater<ll> > pq;
    vector <ll> pump;
    for(ll i = 0; i < k; i++)
    {
        ll x;
        fin(x);
        pump.push_back(x);
    }
    ll ans = 0, edges = 0, mx = 0;
    for(auto it : pump)
    {
        ll nodes = 0;
        queue <ll> q;
        q.push(it);
        vis[it] = true;
        while(!q.empty())
        {
            nodes++;
            ll front = q.front();
            q.pop();
            for(auto it : graph[front])
            {
                if(!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        mx = max(mx, nodes);
        ans += nodes * (nodes - 1) / 2;
    }
    ll rem = 0;
    for(ll i = 1; i <= n; i++)
    {
        rem += (!vis[i]);
    }
    for(ll i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            ll ni = 0;
            vis[i] = true;
            queue <ll> q;
            q.push(i);
            while(!q.empty())
            {
                ni++;
                ll front = q.front();
                q.pop();
                for(auto it : graph[front])
                {
                    if(!vis[it])
                    {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            pq.push(ni);
        }
    }
    ans += rem * (rem - 1) / 2;
    ans += mx * rem;
    ans -= m;
    ll cost = 0;
    if(rem == 0)
    {
        printf("%lld %lld\n", ans, cost);
        exit(0);
    }
    pq.push(mx);
    while(!pq.empty()){
        ll n1 = pq.top();    pq.pop();
        if(pq.empty())
            break;
        ll n2 = pq.top();    pq.pop();
        cost += (n1 * n2);
        pq.push(n1 + n2);
    }
    printf("%lld %lld\n", ans, cost);
    return 0;
}


/////////////////////////////
///////////////////////////////














