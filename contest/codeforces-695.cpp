//////// codeforces 695

/////// A

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
//     	int n; cin>>n;
//     	for(int i=0; i<n; i++){
//     		if(i%18 <= 9){
//     			cout<<(9-(i%18));
//     		}
//     		else{
//     			cout<<((i%18)-9);
//     		}
//     	}
//     	cout<<endl;
//     }
//     return 0;
// }

//////////////////
////////// B

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
    	int maxx = INT_MIN, minn = INT_MAX;
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		if(i!=0 and i!=n-1){
    			maxx = max(maxx, arr[i]);
    			minn = min(minn, arr[i]);
    		}
    	}

    	int cnt =0, ans = INT_MAX;
    	for(int i=1; i<n-1; i++){
    		if(arr[i]==maxx){
    			arr[i] = arr[i+1];
    		}
    		if((arr[i-1]<arr[i] and arr[i+1]<arr[i]) or (arr[i-1]>arr[i] and arr[i+1]>arr[i])){
    			cnt++;
    		}
    	}
    	ans = min(ans, cnt);
    	
    	cnt =0;
    	for(int i=1; i<n-1; i++){
    		if(arr[i]==minn){
    			arr[i] = arr[i+1];
    		}
    		if((arr[i-1]<arr[i] and arr[i+1]<arr[i]) or (arr[i-1]>arr[i] and arr[i+1]>arr[i])){
    			cnt++;
    		}
    	}
    	ans = min(ans, cnt);
    	
    	cnt =0;
    	for(int i=1; i<n-1; i++){
    		if((arr[i-1]<arr[i] and arr[i+1]<arr[i]) or (arr[i-1]>arr[i] and arr[i+1]>arr[i])){
    			cnt++;
    		}
    	}
    	ans = min(ans,max(cnt-1, 0));

    	cnt =0;
    	vector<bool> dp(n,false);
    	for(int i=1; i<n-1; i++){
    		if((arr[i-1]<arr[i] and arr[i+1]<arr[i]) or (arr[i-1]>arr[i] and arr[i+1]>arr[i])){
    			dp[i] = true;
    			cnt++;
    		}
    	}
    	for(int i=1; i<n-1; i++){
    		if(arr[i-1]==arr[i+1]){
    			if(dp[i-1]==true and dp[i+1]==true){
    				cnt -= 3;
    			}
    			else if(dp[i-1]==true or dp[i+1]==true){
    				cnt -= 2;
    			}
    		}
    	}
    	ans = min(ans, cnt);

    	cout<<max(cnt, 0)<<endl;
    }
    return 0;
}

/////////////////
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