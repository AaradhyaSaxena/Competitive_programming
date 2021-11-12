////////// A
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	string a, b;
	cin>>a>>b;
	unordered_map<int,int> mp;
	for(int i=0; i<26; i++){
		mp[a[i]-'a'] = i;
	}
	int cnt = 0;
	for(int i=1; i<b.length(); i++){
		cnt += abs(mp[b[i]-'a']-mp[b[i-1]-'a']);
	}
	cout<<cnt<<endl;
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

/////////// B
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	ll pos, jumps;
	ll ref = 0;
	cin>>pos>>jumps;
	if(pos%2==0){
		if(jumps%4==0){
			ref = 0;
		}
		else if(jumps%4==1){
			ref = (-1)*jumps;
		}
		else if(jumps%4==2){
			ref = 1;
		}
		else{
			ref = (jumps+1);
		}
		cout<<pos+ref<<endl;
	}
	else{
		if(jumps%4==0){
			ref = 0;
		}
		else if(jumps%4==1){
			ref = jumps;
		}
		else if(jumps%4==2){
			ref = -1;
		}
		else{
			ref = (-1)*(jumps+1);
		}
		cout<<pos+ref<<endl;
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

/////////// C
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	vector<ll> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());

	ll maxdiff = arr[0];
	for(int i=1; i<n; i++){
		maxdiff = max(maxdiff, (arr[i]-arr[i-1]));
	}
	cout<<max(maxdiff, arr[0])<<endl;
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

///////// D
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
	string ss; cin>>ss;
	vector<ll> blue;
	vector<ll> red;
	for(int i=0; i<n; i++){
		if(ss[i]=='B'){
			blue.push_back(arr[i]);
		}
		else{
			red.push_back(arr[i]);
		}
	}
	sort(blue.begin(), blue.end());
	sort(red.begin(), red.end());
	
	int bm = blue.size();
	int rm = red.size();
	int b = 0, r = 0;

	bool answer = true;
	for(int i=1; i<=n; i++){
		if(b>bm or r>rm){
			answer = false;
			break;
		}
		if( (b < bm and i<=blue[b]) or (r< rm and i>=red[r])){
			if( b < bm and i<=blue[b]){
				b++;
			}
			else{
				r++;
			}
		}
		else{
			answer= false;
			break;
		}
	}
	if(answer){
		cout<<"YES"<<endl;
	}
	else{
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

////////// E

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {

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

/////////////

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {

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

/////////////