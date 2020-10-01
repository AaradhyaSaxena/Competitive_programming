///////////https://codeforces.com/contest/1408

///// p1

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
int a[101][3];
int ans[101];

bool check_(int vec[], int n){
	if(vec[0] == vec[n-1]){
		return false;
	}
	for(int i=1; i<n; i++){
		if(vec[i]==vec[i-1]){
			return false;
		}
	}
	return true;
}

bool dfs(int i, int n){
	if(i==n and check_(ans,n)){
		return true;
	}

	for(int k=0; k<3; k++){
		if(i==0 or ans[i-1] != a[i][k]){
			ans[i] = a[i][k];
			bool res = dfs(i+1, n);
			if(res==true){
				return true;
			}
		}
	}
	return false;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n; cin>>n;
    	for(int i=0; i<n; i++) cin>>a[i][0];
    	for(int i=0; i<n; i++) cin>>a[i][1];
    	for(int i=0; i<n; i++) cin>>a[i][2];

    	for(int i=0; i<n+1; i++){
    		ans[i] = 0;
    	}
    	bool res = dfs(0,n);
    	for(int i=0; i<n; i++){
    		cout<<ans[i]<<" ";
    	}cout<<endl;
    }
    return 0;
}

////////// p1 brute

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

bool check_(int vec[], int n){
	if(vec[0] == vec[n-1]){
		return false;
	}
	for(int i=1; i<n; i++){
		if(vec[i]==vec[i-1]){
			return false;
		}
	}
	return true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n; cin>>n;
    	int a[n][3];
    	for(int i=0; i<n; i++) cin>>a[i][0];
    	for(int i=0; i<n; i++) cin>>a[i][1];
    	for(int i=0; i<n; i++) cin>>a[i][2];
    	int ans[n+2] = {0};
    	int flag = 0;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<3; j++){
    			ans[i] = a[i][j]; 
    			if(i==n-1 and check_(ans,n)==true){
    				flag = 1;
    				break;
    			}
    			if(flag==1) break;
    		}
    		if(flag==1) break;
    	}
    	for(int i=0; i<n; i++){
    		cout<<ans[i]<<" ";
    	}cout<<endl;
    }
    return 0;
}


///////////

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

//////////

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