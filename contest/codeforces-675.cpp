////////////////
//////////////

//////// cf 675

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
    	ll a,b,c; 
    	cin>>a>>b>>c;
    	ll ans = a+b+c-1;
    	cout<<ans<<endl;
    }
    return 0;
}

/////////////////////
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > mat(n,vector<int>(m));

	for(auto& e: mat){
		cin >> e;
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		int mir = (n - 1 - i);
		if (mir < i){
			break;
		}
		for(int j = 0; j < m; ++j){
			int mir = (m - 1 - j);
			if (mir < j){
				break;
			}
			set<pair<int,int>> pos;
 
			for(int a: {i, n - 1 - i}){
				for(int b: {j, m - 1 - j}){
					pos.insert({a,b});
				}
			}
 
			vector<int> vals;
			for(auto e: pos){
				vals.push_back(mat[e.first][e.second]);
			}
 
			sort(all(vals));
			if (vals.size() == 1){
				continue;
			}
			for(auto e: vals){
				ans += abs(e - vals[1]);
			}
		}
	}
	cout << ans << endl;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

/////////////////////

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

/////////////////////


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

/////////////////////