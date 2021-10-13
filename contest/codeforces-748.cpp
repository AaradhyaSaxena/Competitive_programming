//////////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	ll arr[3]; 
	ll maxx = 0;
	for(int i=0; i<3; i++){
		cin>>arr[i];
		maxx = max(maxx, arr[i]);
	} 
	int cnt=0;
	for(int i=0; i<3; i++){
		if(maxx==arr[i]) cnt++;
	}
	if(cnt==1){
		for(int i=0; i<3; i++){
			if(arr[i]==maxx){
				cout<<0<<" ";
			}
			else{
				cout<<(maxx-arr[i]+1)<<" ";
			}
		}
		cout<<endl;
	}
	else if(cnt==3){
		cout<<1<<" "<<1<<" "<<1<<endl;
	}
	else{
		for(int i=0; i<3; i++){
			if(arr[i]==maxx){
				cout<<1<<" ";
			}
			else{
				cout<<(maxx-arr[i]+1)<<" ";
			}
		}
		cout<<endl;
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

/////////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	ll n; cin>>n;
	int arr[4] = {00,25,50,75};
	string st = to_string(n);
	int len = st.length();
	reverse(st.begin(), st.end());
	vector<int> pos5, pos2, pos7, pos0;
	for(int i=0; i<len; i++){
		if(st[i]=='0') pos0.push_back(i+1);
		if(st[i]=='2') pos2.push_back(i+1);
		if(st[i]=='5') pos5.push_back(i+1);
		if(st[i]=='7') pos7.push_back(i+1);
	}
	int ans = 100;	
	if(pos0.size()>=2){
		ans = min(ans, pos0[1]-2);
	}
	if(pos2.size()>0 and pos5.size()>0){
		int temp = pos5[0];
		for(int i=0; i<pos2.size(); i++){
			if(pos2[i]>temp){
				ans = min(ans, pos2[i]-2);
				break;
			}
		}
	}
	if(pos5.size()>0 and pos0.size()>0){
		int temp = pos0[0];
		for(int i=0; i<pos5.size(); i++){
			if(pos5[i]>temp){
				ans = min(ans, pos5[i]-2);
				break;
			}
		}
	}
	if(pos7.size()>0 and pos5.size()>0){
		int temp = pos5[0];
		for(int i=0; i<pos7.size(); i++){
			if(pos7[i]>temp){
				ans = min(ans, pos7[i]-2);
				break;
			}
		}
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

//////////// C

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n,k; cin>>n>>k;
	int arr[k];
	ll cnt =0;
	vector<ll> pos;
	for(int i=0; i<k; i++){
		cin>>arr[i];
		pos.push_back(n-arr[i]);
	}
	sort(pos.begin(),pos.end());
	int ans = 0;
	for(int i=0; i<k; i++){
		if(cnt + pos[i] >= n){
			break;
		}
		cnt += pos[i];
		ans = i+1;
	}
	cout<<(ans)<<endl;
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

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(vector<int> arr){
	int n = arr.size();
    int result = arr[0];
    for (int i = 1; i < n; i++){
        result = gcd(arr[i], result);
        if(result == 1){
           return 1;
        }
    }
    return result;
}

void solve(int tc = 0) {
	int n; cin>>n;
	int arr[n];
	int minn = INT_MAX;
	vector<int> vec;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		minn = min(minn, arr[i]);
	}
	for(int i=0; i<n; i++){
		if(arr[i]!=minn){
			vec.push_back(arr[i]-minn);
		}
	}
	if(vec.size()==0){
		cout<<-1<<endl;
	}
	else{
		int ans = findGCD(vec);
		cout<<ans<<endl;
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

//////////// E

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n,k; cin>>n>>k;
	vector<vector<int>> vec(n);
	for(int i=0; i<n-1; i++){
		int x,y; cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	int ans =0;
	for(int i=0; i<k; i++){
		for(int j=0; j<vec.size(); j++){
			int last=0;
			if(vec[j].size()==1){
				last = vec[j][0];
				vec[j].clear();
			}
			for(int k=0; k<vec[last].size(); k++){
				if(vec[last][k]==j+1){
					vec[last].erase(vec[last].begin()+k);
				}
			}
		}
	}
	int cnt =0;
	for(int i=0; i<vec.size(); i++){
		cnt += vec[i].size();
	}
	cnt = cnt/2;
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

/// runtime error

