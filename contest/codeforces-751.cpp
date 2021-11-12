//////////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	string s; cin>>s;
	string a, b;
	int minn = 26, index = 0;
	for(int i=0; i<s.length(); i++){
		minn = min(minn, s[i]-'a');
		if(minn ==(s[i]-'a')) index = i;
	}
	a = s[index];
	for(int i=0; i<s.length(); i++){
		if(i==index) continue;
		b += s[i];
	}
	cout<<a<<" "<<b<<endl;
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

//////////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	int arr[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr[i][j] = 0;
		}
	}
	for(int i=0; i<n; i++){
		cin>>arr[0][i];
	} 
	unordered_map<int,int> mp;
	bool change = true;
	int j = 0, iter = 0;
	while (change){
		mp.clear();
		int cnt = 0;
		for(int i=0; i<n; i++){
			mp[arr[j][i]]++;
		}
		for(int i=0; i<n; i++){
			if(arr[j][i] != mp[arr[j][i]]){
				cnt++;
			}
			arr[j+1][i] = mp[arr[j][i]];
		}
		if(cnt==0){
			iter = j+1;
			break;
		}
		j++;
	}
	int q; cin>>q;
	for(int i=0; i<q; i++){
		int a, k; cin>>a>>k;
		k = min(iter, k);
		cout<<arr[k][a-1]<<endl;
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

//////////// D incorrect

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	int arr[n];
	int brr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		cin>>brr[i];
	}  
	int jump[n+1000];
	for(int i=0; i<n+1000; i++){
		jump[i] = n+1000;
	}
	int parent[n+1000];
	for(int i=0; i<n+1000; i++){
		parent[i] = n+1000;
	}
	for(int i=0; i<n; i++){
		if( arr[i]-i > 0 ){
			jump[i] = 1;
			parent[i] = 0;
		}
		for(int j=i; j>= max(0,i-arr[i]); j--){
			int idx = min(n-1,j + brr[j]);
			jump[i] = min(jump[idx]+1, jump[i]);
			if(jump[i] == jump[idx]+1){
				parent[i] = idx;
			}
		}
		cout<<jump[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<parent[i]<<" ";
	}cout<<endl;
	if(jump[n-1]>=n+1000){
		cout<<-1<<endl;
	}
	else{
		cout<<jump[n-1]<<endl;
		int pos = n-1;
		while(pos){
			cout<<parent[pos]+1<<" ";
			pos = parent[pos] - brr[parent[pos]];
			pos = max(0, pos);
		}
		cout<<0<<endl;
	}
	
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
		solve();
    }
    return 0;
}

