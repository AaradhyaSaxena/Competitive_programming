///////// cf 738

//// A
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	ll arr[n];
	ll minn = INT_MAX;
	int odd = 0, even = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		minn = min(minn, arr[i]);
		if(arr[i]%2==0) even++;
		else odd++;
	}
	if(odd==0 or even==0){
		cout<<minn<<endl;
	}
	else{
		cout<<0<<endl;
	}
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
		solve();
    }
    return 0;
}

//////// B


#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

string helper(string ss){
	int n = ss.length();
	string ans = "";
	if(ss[0] != '?'){
		ans += ss[0];
		for(int i=1; i<=n; i++){
			if(ss[i] != '?'){
				ans += ss[i];
				continue;
			}
			if(ans[i-1] == 'R'){
				ans += 'B';
			}else{
				ans += 'R';
			}
		}
	}
	return ans;
}
 
void solve(int tc = 0) {
	int n; cin>>n;
	string ss; cin>>ss;
	string ans = "";
	
	int index = 200;
	for(int i=0; i<n; i++){
		if(ss[i] != '?'){
			index = i;
			break;
		}
	}
	if(index == 0){
		ans = helper(ss);
		ans = ans.substr(0, ans.length()-1);
	}
	else if(index==200){
		for(int i=0; i<n; i++){
			if(i%2==0){
				ans += 'R'; 
			}
			else{
				ans += 'B';
			}
		}
	}
	else{
		string stringL = "";
		string stringR = "";
		stringR = helper(ss.substr(index,n-index));
		
		string sec = ss.substr(0,index+1);
		string revsec = "";
		for(int i=sec.length()-1; i>=0; i--){
			revsec += sec[i];
		}
		revsec = helper(revsec);
		revsec = revsec.substr(1, revsec.length()-1);
		for(int i=revsec.length()-1; i>=0; i--){
			stringL += revsec[i];
		}
		ans = stringL + stringR;
		ans = ans.substr(1, ans.length()-2);
	}
	cout<<ans<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
		solve();
    }
    return 0;
}

////////////// C

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	ll arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int index = n+1;
	for(int i=0; i<n; i++){
		if(arr[i]==1){
			index = i;
			break;
		}
	}
	int cnt = 1;
	for(int i=0; i<=n; i++){
		if(i==index){
			cout<<n+1<<" ";
		}else{
			cout<<cnt++<<" ";
		}
	}
	cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
		solve();
    }
    return 0;
}

////// D

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

vector<vector<int>> g1(1000);
vector<vector<int>> g2(1000);

// bool dfs(int x, int par, vector<bool>& vis){
// 	vis[x]=true;  
// 	for(auto y : adj[x]){
// 		if(vis[y] && par != y || y==x)
// 			return true;
// 		else if(!vis[y] && dfs(adj, y, x, vis))
// 			return true;
// 	}
// 	return false;
// }
    
// bool isCycle(int V){
// 	vector<bool>vis(V);
// 	//////
// 	return false;
// }

bool add_edge_legal(int a, int b){
	for(int i=0; i<g1[a].size(); i++){
		if(g1[a][i] == b){
			return false;
		}
	}
	for(int i=0; i<g1[a].size(); i++){
		if(g2[a][i] == b){
			return false;
		}
	}
	g1[a].push_back(b); g1[b].push_back(a);
	// if(isCycle())
	
	g1[a].pop_back(); g1[b].pop_back();

	return true;
}
 
void solve(int tc = 0) {
	int n,m1,m2; cin>>n>>m1>>m2;
	g1.clear(); g2.clear();
	for(int i=0; i<m1; i++){
		int x,y;
		cin>>x>>y;
		g1[x].push_back(y);
		g1[y].push_back(x);
	}
	for(int i=0; i<m2; i++){
		int x,y;
		cin>>x>>y;
		g2[x].push_back(y);
		g2[y].push_back(x);
	}
	int cnt = 0;
	vector<pair<int,int>> ans;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(add_edge_legal(i,j)){
				cnt++;
				ans.push_back({i,j});
				g1[i].push_back(j); g1[j].push_back(i);
				g2[i].push_back(j);	g2[j].push_back(i);
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=0; i<cnt; i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
		solve();
    }
    return 0;
}



