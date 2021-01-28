////////////  698
///////// A
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
    	int arr[n];
    	int maxx = 0;
    	unordered_map<int,int> mp;
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		mp[arr[i]]++;
    		maxx = max(maxx, mp[arr[i]]);
    	}
    	cout<<maxx<<endl;
    }
    return 0;
}
///////// B
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
    	int n, d; cin>>n>>d;
    	long long dp[101], arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	for(int i=0; i<90; i++){
    		dp[i] = 0;
    	}
    	dp[d] = 1;
    	for(int i=0; i<100; i++){
    		if(i >= d*10 or i%10==d or i%d==0){
    			dp[i] = 1;	
    		} 
    		if(dp[i]==1){
    			for(int j=i; j<100; j+=d){
    				dp[j] = 1;
    			}
    		}
    	}
    	dp[0] = 0;
    	for(int i=0; i<n; i++){
    		if(arr[i]>=90){
    			cout<<"YES"<<endl;
    		}
    		else if(dp[arr[i]]==1){
    			cout<<"YES"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
    return 0;
}
//////////// C

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
    	ll arr[2*n+1];
    	unordered_map<ll,ll> mp;
    	for(int i=0; i<2*n; i++){
    		cin>>arr[i];
    		if(mp.find(arr[i]) != mp.end()){
    			
    		}
    		mp[arr[i]] = 1;
    	}

    }
    return 0;
}
/////////////////

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
/////////////////

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