/// codeforces-664
/// https://codeforces.com/contest/1395

/////// p4
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
using namespace std;

typedef long long ll;
const int maxn = 1e5;
int n, d, m, k, l;
ll a[maxn + 5], b[maxn + 5];

void solve(ll a[], int n) {
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	rep(i, 1, n) a[i] += a[i - 1];
}

int main() {
	scanf("%d %d %d", &n, &d, &m);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		if (x > m) a[++k] = x;
		else b[++l] = x;
	}
	if (k == 0) {
		ll s = 0;
		rep(i, 1, n) s += b[i];
		printf("%lld\n", s);
		exit(0);
	}
	solve(a, k);
	solve(b, l);
	
	fill(b + l + 1, b + n + 1, b[l]);
	ll res = 0;

	rep(i, (k + d) / (1 + d), k){
		if (1ll * (i - 1) * (d + 1) + 1 <= n) {
			res = max(res, a[i] + b[n - 1ll * (i - 1) * (d + 1) - 1]);
		} 
	}
	printf("%lld\n", res);
	return 0;
}	


/////////  p3  /////////////////
////////////////////////////////

#include<bits/stdc++.h>
#define ci const int&
using namespace std;

int n,m,p[210],d[210],ans;

bool Check(ci x){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			if(((p[i]&d[j])|x)==x)
				goto Next;
		return 0;
		Next:;
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=m;++i)scanf("%d",&d[i]);
	ans=(1<<9)-1;
	for(int i=8;i>=0;--i)
		Check(ans^(1<<i)) ? ans ^= (1<<i) : 0;
	printf("%d",ans);
	return 0;
}

////// incorrect
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n,m;
// 	cin>>n>>m;
// 	long long int a[n], b[m];
// 	for(int i=0; i<n; i++){
// 		cin>>a[i];
// 	}
// 	for(int i=0; i<m; i++){
// 		cin>>b[i];
// 		if(b[i]==0){
// 			cout<<0<<endl;
// 			return 0;
// 		}
// 	}
// 	int table[n][m];
// 	memset(table,0,sizeof(table));
// 	for(int i=0; i<n; i++){
// 		for(int j=0; j<m; j++){
// 			table[i][j] = a[i]&b[j];
// 		}
// 	}
// 	int temp = INT_MAX, minn = INT_MAX;
// 	for(int i=n-2; i>=0; i--){
// 		for(int j=0; j<m; j++){
// 			temp = INT_MAX; minn = INT_MAX;
// 			for(int k=0; k<m; k++){
// 				temp = table[i][j]|table[i+1][k];
// 				minn = min(minn,temp);
// 			}
// 			table[i][j] = minn;
// 		}
// 	}
// 	int ans = INT_MAX;
// 	for(int i=0; i<m; i++){
// 		ans = min(ans, table[0][i]);
// 	}
// 	cout<<ans<<endl;
// }


////////////////////////////
////////  p2  //////////////
     
// #include <bits/stdc++.h>
// using namespace std;

// bool visited[100][100];
// int movex[4] = {0,1,0,-1};
// int movey[4] = {1,0,-1,0};
// vector<pair<int,int>> ans;

// bool islegal(int n, int m, int x, int y){
// 	if(x>0 and x<=n and y>0 and y<=m){
// 		return true;
// 	}return false;
// }

// void move(int n,int m,int &x,int &y, int &left){
// 	if(left == 0)
// 		return;
// 	for(int k=1; k<max(n,m); k++){
// 		for(int i=0; i<4; i++){
// 			int X = x + k*movex[i], Y = y + k*movey[i];
// 			if(islegal(n,m,X,Y) and visited[X-1][Y-1]==false){
// 				x = X;
// 				y = Y;
// 				visited[x-1][y-1] = true;
// 				ans.push_back({x,y});
// 				left--;
// 				move(n,m,x,y,left);
// 			}
// 		}
// 	}
// 	if(left !=0){
// 		ans.pop_back();
// 	}
// }

// int main(){
// 	int n,m,x,y,t;
// 	cin>>n>>m>>x>>y;
// 	t = n*m;
// 	memset(visited, false, sizeof(visited));
// 	visited[x-1][y-1] = true;
// 	cout<<x<<" "<<y<<endl;
// 	int left = n*m -1;
// 	move(n,m,x,y,left);

// 	if(left==0){
// 		for(int i=0; i<ans.size(); i++){
// 			cout<<ans[i].first<<" "<<ans[i].second<<endl;
// 		}
// 	}
// }


///////////////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// bool checkP(int r, int g, int b, int w){
// 	int nodd = 0, neven = 0;
// 	if(r%2==0){
// 		neven++;
// 	}else{
// 		nodd++;
// 	}
// 	if(g%2==0){
// 		neven++;
// 	}else{
// 		nodd++;
// 	}
// 	if(b%2==0){
// 		neven++;
// 	}else{
// 		nodd++;
// 	}
// 	if(w%2==0){
// 		neven++;
// 	}else{
// 		nodd++;
// 	}
// 	if(nodd==1 and neven==3){
// 		return true;
// 	}
// 	if(nodd==0){
// 		return true;
// 	} 
// 	return false;
// }

// int main(){
// 	int t; 
// 	cin>>t;
// 	while(t--){
// 		long long int r,g,b,w;
// 		cin>>r>>g>>b>>w;
// 		if(checkP(r,g,b,w)){
// 			cout<<"YES"<<endl;
// 		}else{
// 			if(r>0 and g>0 and b>0){
// 				if(checkP(r-1,g-1,b-1,w+3)){
// 					cout<<"YES"<<endl;
// 				}else{
// 					cout<<"NO"<<endl;
// 				}
// 			}else{
// 				cout<<"NO"<<endl;
// 			}
// 		}
// 	}
// }


