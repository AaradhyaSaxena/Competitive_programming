////////  p1

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
        	int n;
        	cin>>n;
        	int arr[n];
        	for(int i=0; i<n; i++){
        		cin>>arr[i];
        	}
        	for(int i=n-1; i>=0; i--){
        		cout<<arr[i]<<" ";
        	}cout<<endl;
        }
        return 0;
    }

//////// p2

#include <bits/stdc++.h>
using namespace std;

int main(){     
   	ios::sync_with_stdio(false), cin.tie(0);
	int t; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long cur = 0;
		for (int i = 0; i < n; ++i) {
			long long x; 
			cin >> x;
			cur = max(0LL, cur + x);
		}
		cout << cur << "\n";
	}
}
///////////////////////

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
    	ll n;
    	cin>>n; 
    	ll arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	int flag = 1;
    	ll cnt = 0;
    	while(flag==1){
    		flag = 0;
    		for(int i=0; i<n; i++){
    			int j = i+1;
    			while(arr[i]>0 and j<n){
    				if(arr[j]<0){
    					arr[i] = arr[i] + arr[j];
    					arr[j] = 0;
    				}
    				j++; 
    			}
    		}
    		for(int i=n-1; i>=0; i--){
    			int j = i-1;
    			while(arr[i]>0 and j>=0){
    				if(arr[j]<0){
    					arr[i] = arr[i] + arr[j];
    					cnt += abs(arr[j]);
    					arr[j] = 0;
    				}
    				j--;
    			}
    		}
    		for(int i=0; i<n; i++){
    			if(arr[i] != 0){
    				flag = 1;
    				break;
    			}
    		}
    	}
    	cout<<cnt<<endl;
    }
    return 0;
}
//////////////////////

//// p3

#include <bits/stdc++.h>
using namespace std;
     
int n, k, t;
string s;
     
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        int zer = 0, one = 0;
        bool chk = true;
        for (int i = 0; i < k; i++) {
            int tmp = -1;
            for (int j = i; j < n; j += k) {
                if (s[j] != '?') {
                    if (tmp != -1 && s[j] - '0' != tmp) {
                        chk = false;
                        break;
                    }
                    tmp = s[j] - '0';
                }
            }
            if (tmp != -1) {
                (tmp == 0 ? zer : one)++;
            }
        }
        if (max(zer, one) > k / 2) {
            chk = false;
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}

/////////
/////////////////

/// p4

    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int N = 1e5 + 5;
    int n, a, b, da, db, depth[N];
    vector<int> adj[N];
    int diam = 0;
     
    int dfs(int x, int p) {
        int len = 0;
        for(int y : adj[x]) {
            if(y != p) {
                depth[y] = depth[x] + 1;
                int cur = 1 + dfs(y, x);
                diam = max(diam, cur + len);
                len = max(len, cur);
            }
        }
        return len;
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int te;
        cin >> te;
        while(te--) {
            cin >> n >> a >> b >> da >> db;
            for(int i = 1; i <= n; i++) adj[i].clear();
            for(int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            diam = 0;
            depth[a] = 0;
            dfs(a, -1);
            cout << (2 * da >= min(diam, db) || depth[b] <= da ? "Alice" : "Bob") << '\n';
        }
    }











