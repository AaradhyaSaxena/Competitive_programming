///////// cf edu 115

//// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	string s1, s2;
	cin>>s1>>s2;
	if(s1[0]=='1' or s2[n-1]=='1'){
		cout<<"NO"<<endl;
		return;
	}
	for(int i=0; i<n-1; i++){
		if(s1[i+1]=='1' and s2[i+1]=='1'){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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

//// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	int arr[n][5];
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++){
			cin>>arr[i][j];
		}
	}
	bool table[5];
	for(int i=0; i<5; i++) table[i] = 0;
	for(int j=0; j<5; j++){
		int cnt = 0;
		for(int i=0; i<n; i++){
			cnt += arr[i][j];
		}
		if(cnt>= n/2) table[j]=1;
	}
	bool students[n];
	for(int i=0; i<n; i++) students[i] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++){
			if(table[j]==1 and arr[i][j]==1){
				students[i]= 1;
				break;
			}
		}
	}
	for(int i=0; i<n; i++){
		if(students[i]==0){
			cout<<"NO"<<endl;
			return;
		}
	}
	int cnt =0;
	for(int j=0; j<5; j++){
		cnt += table[j];
	}
	if(cnt<2){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
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

// //// C
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

void solve(int tc = 0) {
	int n; cin>>n;
	ll arr[n];
	double mean = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		mean += (1.0)*arr[i]/n;
	}
	double k = mean;
	unordered_map<ll,vector<ll> > mp;
	vector<pair<ll,ll>> vec;
	for(int i=0; i<n; i++){
		mp[arr[i]].push_back(i);
	}
	for(int i=0; i<n; i++){
		double temp = (2.0)*k - arr[i];
		if(mp.find(temp) != mp.end()){
			for(int j=0; j<mp[temp].size(); j++){
				vec.push_back({i, mp[temp][j]});
			}
		}
	}
	vector<pair<ll,ll>> ans;
	for(int i=0; i<vec.size(); i++){
		ll x = vec[i].first, y = vec[i].second;
		if(x<y){
			ans.push_back({vec[i].first,vec[i].second});
		}
	}
	cout<<ans.size()<<endl;
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


// //// D
// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;
 
// void solve(int tc = 0) {
// 	int n; cin>>n;
// 	pair<int,int> pr[n];
// 	for(int i=0; i<n; i++){
// 		int x, y; cin>>x>>y;
// 		pr[i].first = x, pr[i].second = y;
// 	}
// 	for(int)
// }
 
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int t; cin >> t;
//     while(t--){
// 		solve();
//     }
//     return 0;
// }