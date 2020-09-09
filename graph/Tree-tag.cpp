//////////https://codeforces.com/contest/1405/problem/D
///// https://codeforces.com/blog/entry/82366 >> solution

///// tree tag

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a, b, da, db, depth[N];
vector<int> adj[N];
int diam = 0;
 
int dfs(int x, int p) {
    int len = 0;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = depth[x] + 1;
            int cur = 1 + dfs(y, x);
            diam = max(diam, cur + len);
            len = max(len, cur);
        }
    }
    return len;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int te;
    cin >> te;
    while(te--) {
        cin >> n >> a >> b >> da >> db;
        for(int i = 1; i <= n; i++) 
        	adj[i].clear();
        
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        diam = 0;
        depth[a] = 0;
        dfs(a, -1);

        if(2 * da >= min(diam, db) || depth[b] <= da){
        	cout <<"Alice"<<endl;
        }else{
        	cout <<"Bob"<<endl;
        }
    }
}


/*

Let's consider several cases independently.

Case 1: dist(𝑎,𝑏) ≤ 𝑑𝑎

Unsurprisingly, Alice wins in this case by tagging Bob on the first move.

Case 2: 2𝑑𝑎 ≥ tree diameter

Here, the diameter of a tree is defined as the length of the longest simple path.
In this case, Alice can move to a center of the tree. 
Once Alice is there, it doesn't matter where Bob is, 
since Alice can reach any vertex in the tree in just one move, winning the game.

Case 3: 𝑑𝑏 > 2𝑑𝑎

In this case, let's describe a strategy for Bob to win. 
Because we are not in case 1, Bob will not lose before his first move. 
Then it is sufficient to show that Bob can always end his turn with distance greater than 𝑑𝑎 from Alice.
Since we are not in case 2, there is at least one vertex with distance at least 𝑑𝑎 from Alice. 
If Bob is at such a vertex at the start of his turn, he should simply stay there. 
Otherwise, there is some vertex 𝑣 with dist(𝑎,𝑣) = 𝑑𝑎+1. 
Then dist(𝑏,𝑣) ≤ dist(𝑏,𝑎) + dist(𝑎,𝑣) ≤ 𝑑𝑎 + (𝑑𝑎+1) = 2𝑑𝑎 + 1 ≤ 𝑑𝑏, so Bob can jump to 𝑣 on his turn.

Case 4: 𝑑𝑏 ≤ 2𝑑𝑎

In this case, Alice's strategy will be to capture Bob whenever possible or move one vertex closer to Bob otherwise. 
Let's prove that Alice will win in a finite number of moves with this strategy.
Let's root the tree at 𝑎. Bob is located in some subtree of 𝑎, say with 𝑘 vertices. 
Alice moves one vertex deeper, decreasing Bob's subtree size by at least one vertex. 
Since 𝑑𝑏 ≤ 2𝑑𝑎 , Bob cannot move to another subtree without being immediately captured, 
so Bob must stay in this shrinking subtree until he meets his inevitable defeat.

Solution
The only non-trivial part in the implementation is checking for cases 1 and 2. 
Case 1 is simply checked with DFS. 
Case 2 only requires computing the diameter of the tree, which is a standard problem.
Complexity is 𝑂(𝑛).

*/