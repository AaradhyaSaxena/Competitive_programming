///////codechef- august lunch

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

bool cmp(pair<int, int>& a, pair<int, int>& b) { 
    return a.second > b.second; 
} 

void sort(map<int, int>& M) { 
  
    vector<pair<int, int> > A; 
  	for (auto& it : M) { 
        A.push_back(it); 
    } 
    sort(A.begin(), A.end(), cmp);
} 
     
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n,m,x=0;
    	cin>>n>>m;
    	int arr[n][m+1];
    	for(int i=0; i<n; i++){
    		cin>>arr[i][0];
    	}
    	for(int i=0; i<n; i++){
    		for(int j=1; j<=m; j++){
    			cin>>x;
    			arr[i][j] = x + arr[i][j-1];
    		}
    	}
    	int dp[n][m+1];
    	memset(dp,0,sizeof(dp));

    	map<int,int> mp;
    	for(int j=1; j<=m; j++){
    		for(int i=0; i<n; i++){
    			mp[i] = arr[i][j];
    		}
    		sort(mp);
    		int max_rating=INT_MAX, rank = 0;
    		map<int,int>:: iterator itr;
    		int cnt = 0;
    		for(itr = mp.begin(); itr != mp.end(); ++itr){
    			cnt++;
    			if(itr->second == max_rating){
    				dp[itr->first][j] = rank;
    				max_rating = itr->second;
    			}else{
    				rank = cnt;
    				dp[itr->first][j] = rank;
    				max_rating = itr->second;
    			}    			
    		}
    	}
    	int ans = 0;
    	int result[n][2];
    	
    	for(int i=0; i<n; i++){
    		int rank = INT_MAX;
    		int rating = INT_MIN;
    		for(int j=1; j<=m; j++){
    			if(dp[i][j] < rank){
    				rank = dp[i][j];
    				result[i][0] = j;
    			}
    			if(arr[i][j] > rating){
    				rating = arr[i][j];
    				result[i][1] = j;
    			}
    		}
    		cout<<result[i][0]<<" "<<result[i][1]<<endl;
    		if(result[i][0] != result[i][1]){
    			ans++;
    		}
    	}
    	cout<<ans<<endl;
    	mp.clear();
    }
    return 0;
}


//// p2

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
    	vector<int> vec;
    	int cnt = 0;
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	for(int i=0; i<n; i++){
    		if(arr[i]==1){
    			if(cnt>0){
    				vec.push_back(cnt);
    			}
    			cnt =0;
    		}else{
    			cnt++;
    		}
    	}
    	vec.push_back(0);
    	sort(vec.begin(), vec.end());
    	int len = vec.size();
    	if(len>1){
    		int first = vec[len-1];
    		int second = vec[len-2];
    		if( (first%2 == 0) or (second >= (first/2) + 1)){
    			cout<<"No"<<endl;
    		}
    		else{
    			cout<<"Yes"<<endl;
    		}
    	}else{
    		cout<<"No"<<endl;
    	}
    	
    }
    return 0;
}
//////////
////////////

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
    	map<int,int> mp;
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		if(mp.find(arr[i]) == mp.end()){
    			mp[arr[i]] = 1;
    		}else{
    			mp[arr[i]]++;
    		}
    	}
    	map<int,int> freq;

    	map<int, int>::iterator itr; 
    	for (itr = mp.begin(); itr != mp.end(); ++itr) { 
    		if(freq.find(itr->second) == freq.end()){
    			freq[itr->second] = 1;
    		}else{
    			freq[itr->second]++;
    		}
    	}

    	int maxx = 0;
    	int ans = INT_MAX;
    	for(itr = freq.begin(); itr != freq.end(); ++itr){
    		if(itr->second == maxx){
    			maxx = itr->second;
    			ans = min(itr->first, ans);
    		}
    		if(itr->second > maxx){
    			maxx = itr->second;
    			ans = itr->first;
    		}
    	} 
    	cout<<ans<<endl; 
    }
    return 0;
}

///////////////////////////

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
//     }
//     return 0;
// }





