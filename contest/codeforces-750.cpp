//////////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	ll a,b,c;
	cin>>a>>b>>c;
	if((a+2*b+3*c)%2==0){
		cout<<0<<endl;
	}else{
		cout<<1<<endl;
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

//////////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	ll arr[n];
	int cnto = 0, cnt1 = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]==0) cnto++;
		if(arr[i]==1) cnt1++;
	}
	ll ans = pow(2,cnto)*cnt1;
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

int helper(string ss, char a) {
	int n = ss.length();
	int i=0, j=n-1;
	int cnt =0;
	while(i<j){
		if(ss[i]==ss[j]){
			i++; j--;
		}
		else if(ss[i]==a){
			i++;
			cnt++;
		}
		else if(ss[j]==a){
			j--;
			cnt++;
		}else{
			return n;
		}
	}
	return cnt;
}

string stringbreak(string ss, int i, int j){
	return ss.substr(i, (j-i+1));
}
 
void solve(int tc = 0) {
	int n; cin>>n;
	string ss; cin>>ss;
	string rev = ss;
	reverse(rev.begin(), rev.end());
	int cnt = 0;
	int i=0, j=n-1;
	while(i<j){
		if(ss[i]==ss[j]){
			i++; j--;
		}
		else{
			cnt = n;
			cnt = min(cnt, helper(ss, ss[i]));
			cnt = min(cnt, helper(ss, ss[j]));
			break;
		}
	}
	if(cnt==n){
		cout<<-1<<endl;
	}
	else{
		cout<<cnt<<endl;
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

//////////// D

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	ll arr[n];
	ll sum = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	ll sumarr[n];
	for(int i=0; i<n; i++){
		sumarr[i] = sum-arr[i];
	}
	if(sum==0){
		for(int i=0; i<n; i++){
			cout<<1<<" ";
		}
		cout<<endl;
	}
	else{
		int flag = 0;
		for(int i=0; i<n; i++){
			if( sumarr[i]%abs(arr[i])==0 and flag==0){
				cout<<(sumarr[i]/arr[i])*(-1)<<" ";
				flag=1;
			}else{
				cout<<1<<" ";
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

//////////// F1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(int tc = 0) {
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	} 
	//////
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

