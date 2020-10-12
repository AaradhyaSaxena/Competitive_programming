////// DSU

///// https://www.hackerrank.com/challenges/components-in-graph/problem

#include<stdio.h>
#define MAXN   100005

int par[MAXN], sz[MAXN];
/*
    par[i] = parent of the i-th node
    sz[i]  = size of the component which is being represented by the i-th node
*/

void init(int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int findParent(int idx)
{
    if(par[idx] == idx) return idx;
    return par[idx] = findParent(par[idx]);
}

void Union(int u, int v)
{
    int par_u = findParent(u);
    int par_v = findParent(v);

    if(par_u == par_v) return;

    par[par_u] = par_v;     // updating the parent of the new component
    sz[par_v] += sz[par_u]; // updating the size of the new component
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int i, j, k, n, cur_sz;
    int u, v, mx = 0, mn = MAXN;

    scanf("%d", &n);
    init(2*n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d %d", &u, &v);
        Union(u, v);
    }

    for(i = 1; i <= 2*n; i++)
    {
        cur_sz = sz[findParent(i)];
        if(cur_sz > mx) mx = cur_sz;
        if(cur_sz > 1 && cur_sz < mn) mn = cur_sz;
    }

    printf("%d %d\n", mn, mx);
    return 0;
}
///////////

////////////////////
//////////////////////////////
///////////////https://www.hackerrank.com/challenges/kundu-and-tree/problem

///// Branches with colour

#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define s(a) scanf("%d",&a);

vector<int> edges[100009];
long long int visited[100009];
long long int  count1[100009];
long long int B[100009],C[100009],D[100009];

void dfs(int x, int temp)
{
    if(visited[x] == 0)
        visited[x] = temp;
    for(int i = 0 ; i< edges[x].size() ; i++)
    {
        if(visited[edges[x][i]] == 0)
            dfs(edges[x][i],temp);
    }
    return;
}

int main()
{
    int n,i,a,b;
    char c;
    s(n);
    for(i=0 ; i< n -1 ; i++)
    {
        s(a);
        s(b);
        cin>>c;
        if( c != 'r')
        {
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
    }
    int temp = 1;
    for(i=1 ; i<=n ; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i,temp);
            temp++;
        }
    }
    for(i=1 ; i<= n ; i++)
        count1[visited[i]]++;   
    long long int sum = 0;

    B[n-1] = count1[n];
    for(i=n-2;i>=0;i--) 
    	B[i] = (B[i+1] + count1[i+1])%MOD;
    for(i=1;i<n-1;i++) 
    	C[i] = (count1[i+1]*B[i+1])%MOD;

    D[n-2] = C[n-2];
    for(i=n-3;i>=1;i--) 
    	D[i] = (D[i+1] + C[i])%MOD;

    for(i=0;i<n-2;i++) 
    	sum = (sum + count1[i+1]*D[i+1])%MOD;

    cout<< ( MOD + sum )%MOD<<endl; 
    return 0;
}

/*

If there is a red edge between vertex 'a' and 'b' then if we delete the red edge 
then vertex a and b will lie on different comonenet of the tree. 
So, if we delete all of the red edges in the tree. 
All the three vertices i.e. a, b and c will have to lie of different disconnected components.
So, when you are scanning the tree and got that color of some edge is red, 
don't scan it and make forest i.e. disconnected tree.
Consider that size of these components are a1, a2, a3,.... , ak.

So we have to pick three vertices out of given k disconnected component which can be done in S number of ways.
*/


///////////////
/////////////
////////////////