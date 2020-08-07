//// Code_forces 662

//// problem C
/// https://codeforces.com/contest/1393/problem/C

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

// }


/////////////////////////////////////////////////

/// https://codeforces.com/contest/1393/problem/B
//// problem B

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	map<int,int> mp;
	map<int, int>::iterator itr; 
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(mp.find(arr[i])==mp.end()){
			mp[arr[i]] = 1;
		}else{
			mp[arr[i]]++;
		}
	}
	int t;
	cin>>t;
	while(t--){
		char sign; int num;
		cin>>sign; cin>>num;
		int cnt4 = 0, cnt2 = 0;
		if(sign=='+'){
			if(mp.find(num)==mp.end()){
				mp[num] = 1;
			}else{
				mp[num]++;
			}
		}else{
			mp[num]--;
		}
		for(itr = mp.begin(); itr != mp.end(); ++itr) {
			int value = itr->second;
			cnt4 += value/4;
			cnt2 += value/2;
		}
		cnt2 = cnt2 - 2*cnt4;
		if(cnt4 >= 2){
			cout<<"YES"<<endl;
		}else if(cnt4 ==1 and cnt2 >= 2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const double pi = acos(-1.0);
    const int mod = (1 ? 1000000007 : 998244353);
    const int inf = (1 ? 0x3f3f3f3f : 0x7fffffff);
    const int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
    const ll INF = (1 ? 0x3f3f3f3f3f3f3f3f : 0x7fffffffffffffff);
     
    ll a, b, c, d, e, f;
     
    int num[100005];
    void solve()
    {
    	cin >> a;
    	memset(num, 0, sizeof(num));
    	while(a--)
    	{
    		cin >> b;
    		num[b]++;
    	}
    	cin >> a;
    	c = 0; d = 0;
    	for (int i = 1; i <= 100000; i++)
    	{
    		c += num[i] / 4;
    		d += num[i] % 4 / 2;
    	}
    	string z;
    	while (a--)
    	{
    		cin >> z >> b;
    		c -= num[b] / 4;
    		d -= num[b] % 4 / 2;
    		if (z == "-")num[b]--;
    		else num[b]++;
    		c += num[b] / 4;
    		d += num[b] % 4 / 2;
    		if (c >= 1 && (c - 1) * 2 + d >= 2)cout << "YES" << endl;
    		else cout << "NO" << endl;
    	}
     
    }
     
    int main()
    {
    	ios::sync_with_stdio(false); cin.tie(0);
    	ll T = 1;
    	//cin >> T;
    	while (T--)solve();
    }
     


////////////////////////////////////////////////
///https://codeforces.com/contest/1393/problem/A

//// problem A
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n, ans; 
// 		cin>>n;
// 		ans = (n/2)+1;
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }

