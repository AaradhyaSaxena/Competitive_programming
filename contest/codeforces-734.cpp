///// codeforces 734

//////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	ll n;
	cin >> n;
	if(n%3==0){
		cout<<n/3<<" "<<n/3<<endl;
	}
	else if(n%3==1){
		cout<<n/3 + 1<<" "<<n/3<<endl;
	}
	else{
		cout<<n/3<<" "<<n/3 + 1<<endl;
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
     
void solve(int tc = 0) {
	string ss; cin>>ss;
	ll n = ss.length();
	int arr[26];
	for(int i=0; i<26; i++){
		arr[i] = 0;
	}
	for(int i=0; i<n; i++){
		arr[ss[i]-'a']++;
	}
	int cntx=0, cnty=0;
	for(int i=0; i<26; i++){
		if(arr[i]>=2){
			cntx++; cnty++;
		}
		else if(arr[i]!=0 and cntx==cnty){
			cntx++;
		}
		else if(arr[i]!=0 and cntx>cnty){
			cnty++;
		}
		else if(arr[i]!=0 and cntx<cnty){
			cntx++;
		}
	}
	if(cntx==cnty){
		cout<<cntx<<endl;
	}
	else{
		cout<<min(cntx,cnty)<<endl;
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

////////// C

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n, k; cin>>n>>k;
	unordered_map<int,int> mp;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}
	ll cnt=0;
	for(int i=0; i<n; i++){
		if(mp[arr[i]] ==0) continue;
		if(mp[arr[i]] >= k) cnt += k;
		else cnt += mp[arr[i]];
		mp[arr[i]] = 0;
	}
	cout<<cnt/k<<endl;
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








