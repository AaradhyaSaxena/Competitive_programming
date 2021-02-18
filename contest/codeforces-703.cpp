///////////// df 703
//////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
 
void solve(){
	ll n; 
	cin>>n;
	ll arr[n];
	ll sum =0;
	int flag = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]>i){
			sum += (arr[i]-i);
		}
		else if(arr[i]<i){
			if(arr[i]+sum<i){
				flag =1;
			}else{
				sum -= (i-arr[i]);
			}
		}
	}
	if(flag==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return;
}
 
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

// //////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int dx[8] = {1,1,1,-1,-1,-1,0,0};
int dy[8] = {1,0,-1,1,0,-1,1,-1};
 
void solve(){
	int n; 
	cin>>n;
	ll arr[n][2];
	vector<int> xx,yy;
	for(int i=0; i<n; i++){
		cin>>arr[i][0];
		cin>>arr[i][1];
		xx.push_back(arr[i][0]);
		yy.push_back(arr[i][1]);
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());

	int x_mid, y_mid;
	int cnt, dmin;
	if(n%2 !=0 ){
		cnt =1;
		x_mid = xx[n/2]; 
		y_mid = yy[n/2];
		dmin = 0;
		for(int i=0; i<n; i++){
			dmin += abs(x_mid-arr[i][0]) + abs(y_mid-arr[i][1]);
		}
		for(int i=0; i<8; i++){
			int temp = 0;
			int X = x_mid + dx[i], Y=y_mid + dy[i];
			for(int i=0; i<n; i++){
				temp += abs(X-arr[i][0]) + abs(Y-arr[i][1]);
			}
			if(temp<=dmin){
				cnt++;
			}
		}
	}
	else{
		cnt = 1;
		int x_mid1 = xx[n/2], y_mid1 = yy[n/2];
		int x_mid2 = xx[(n/2) -1], y_mid2 = yy[(n/2) -1];
		int dmin1, dmin2;
		dmin1 = 0;
		for(int i=0; i<n; i++){
			dmin1 += abs(x_mid1 - arr[i][0]) + abs(y_mid1 - arr[i][1]);
		}
		dmin2 = 0;
		for(int i=0; i<n; i++){
			dmin2 += abs(x_mid2 - arr[i][0]) + abs(y_mid2 - arr[i][1]);
		}
		dmin = min(dmin1, dmin2);

		vector<pair<int,int>> vec;
		vec.push_back({x_mid1, y_mid1});
		for(int i=0; i<8; i++){
			int flag = 0;
			int temp = 0;
			int X = x_mid1 + dx[i], Y = y_mid1 + dy[i];
			for(int i=0; i<vec.size(); i++){
				if(X == vec[i].first and Y == vec[i].second){
					flag = 1;
				}
			}
			if(flag==0){
				vec.push_back({X, Y});
				for(int i=0; i<n; i++){
					temp += abs(X-arr[i][0]) + abs(Y-arr[i][1]);
				}
				if(temp==dmin){
					cnt++;
				}
			}
		}

		if(true){
			int flag1 =0;
			for(int i=0; i<vec.size(); i++){
				if(x_mid2==vec[i].first and y_mid2==vec[i].second){
					flag1 = 1;
				}
			}
			if(flag1==0){
				int temp1 = 0;
				vec.push_back({x_mid2, y_mid2});
				for(int i=0; i<n; i++){
					temp1 += abs(x_mid2-arr[i][0]) + abs(y_mid2-arr[i][1]);
				}
				if(temp1==dmin){
					cnt++;
				}
			}

			for(int i=0; i<8; i++){
				int flag = 0;
				int temp = 0;
				int X = x_mid2 + dx[i], Y= y_mid2 + dy[i];
				for(int i=0; i<vec.size(); i++){
					if(X==vec[i].first and Y==vec[i].second){
						flag = 1;
					}
				}
				if(flag==0){
					vec.push_back({X, Y});
					for(int i=0; i<n; i++){
						temp += abs(X-arr[i][0]) + abs(Y-arr[i][1]);
					}
					if(temp==dmin){
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt<<endl;

	return;
}
 
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
/////// correct B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

void solve(){
	ll n; cin >> n;
	ll x[n], y[n];
	for(ll i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	sort(x,x+n);
	sort(y,y+n);
	
	if(n % 2 == 1){
		cout << 1 << "\n";
		return;
	}
	cout << (x[n/2] - x[n/2 - 1] + 1) * (y[n/2] - y[n/2 - 1] + 1) << "\n";
}
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}


///////// C

#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
 
void solve(){
	int n; 
	cin>>n;
	int l = 1, r = n;
	int sec, sec1, sec2;
	cout.flush();
	while(l<r){
		cout<<"? "<<l<<" "<<r<<endl; cout.flush();
		cin>>sec;
		cout<<"? "<<l<<" "<<sec<<endl; cout.flush();
		cin>>sec1;
		cout<<"? "<<sec<<" "<<r<<endl; cout.flush();
		cin>>sec2;
		if(sec==sec1){
			r=sec-1;
		}
		else{
			l=sec+1;
		}
	}
	cout<<"! "<<l<<endl;
}
 
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

/////////// c correct

#include<bits/stdc++.h> 
using namespace std;
#define int long long

map<pair<int,int>, int> qans;
 
int query(int l,int r){
	if(qans.count({l,r})){
		return qans[{l,r}];
	}
	if(l == r){
		return -1;
	}
	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;
	return qans[{l,r}] = ans;
}
void answer(int x){
	cout << "! " << x << endl;
	exit(0);
}
 
void solve(){
	int n;
	cin >> n;
	
	int smx = query(1,n);
	int ans;
	if(smx == query(1,smx)){
		// [1 to smx]
		int L = 1, U = smx - 1;
		while(L <= U){
			int m = (L + U) / 2;
			if(query(m,smx) == smx){
				ans = m;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
	}
	else{
		// [smx to r]
		int L = smx + 1, U = n;
		while(L <= U){
			int m = (L + U) / 2;
			if(query(smx,m) == smx){
				ans = m;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
	}
	answer(ans);
}

int main(){
	int T=1;
	// cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

/////////////
