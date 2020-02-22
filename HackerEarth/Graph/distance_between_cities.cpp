////// https://www.hackerearth.com/problem/algorithm/pillow-the-robot-ed88f955/description/

#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 6e5 + 10;
const int EXP = 22;
int n, q, u, v, k, x[MAX + 1], dep[MAX + 1], res;
vector <int> adj[MAX + 1];
vector <int> euler;
vector <int> depthArr;
int FAI[MAX + 1];
int level[MAX + 1];
int ptr;
int dp[MAX + 1][EXP];
int logn[MAX + 1];
int p2[EXP];
     
void buildSparseTable(int n) { 
    memset(dp, -1, sizeof(dp)); 
    for (int i = 1; i < n; ++i) 
        dp[i-1][0] = (depthArr[i] > depthArr[i-1])?i-1:i;
    for (int l=1; l < EXP; ++l)
    for (int i=0; i < n; ++i)
    if (dp[i][l-1] != -1 && dp[i + p2[l - 1]][l - 1] != -1) 
    dp[i][l] = 
    (depthArr[dp[i][l-1]] > depthArr[dp[i+p2[l-1]][l-1]]) ?
            dp[i+p2[l-1]][l-1] : dp[i][l-1]; 
            else
            break; 
} 
      
int query(int l,int r) { 
    int d = r - l; 
    int dx = logn[d]; 
    if (l == r) return l; 
    if (depthArr[dp[l][dx]] > depthArr[dp[r - p2[dx]][dx]]) 
        return dp[r - p2[dx]][dx]; 
    else
        return dp[l][dx]; 
} 
  
void preprocess() {
    p2[0] = 1; 
    for (int i = 1; i < EXP; ++i) 
        p2[i] = p2[i - 1] * 2; 
    int val = 1, ptr = 0; 
    for (int i = 1; i <= MAX; ++i) { 
        logn[i] = ptr-1; 
        if (val == i) { 
            val *= 2; 
            logn[i] = ptr; 
            ++ptr;
        } 
    } 
}
 
void visit(int cur = 1, int prev = 0) {
    if (FAI[cur] == -1) 
        FAI[cur] = ptr; 
    level[cur] = dep[cur];
    euler.push_back(cur); 
    ++ptr;
    for (auto x : adj[cur]) {
        if (x != prev) {
            dep[x] = dep[cur] + 1;
            visit(x, cur);
            euler.push_back(cur);
            ++ptr; 
        } 
    } 
}
     
void makeArr() { 
    for (auto x : euler) 
        depthArr.push_back(level[x]); 
} 
      
int LCA(int u,int v) {
    if (u == v) 
       return u; 
    if (FAI[u] > FAI[v]) 
       swap(u,v); 
    return euler[query(FAI[u], FAI[v])]; 
}
     
int getDistance(const int& u, const int& v) {
    int commonPar = LCA(u, v);
    return dep[u] + dep[v] - (dep[commonPar] << 1);
}
     
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess();
    ptr = 0; 
    memset(FAI,-1,sizeof(FAI)); 
    visit();
    makeArr(); 
    buildSparseTable(depthArr.size());
     
    while (q--) {
        scanf("%d", &k);
        for (int i = 1; i <= k; ++i)
            scanf("%d", x + i);
        res = -1;
        u = x[1];
        for (int i = 2; i <= k; ++i) {
            int dis = getDistance(x[1], x[i]);
            if (res < dis) {
                res = dis;
                u = x[i];
            }
        }
     
        res = 0;
        for (int i = 1; i <= k; ++i)
            res = max(res, getDistance(u, x[i]));
     
        res = (res + 1) >> 1;
        printf("%d\n", res);
    }
    return 0;
}