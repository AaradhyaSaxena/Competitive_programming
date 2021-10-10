///////// cf 744

//// A
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	string s; cin>>s;
	int a=0,b=0,c=0;
	for(int i=0; i<s.length(); i++){
		if(s[i] == 'A') a++;
		if(s[i] == 'B') b++;
		if(s[i] == 'C') c++;
	}
	// cout<<a<<" "<<b<<" "<<c<<endl;
	if(b==(a+c)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
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

void helper( *arr, int start, int n){
	ll minn = INT_MAX, index = 0;
	for(ll i=start; i<=n; i++){
		minn = min(minn, arr[i]);
		if(arr[i]==minn) index = i;
	}
	if(index==start){
		helper(arr, start+1, n);
	}
	else{
		cout<<start<<" "<<n<<" "<<(n-index);
		vector<ll> vec;
		for(ll i=start; i<=n; i++){
			vec.push_back(arr[i]);
		}
		ll vec_size = vec.size();
		for(ll i=0; i<vec_size; i++){
			arr[start+i] = vec[(i+index)%vec_size];
		}
		helper(arr,start+1,n);
	}
}
 
void solve(int tc = 0) {
	ll n; cin>>n;
	ll arr[n];
	for(ll i=0; i<n; i++){
		cin>>arr[i];
	}
	helper(arr,1,n);
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

//// C
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n,m,k; cin>>n>>m>>k;
	vector<string> vec;
	for(int i=0; i<n; i++){
		string ss;
		cin>>ss;
		vec.push_back(ss);
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

//////// D

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

bool comp(int a[], int b[]){
    return (a[1] < b[1]);
}
 
void solve(int tc = 0) {
	int n; cin>>n;
	priority_queue<pair<int, int> > arr;
	for(int i=0; i<n; i++){
		int x,y; cin>>x; y=i+1;
		arr.push({x,y});
	}
	int cnt = 0;
	vector< pair<int,int>> ans;

	while(arr.size()>1){
		pair<int,int> end2 = arr.top(); arr.pop();
		pair<int,int> end1 = arr.top(); arr.pop();
		if(end1.first <= end2.first){
			int k = end1.first;
			cnt += k;
			for(int i=0; i<k; i++){
				ans.push_back({end1.second, end2.second});
			}
		}
		if((end2.first-end1.first)>0){
			arr.push({(end2.first-end1.first),end2.second});	
		}
	}
	cout<<cnt<<endl;
	for(int i=0; i<ans.size(); i++){
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

//////// E1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	ll n; cin>>n;
	ll arr[n];
	for(ll i=0; i<n; i++){
		cin>>arr[i];
	}
	deque <int> dq;
	dq.push_back(arr[0]);
	for(int i=1; i<n; i++){
		if(arr[i] < dq.front()){
			dq.push_front(arr[i]);
		}
		else{
			dq.push_back(arr[i]);
		}
	}
	deque <int> :: iterator it;
    for (it = dq.begin(); it != dq.end(); ++it)
        cout << " " << *it;
    cout << endl;
	
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
