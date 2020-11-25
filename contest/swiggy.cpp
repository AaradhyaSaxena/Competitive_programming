///////////////////

////// SWIGGY

// Count number of occurrences (or frequency) in a sorted array

#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r < l) 
        return -1; 
    int mid = l + (r - l) / 2; 
    if (arr[mid] == x) 
        return mid; 
    if (arr[mid] > x) 
        return binarySearch(arr, l, mid - 1, x); 
    return binarySearch(arr, mid + 1, r, x); 
} 
  
int countOccurrences(int arr[], int n, int x){ 
    int ind = binarySearch(arr, 0, n - 1, x); 
    if (ind == -1) return 0; 
  
    int count = 1; 
    int left = ind - 1; 
    while (left >= 0 && arr[left] == x) 
        count++, left--; 
  
    int right = ind + 1; 
    while (right < n && arr[right] == x) 
        count++, right++; 
  
    return count; 
} 
  
int main() { 
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 }; 
    int n = sizeof(arr) / sizeof(arr[0]), x = 2; 
    cout << countOccurrences(arr, n, x); 
    return 0; 
}

////////////////
////////////////

//////// stocks buy and sell

#include <bits/stdc++.h>
using namespace std;
 
void stockBuySell(int price[], int n)
{
    if (n == 1)
        return;
 
    int i = 0;
    while (i < n - 1) {
        while( (i < n - 1) && (price[i + 1] <= price[i]) ){
            i++;
        }
        if (i == n - 1) break;
        int buy = i++;

        while ((i < n) && (price[i] >= price[i - 1])){
            i++;
        }
        int sell = i - 1;
        cout << "Buy on day: " << buy << "\t Sell on day: " << sell << endl;
    }
}
 
int main(){
    int price[] = { 100, 180, 260, 310, 40, 535, 695 };
    int n = sizeof(price) / sizeof(price[0]);
 	stockBuySell(price, n);
    return 0;
}

/////////////////
//////////////////////

//// distinct substrings

#include<bits/stdc++.h>
using namespace std;

void printAllSubstrings(string s, int n) 
{
    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
            printf("%s\n", temp);
        }
    }
}
 
int main() 
{
    string s = "Geeky";
    printAllSubstrings(s, s.length());
    return 0;
}

///////////////
/////////////////////////
//// is cicular


bool isCircular(char path[]) 
{ 
  int x = 0, y = 0; 
  int dir = N; 
  
  for (int i=0; path[i]; i++) 
  { 
      char move = path[i]; 
      if (move == 'R') 
        dir = (dir + 1)%4; 
      else if (move == 'L') 
        dir = (4 + dir - 1)%4; 
  
     else // if (move == 'G') 
    { 
         if (dir == N) y++; 
         else if (dir == E) x++; 
         else if (dir == S) 
            y--; 
         else // dir == W 
            x--; 
      } 
  } 
  
   // If robot comes back to (0, 0), then path is cyclic 
  return (x == 0 && y == 0); 
} 
  
// Driver program 
int main() 
{ 
    char path[] = "GLGLGLG"; 
    if (isCircular(path)) 
      cout << "Given sequence of moves is circular"; 
    else
      cout << "Given sequence of moves is NOT circular"; 
} 

/////////////////////////
////////////////////////
//////  parser

/*
def validString(arr):
  isNum = False
  count = 0

  strArray = arr.split(' ')
  operators = ['plus','minus','times','div']
  for i in strArray:
    count +=1 

  if i in operators:
    if not isNum:
      return 'ERR'
    else :
      isNum = False  
  else :
    if isNum and i.isdigit() and count <2:
      return 'ERR'
    else :
      isNum = True  
  if count == 2:
    count = 0    
  return 'OK'
  print(validString('1 plus 2'))
*/

//////////////////
/// road repairing

#include <bits/stdc++.h>
using namespace std;

int fa[100010];

int findfa(int x) {
    return x == fa[x] ? x : fa[x] = findfa(fa[x]);
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i) fa[i] = i;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++ i) {
        int u, v;
        cin >> u >> v;
        int x = findfa(u), y = findfa(v);
        if (x != y) fa[x] = y;
    }

    int cc = 0;
    for (int i = 1; i <= n; ++ i) if (findfa(i) == i) ++ cc;

    cin >> m;
    for (int i = 0; i < m; ++ i) {
        int u, v;
        cin >> u >> v;
        int x = findfa(u), y = findfa(v);
        if (x != y) fa[x] = y;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) if (findfa(i) == i) ++ cnt;

    if (cnt > 1) cout << -1 << endl;
    else cout << cc - 1 << endl;

    return 0;
}

////////////////////////
// food delivery service

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)1e9 + 123;
const ll infl = (ll)1e18 + 123;
const int MAX_N = (int)1e6 + 123;

void check(int x, int l, int r) {
    assert(x >= l && x <= r);
}

int cnt[MAX_N];
queue < int > q;

vector < int > dig;

int F(int x) {
    dig.clear();
    while(x) {
        dig.pb(x % 10);
        x /= 10;
    }
    sort(dig.begin(), dig.end());
    reverse(dig.begin(), dig.end());
    int res = 0;
    for (auto i : dig) {
        res = res * 10 + i;
    }
    return res;
}

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    check(n, 1, (int)1e6);
    check(x, 1, n);
    
    memset(cnt, -1, sizeof cnt);
    cnt[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if (v + 1 <= n && cnt[v + 1] == -1) {
            cnt[v + 1] = cnt[v] + 1;
            q.push(v + 1);
        } if (v > 1 && cnt[v - 1] == -1) {
            cnt[v - 1] = cnt[v] + 1;
            q.push(v - 1);
        } if (v * 2 <= n && cnt[2 * v] == -1) {
            cnt[2 * v] = cnt[v] + 1;
            q.push(2 * v);
        } if (v % 2 == 0 && cnt[v / 2] == -1) {
            cnt[v / 2] = cnt[v] + 1;
            q.push(v / 2);
        }
        
        int u = F(v);
        if (u <= n && cnt[u] == -1) {
            cnt[u] = cnt[v] + 1;
            q.push(u);
        }
    }
    printf("%d\n", cnt[x]);
}

int main() {
#ifdef DEBUG
    freopen("input.txt","r", stdin);
#endif
    int numberOfTests;
    scanf("%d", &numberOfTests);
    check(numberOfTests, 1, (int)1e6);
    while(numberOfTests--)
        solve();
    return 0;
}

///////////////////
/// mohit and swiggy

#include <unordered_set>
using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)1e9 + 123;
const ll infl = (ll)1e18 + 123;
const int MAX_N = (int)1e6 + 123;

void check(int x, int l, int r) {
    assert(x >= l && x <= r);
}

int n, m;
vector < pi > g[MAX_N];
vector < pair < int, pi > > edges;

int pr[MAX_N], h[MAX_N];

void init() {
    for (int i = 0; i <= n; i++) {
        pr[i] = i;
        h[i] = 0;
    }
}

int getParent(int v) {
    if (v == pr[v])
        return v;
    return pr[v] = getParent(pr[v]);
}

bool unionSets(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b)
        return 0;
    if (h[a] < h[b])
        swap(a, b);
    pr[b] = a;
    h[a] += (h[a] == h[b]);
    return 1;
}

map < pi, bool > used;

int main() {
#ifdef DEBUG
    freopen("input.txt","r", stdin);
#endif
    scanf("%d%d", &n, &m);
    check(n, 1, (int)5e5);
    check(m, n, (int)1e6);
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        check(u, 0, n);
        check(v, 0, n);
        check(w, 1, (int)1e4);
        if (u > v)
            swap(u, v);
        if (used[mp(u, v)] == 1)
            assert(0);
        
        used[mp(u, v)] = 1;
        edges.pb(mp(w, mp(u, v)));
    }
    sort(edges.begin(), edges.end());
    init();
    
    int ans = 0, cnt = 0;
    for (auto i : edges) {
        if (unionSets(i.s.first, i.s.second)) {
            ans += i.f;
            cnt++;
        }
    }
    
    assert(cnt == n);
    printf("%d\n", 2 * ans);
    return 0;
}

/////////////////
/////////////////////




























============================




