//////https://codeforces.com/contests/1419
// https://codeforces.com/blog/entry/82817

/// Code forces 671

///// p1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n; cin>>n;
    	string s1;
    	cin>>s1;
    	int oo = 0, oe = 0, ee = 0, eo = 0;
    	for(int i=1; i<=n; i++){
    		if(s1[i-1]%2==0 and i%2==0){
    			ee++;
    		}
    		else if(s1[i-1]%2==0 and i%2!=0){
    			oe++;
    		}
    		else if(s1[i-1]%2 !=0 and i%2==0){
    			eo++;
    		}
    		else if(s1[i-1]%2 !=0 and i%2!=0){
    			oo++;
    		}
    	}
    	for(int i=1; i<n; i++){
    		if(i%2==1){
    			if(oe>0) oe--;
    			else oo--;
    		}
    		else{
    			if(eo>0) eo--;
    			else ee--;
    		}
    	}

    	if(oe + ee >= oo + eo){
    		cout<<2<<endl;
    	}else{
    		cout<<1<<endl;
    	}
    }
    return 0;
}


//////// p2

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

ll factorial(ll n){ 
    return (n==1 || n==0) ? 1: n*factorial(n - 1);  
} 
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	ll n;
    	cin>>n;
    	ll i = 1, cnt =0;
    	while(n>0){
    		n -= factorial(i);
    		cnt++;
    		i += 2;
    	}
    	if(n<0){
    		cnt--;
    	}
    	cout<<cnt<<endl;
    }
    return 0;
}

////

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
const int INF = 2e9 + 1;
 
ll getS(ll x) {
    return x * (x + 1) / 2; 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T --> 0) {
        ll x;
        cin >> x;
        int ans = 0;
        for (int i = 1; getS((1LL << i) - 1) <= x; i++) {
            ans++;
            x -= getS((1LL << i) - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}

///////////////////


#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
    	cin>>arr[i];
    }
    sort(arr, arr+n);
    int i = 0, j= n-2;
    while(j>i){
    	int temp = arr[i];
    	arr[i] = arr[j];
    	arr[j] = temp;
    	i += 2; 
    	j -= 2;
    }
    int cnt = 0;
    for(int i=1; i<n-1; i++){
    	if(arr[i]<arr[i-1] and arr[i]<arr[i+1]){
    		cnt++;
    	}
	}
	cout<<cnt<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}

///// d2

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        bool f = true;
        if (2 * m + 1 > n) {
            f = false;
        }
        else {
            vector<int> b;
            int pos_a = 0, pos_b = n - (m + 1);
            for (int i = 0; i < 2 * m + 1; ++i) {
                if (i % 2 == 0) {
                    b.emplace_back(a[pos_b]);
                    ++pos_b;
                }
                else {
                    b.emplace_back(a[pos_a]);
                    ++pos_a;
                }
            }
            for (int i = 1; i < 2 * m + 1; i += 2) {
                if (b[i] >= b[i - 1] || b[i] >= b[i + 1])
                    f = false;
            }
        }
        if (f)
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    vector<int> b;
    int pos_a = 0, pos_b = n - (l + 1);
    for (int i = 0; i < 2 * l + 1; ++i) {
        if (i % 2 == 0) {
            b.emplace_back(a[pos_b]);
            ++pos_b;
        }
        else {
            b.emplace_back(a[pos_a]);
            ++pos_a;
        }
    }
    for (int i = pos_a; i < n - (l + 1); ++i) {
        b.emplace_back(a[i]);
    }
    for (auto &c : b) {
        cout << c << " ";
    }
}

///////////////////


// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){

//     }
//     return 0;
// }

///////////////////

