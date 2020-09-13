//////////https://codeforces.com/contest/1406/problem/C

///// Centroid of a tree

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, size[100005], fa[100005], minn=1e9, cent1, cent2;
vector<int> g[100005];

void dfs(int x, int f){
    fa[x] = f, size[x] = 1;
    int mx = 0;
    for(int y:g[x]){
        if(y == f) continue;
        dfs(y,x);
        size[x] += size[y];
        mx = max(mx, size[y]);
    }
    mx = max(mx, n-size[x]);
    if(mx < minn) minn = mx, cent1 = x, cent2 = 0;
    else if(mx == minn) cent2 = x;
}

int S;

void dfs2(int x, int f){
    if(g[x].size() == 1){
        S = x;
        return ;
    }
    for(int y:g[x]){
        if(y == f) continue;
        dfs2(y,x);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n,cent1=cent2=0,minn=1e9;
        for(int i=1; i <= n; i++) g[i].clear(),fa[i]=0;
        for(int i=1; i<n; i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y), g[y].push_back(x);
        }
        dfs(1,0);
        if(!cent2){
            printf("1 %d\n1 %d\n",g[1][0],g[1][0]);
            continue;
        }
        if(fa[cent1] != cent2) swap(cent1, cent2);
        dfs2(cent1, cent2);
        printf("%d %d\n%d %d\n",S,fa[S],S,cent2);
    }
    return 0;
}

















////////////////////////////
////////////////////////////

#include <bits/stdc++.h> 
using namespace std; 
  
#define MAXN 1025 
  
vector<int> tree[MAXN]; 
vector<int> centroidTree[MAXN]; 
bool centroidMarked[MAXN]; 
  
/* method to add edge between to nodes of the undirected tree */
void addEdge(int u, int v) 
{ 
    tree[u].push_back(v); 
    tree[v].push_back(u); 
} 
  
/* method to setup subtree sizes and nodes in current tree */
void DFS(int src, bool visited[], int subtree_size[], int* n) 
{ 
    /* mark node visited */
    visited[src] = true; 
  
    /* increase count of nodes visited */
    *n += 1; 
  
    /* initialize subtree size for current node*/
    subtree_size[src] = 1; 
  
    vector<int>::iterator it; 
  
    /* recur on non-visited and non-centroid neighbours */
    for (it = tree[src].begin(); it!=tree[src].end(); it++) 
        if (!visited[*it] && !centroidMarked[*it]) 
        { 
            DFS(*it, visited, subtree_size, n); 
            subtree_size[src]+=subtree_size[*it]; 
        } 
} 
  
int getCentroid(int src, bool visited[], int subtree_size[], int n) 
{ 
    /* assume the current node to be centroid */
    bool is_centroid = true; 
  
    /* mark it as visited */
    visited[src] = true; 
  
    /* track heaviest child of node, to use in case node is  
       not centroid */
    int heaviest_child = 0; 
  
    vector<int>::iterator it; 
  
    /* iterate over all adjacent nodes which are children  
       (not visited) and not marked as centroid to some  
       subtree */
    for (it = tree[src].begin(); it!=tree[src].end(); it++) 
        if (!visited[*it] && !centroidMarked[*it]) 
        { 
            /* If any adjacent node has more than n/2 nodes, 
             * current node cannot be centroid */
            if (subtree_size[*it]>n/2) 
                is_centroid=false; 
  
            /* update heaviest child */
            if (heaviest_child==0 || 
                subtree_size[*it]>subtree_size[heaviest_child]) 
                heaviest_child = *it; 
        } 
  
    /* if current node is a centroid */
    if (is_centroid && n-subtree_size[src]<=n/2) 
        return src; 
  
    /* else recur on heaviest child */
    return getCentroid(heaviest_child, visited, subtree_size, n); 
} 
  
/* function to get the centroid of tree rooted at src. 
 * tree may be the original one or may belong to the forest */
int getCentroid(int src) 
{ 
    bool visited[MAXN]; 
    int subtree_size[MAXN]; 
  
	// initialize auxiliary arrays 
    memset(visited, false, sizeof visited); 
    memset(subtree_size, 0, sizeof subtree_size); 
  
	// variable to hold number of nodes in the current tree 
    int n = 0; 
  
	// DFS to set up subtree sizes and nodes in current tree 
    DFS(src, visited, subtree_size, &n); 
  
    for (int i=1; i<MAXN; i++) 
        visited[i] = false; 
  
    int centroid = getCentroid(src, visited, subtree_size, n); 
  
    centroidMarked[centroid]=true; 
  
    return centroid; 
} 
  
/* function to generate centroid tree of tree rooted at src */
int decomposeTree(int root) 
{ 
    // get Centorid for current tree 
    int cend_tree = getCentroid(root); 
    printf("%d ", cend_tree); 
  
    vector<int>::iterator it; 
  
    // for every node adjacent to the found centroid and not already marked as centroid 
    for (it = tree[cend_tree].begin(); it != tree[cend_tree].end(); it++) 
    { 
        if (!centroidMarked[*it]) 
        { 
            // decompose subtree rooted at adjacent node 
            int cend_subtree = decomposeTree(*it); 
  
            // add edge between tree centroid and centroid of subtree 
            centroidTree[cend_tree].push_back(cend_subtree); 
            centroidTree[cend_subtree].push_back(cend_tree); 
        } 
    } 
  
    /* return centroid of tree */
    return cend_tree; 
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, x, y; 
    	cin>>n;
    	int arr[n][2];
    	vector<vector<int>> gr;
    	for(int i=0; i<n; i++){
    		cin>>x>>y;
    		arr[i][0] = x;
    		arr[i][1] = y;
    		gr[x].push_back(y);
    		gr[y].push_back(x);
    	}
    	int dp[n] = {0};
    	// helepr(gr,dp,1);
    	decomposeTree(1); 

    }
    return 0;
}
  
// // driver function 
// int main() 
// { 
//     /* number of nodes in the tree */
//     int n = 16; 
  
//     /* arguments in order: node u, node v 
//      * sequencing starts from 1 */
//     addEdge(1, 4); 
//     addEdge(2, 4); 
//     addEdge(3, 4); 
//     addEdge(4, 5); 
//     addEdge(5, 6); 
//     addEdge(6, 7); 
//     addEdge(7, 8); 
//     addEdge(7, 9); 
//     addEdge(6, 10); 
//     addEdge(10, 11); 
//     addEdge(11, 12); 
//     addEdge(11, 13); 
//     addEdge(12, 14); 
//     addEdge(13, 15); 
//     addEdge(13, 16); 
  
//     /* generates centroid tree */
//     decomposeTree(1); 
  
//     return 0; 
// }