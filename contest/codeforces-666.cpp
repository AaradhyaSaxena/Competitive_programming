///////////

///// codeforces 666

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
//     	vector<string> vec;
//     	string s1;
//     	for(int i=0; i<n; i++){
//     		cin>>s1;
//     		vec.push_back(s1);
//     	}
//     	int arr[26];
//     	for(int i=0; i<26; i++){
//     		arr[i] = 0;
//     	}
//     	for(int i=0; i<vec.size(); i++){
//     		for(int j=0; j<vec[i].length(); j++){
//     			arr[vec[i][j] - 'a']++;
//     		}
//     	}
//     	int flag = 0;
//     	for(int i=0; i<26; i++){
//     		if(arr[i]%n != 0){
//     			flag = 1;
//     			break;
//     		}
//     	}
//     	if(flag){
//     		cout<<"NO"<<endl;
//     	}else{
//     		cout<<"YES"<<endl;
//     	}
//     }
//     return 0;
// }

////////////////////////////

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

ll helper(ll n, ll r){
	ll sum = (pow(r,n) -1)/(r-1);
	return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin>>n;
	ll arr[n];
	ll sum = 0;
	for(ll i=0; i<n; i++)
	{
   		cin>>arr[i];
    	sum += arr[i];
    }
    sort(arr,arr+n);
    ll goclose = INT_MAX;
    ll index = 0;
    ll start = 1, end = sum;
    ll farr[n];
	ll ans = 0;
    while(start <= end)
    {
    	ll mid = (end+start)/2;
    	// cout<<start<<" "<<mid<<" "<<end<<endl;
    	// cout<<goclose<<" "<<helper(n, mid)<<endl;
    	// cout<<ans<<endl<<endl;
    	ans = 0;
    	for(ll i=0; i<n; i++){
			farr[i] = pow(mid	,i);
			ans += abs(farr[i] - arr[i]);
		}
		if(ans <= goclose){
    		goclose = ans;
    		index = mid;
    	}
    	if(goclose == 0){
    		break;
    	}
    	if(helper(n, mid) < sum){
    		start = mid+1;
    	}else{
    		end = mid-1;
    	}
    }
	cout<<ans<<endl;
    return 0;
}


/////////////////////////////

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

