/////////https://codeforces.com/contest/1398

///// p1
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// 	int t; 
// 	cin>>t;
// 	while(t--){
// 		int n; 
// 		cin>>n;
// 		int arr[n];
// 		for(int i=0; i<n; i++){
// 			cin>>arr[i];
// 		}
// 		if (arr[0] + arr[1] <= arr[n-1]) {
// 			cout<<1<<" "<<2<<" "<<n<<endl; 
// 		}else{
// 			cout<<-1<<endl;
// 		}
// 	}
// }

// //// p2
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
// 	int t; 
// 	cin>>t;
// 	while(t--){
// 		string s;
// 		cin>>s;
// 		vector<int> vec;
// 		int i = 0, n = s.length(), cnt = 0, ans=0;
// 		while(i<n){
// 			if(s[i]=='1'){
// 				cnt++;
// 			}
// 			if(s[i]=='0'){
// 				vec.push_back(cnt);
// 				cnt = 0;
// 			}
// 			i++;
// 		}
// 		if(cnt!=0){
// 			vec.push_back(cnt);
// 		}
// 		sort(vec.begin(), vec.end());
// 		for(int i=vec.size()-1; i>=0; i-=2){
// 			ans += vec[i];
// 		}
// 		cout<<ans<<endl;
// 	}
// }


// /////// p3 incorrect //
// #include <iostream>
// using namespace std;
 
// int main(){
// 	int t; 
// 	cin>>t;
// 	while(t--){
// 		int n, cnt=0, prev = 0, curr = 0;
// 		cin>>n;
// 		string s;
// 		cin>>s;
// 		for(int i=1; i<=n; i++){
// 			prev = 0;
// 			for(int j=i; j<=n; j++){
// 				curr = prev + int(s[j-1]-48);
// 				prev = curr;
// 				if(curr == j-i+1) cnt++;
// 			}
// 		}
// 		cout<<cnt<<endl;
// 	}
// }

////////// p3 ed //

#include<bits/stdc++.h>
using namespace std;

int T,n;
string s;
map<int,int>mp;

int main(){
	cin>>T;
	while(T--){
		mp.clear(); 
		cin>>n>>s;mp[0]++;
		long long ans=0,sum=0;
		for(int i=0;i<n;i++){
			sum+=s[i]-'1'; 
			ans+=mp[sum];
			mp[sum]++;
		}
		cout<<ans<<endl;
	}
}

////// p4 incorrect

/*Incorrect appoach to think it as a problem of 3 pointers, and greedy selection of
sticks.*/

////// p4 ed

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 202;
// int a[N], b[N], c[N];
// int dp[N][N][N];
// int n, m, k;
 
// int main(){
 
// 	scanf("%d%d%d", &n, &m, &k);
// 	for (int i = 0; i < n; i++)
// 		scanf("%d", &a[i]);
// 	sort(a, a + n);
// 	for (int i = 0; i < m; i++)
// 		scanf("%d", &b[i]);
// 	sort(b, b + m);
// 	for (int i = 0; i < k; i++)
// 		scanf("%d", &c[i]);
// 	sort(c, c + k);
 
// 	for (int i = n; i >= 0; i--)
// 		for (int j = m; j >= 0; j--)
// 			for (int h = k; h >= 0; h--) {
// 				if (i > 0 && j > 0)
// 					dp[i - 1][j - 1][h] = max(dp[i - 1][j - 1][h], dp[i][j][h] + a[i - 1] * b[j - 1]);
// 				if (i > 0 && h > 0)
// 					dp[i - 1][j][h - 1] = max(dp[i - 1][j][h - 1], dp[i][j][h] + a[i - 1] * c[h - 1]);
// 				if (j > 0 && h > 0)
// 					dp[i][j - 1][h - 1] = max(dp[i][j - 1][h - 1], dp[i][j][h] + b[j - 1] * c[h - 1]);
// 			}
// 	int ans = 0;
// 	for (int i = 0; i <= n; i++)
// 		for (int j = 0; j <= m; j++)
// 			for (int h = 0; h <= k; h++)
// 				ans = max(ans, dp[i][j][h]);
// 	printf("%d\n", ans);
 
// 	return 0;
// }

/////////////////////////////
///// p 5

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ld = long double;      
// set<int> small, big;
// set<int> fire, elec;
// ll sumBig = 0;
// ll sumAll = 0;
     
// void addOne(int x) {
// 	sumAll += x;
// 	if (big.empty() || x < *big.begin()) {
// 		small.insert(x);
// 	} else {
// 		big.insert(x);
// 		sumBig += x;
// 	}
// }
// void remOne(int x) {
// 	sumAll -= x;
// 	if (small.count(x)) {
// 		small.erase(x);
// 	} else {
// 		big.erase(x);
// 		sumBig -= x;
// 	}
// }
 
// ll calcAns() {
// 	while((int)big.size() > (int)elec.size()) {
// 		int x = *big.begin();
// 		big.erase(x);
// 		small.insert(x);
// 		sumBig -= x;
// 	}
// 	while((int)big.size() < (int)elec.size()) {
// 		int x = *small.rbegin();
// 		small.erase(x);
// 		big.insert(x);
// 		sumBig += x;
// 	}
// 	ll ans = sumAll + sumBig;
// 	if ((int)elec.size() > 0 && (fire.empty() || *fire.rbegin() < *elec.begin())) {
// 		ans -= *elec.begin();
// 		if (!fire.empty()) ans += *fire.rbegin();
// 	}
// 	return ans;
// }
 
// int main(){
     
//     int q;
//     scanf("%d", &q);
//     while(q--) {
//     	int t, x;
//     	scanf("%d%d", &t, &x);
// 		if (x > 0) {
// 			if (t == 0)
// 				fire.insert(x);
// 			else
// 				elec.insert(x);
//     		addOne(x);
//     	}else {
//     		x *= -1;
//     		if (t == 0)
//     			fire.erase(x);
//     		else
//     			elec.erase(x);
//     		remOne(x);
//     	}
//     	printf("%lld\n", calcAns());
// 	}     
//    	return 0;
// }

////////////////

/////F. Controversial Rounds

// #include <bits/stdc++h>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// #define pb push_back
// #define mp make_pair
// #define all(x) (x).begin(),(x).end()
// #define fi first
// #define se second

// const int N = (int)1e6 + 7;
// char s[N];
// int lst[2];
// int a[N];
// int nxt[N];
// int n;
// pii ord[N];
 
// int getNext(int p) {
// 	return nxt[p] == p ? p : nxt[p] = getNext(nxt[p]);
// }
// void turnOn(int p) {
// 	nxt[p] = p + 1;
// }
 
// int main(){

// 	scanf("%d", &n);
// 	scanf("%s", s);
// 	lst[0] = lst[1] = n;
// 	for (int i = n - 1; i >= 0; i--) {
// 		if (s[i] != '?')
// 			lst[(int)(s[i] - '0')] = i;
// 		a[i] = max(lst[0], lst[1]) - i;
// 		ord[i] = mp(a[i], i);
// 	}
// 	/*
// 	for (int i = 0; i < n; i++)
// 		eprintf("%d ", a[i]);
// 	eprintf("\n");
// 	*/
// 	for (int i = 0; i < n; i++)
// 		nxt[i] = i;
// 	nxt[n] = n;
// 	sort(ord, ord + n);
// 	int l = 0;
// 	for (int k = 1; k <= n; k++) {
// 		while(l < n && ord[l].first < k) {
// 			turnOn(ord[l].second);
// 			l++;
// 		}
// 		int ans = 0;
// 		int p = 0;
// 		while(p < n) {
// 			p = getNext(p);
// 			if (p == n) break;
// 			ans++;
// 			p += k;
// 		}
// 		printf("%d ", ans);
// 	}
// 	printf("\n");
 
// 	return 0;
// }

///////////////////////////

    // #include <bits/stdc++.h>
    // using namespace std;
     
    // #define ll long long
    // #define ar array
     
    // const int mxN=1e6;
    // int n, prv[mxN+1][2], a[mxN+1][2];
    // string s;
     
    // int main() {
    // 	ios::sync_with_stdio(0);
    // 	cin.tie(0);
     
    // 	cin >> n >> s;
    // 	prv[0][0]=prv[0][1]=-1;
    // 	for(int i=0; i<n; ++i) {
    // 		prv[i+1][0]=prv[i][0];
    // 		prv[i+1][1]=prv[i][1];
    // 		a[i+1][0]=a[i][0];
    // 		a[i+1][1]=a[i][1];
    // 		if(s[i]=='?')
    // 			continue;
    // 		prv[i+1][s[i]&1]=i;
    // 		++a[i+1][s[i]&1];
    // 	}
    // 	for(int x=1; x<=n; ++x) {
    // 		int s=0, c=0;
    // 		while(s+x<=n) {
    // 			if(a[s+x][0]-a[s][0]==0) {
    // 				s+=x;
    // 				++c;
    // 				continue;
    // 			}
    // 			if(a[s+x][1]-a[s][1]==0) {
    // 				s+=x;
    // 				++c;
    // 				continue;
    // 			}
    // 			int b=prv[s+x][1]>prv[s+x][0];
    // 			s=prv[s+x][b^1]+1;
    // 		}
    // 		cout << c << " ";
    // 	}
    // }

//////////////////