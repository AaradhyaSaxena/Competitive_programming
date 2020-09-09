////////// p1

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
//     	int n;
//     	cin>>n;
//     	int arr[n];
//     	int num1 = 0, num0 = 0;
//     	int sume = 0, sumo = 0;
//     	for(int i=0; i<n; i++){
//     		cin>>arr[i];
//     	}
//     	for(int i=0; i<n; i++){
//     		if(arr[i]==1) num1++;
//     		if(arr[i]==0) num0++;
//     		if(i%2==0) sume += arr[i];
//     		if(i%2==1) sumo += arr[i];
//     	}
//     	if(sume==sumo){
//     		cout<<n<<endl;
//     		for(int i=0; i<n; i++){
//     			cout<<arr[i]<<" ";
//     		}cout<<endl;
//     	}
//     	else{
//     		if(num0>=num1)
//     		{
//     			cout<<n/2<<endl;
//     			for(int i=0; i<n/2; i++){
//     				cout<<0<<" ";
//     			}cout<<endl;
//     		}
//     		else
//     		{
//     			cout<<n/2<<endl;
//     			for(int i=0; i<n/2; i++){
//     				cout<<1<<" ";
//     			}cout<<endl;
//     		}
//     	}
    		
//     }
//     return 0;
// }

///////////////////////////////

//// p2

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;

// int gcd(int m, int n) {
//     if(m < n){
//     	swap(m, n);
//     }
//     if(n == 0){
//     	return m;  	
//     }
//     return gcd(m % n, n);
// }
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//     	int n, x, index =0;
//     	cin>>n;
//     	vector<int> arr;
//     	int maxx = INT_MIN;
//     	for(int i=0; i<n; i++){
//     		cin>>x;
//     		arr.push_back(x);
//     		maxx = max(maxx, x);
//     		if(x==maxx) index = i;
//     	}
//     	vector<int> ans;
//     	ans.push_back(maxx);
//     	swap(arr[0],arr[index]);

//     	int temp = 0, prev = maxx, next = 0;
//     	maxx = INT_MIN;

//     	for(int i=1; i<n; i++){
//     		for(int j=i; j<n; j++)
//     		{
//     			temp = gcd(prev,arr[j]);
//     			if(temp>maxx){
//     				maxx = temp;
//     				next = arr[j];
//     				index = j;
//     			}
//     		}
//     		ans.push_back(next);
//     		prev = gcd(prev,next);
//     		maxx =INT_MIN;
//     		swap(arr[i],arr[index]);
//     	}
//     	for(int i=0; i<n; i++){
//     		cout<<ans[i]<<" ";
//     	}cout<<endl;
//     }
//     return 0;
// }

////////////////////////

/////// p4

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

bool canJump(ll start, ll end, ll arr[]){
	if(start + 1 == end){
		return true;
	}
	ll max_end = max(arr[start],arr[end]);
	ll min_end = min(arr[start],arr[end]);
	ll max_btw = INT_MIN, min_btw = INT_MAX;
	for(int i=start+1; i<end; i++){
		max_btw = max(max_btw,arr[i]);
		min_btw = min(min_btw,arr[i]);
	}
	if(min_end>max_btw) return true;
	if(max_end<min_btw) return true;

	return false;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; 
	cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++){
    	cin>>arr[i];
    }

    ll dp[n];
    for(ll i=0; i<n; i++){
    	dp[i] = INT_MAX;
    }
    dp[n-1] = 0;

	ll count = 0;
	for(ll i=n-2; i>=0; i--){
		ll minn = INT_MAX, temp=0;
		for(ll j=i+1; j<n; j++){
			if(canJump(i,j,arr)){
				// cout<<i<<" "<<j<<" "<<"yes"<<endl;
				temp = dp[j] + 1;
			}
			minn = min(minn,temp);
		}
		dp[i] = minn;
	}

	cout<<dp[0]<<endl;
}

/////////////

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

/////////////////////////

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
