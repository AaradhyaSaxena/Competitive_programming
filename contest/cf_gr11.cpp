/////// global round 11


//// p1

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
    	int sum = 0;
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		sum += arr[i];
    	}
    	if(sum==0){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    		sort(arr,arr+n);
    		int flag = 0;
    		sum = 0;
    		for(int i=0; i<n; i++){
    			sum += arr[i];
    			if(sum==0){
    				flag = 1;
    				break;
    			}
    		}
    		if(flag==0){
    			for(int i=0; i<n; i++){
    				cout<<arr[i]<<" ";
    			}cout<<endl;
    		}
    		if(flag==1){
    			for(int i=n-1; i>=0; i--){
    				cout<<arr[i]<<" ";
    			}cout<<endl;
    		}
    	}
    }
    return 0;
}

/////////////////// p2

///// logical mistake

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int helper(string str, int start, int end, int k){
	int l = r = i = start;
	int L=start, R=start;
	int maxx = 0;
	while(i<end){
		if(k==0 and str[i]=='L'){
			while(str[l]=='W'){
				l++;
			}
			if(str[l]=='L'){
				l++;
				k++;
			}
		}
		if(str[i]=='L'){
			k--;
		}
		if((r-l+1) > maxx){
			maxx = r-l+1;
			L = l; R = r;
		}
		r++;
		i++;	
	}

	while(arr[L]=='L'){
		L++;
		k++;
		maxx--;
	}
	while(arr[R]=='L'){
		R--;
		k++;
		maxx--;
	}

	int pts = 0;
	for(int i=0; i<L; i++){
		if(str[i]=='W' and (i==0 or str[i-1]=='L')){
			pts += 1;
		}
		if(str[i]=='W' and str[i-1]=='W'){
			pts += 2;
		}
	}
	for(int i=R+1; i<n; i++){
		if(str[i]=='W' and (i==0 or str[i-1]=='L')){
			pts += 1;
		}
		if(str[i]=='W' and str[i-1]=='W'){
			pts += 2;
		}
	}
	// cout<<"maxx "<<maxx<<endl;
	// cout<<"others "<<pts<<endl;
	// cout<<L<<" "<<R<<endl;
	pts += max(0,(2*maxx -1));
	return pts;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin>>n>>k; 
    	string str;
    	cin>>str;
    	int ans = 0;
    	ans = helper(str,0,n,k);
    	cout<<ans<<endl;
    }
    return 0;
}

////// after hint

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int helper(string str, int n, int k){
	vector< pair<int,pair<int,int>> > vec;


	int start = 0, end = n-1;
	// while(str[start]=='L'){
	// 	start++;
	// }
	// while(str[end]=='L'){
	// 	end--;
	// }

	int i=start;
	int gap = 0;
	int l = start, r = start;
	while(i<=end){
		if(str[i]=='W'){
			r = i-1;
			vec.push_back({gap,{start,end}});
			gap==0;
			l = i+1;
		}
		if(str[i]=='L'){
			gap++;
		}
		i++;
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<vec.size(); i++){
		int gap = vec[i].first;
		// cout<<gap<<endl;
		if(gap==0){
			continue;
		}
		int left = vec[i].second.first;
		int right = vec[i].second.second;
		if(gap > 0 and gap<=k){
			k = k - gap;
			cout<<"yo";
			for(int i=left; i<=right; i++){
				str[i]='W';
			}
		}
	}
	int ans = 0;
	if(str[0]=='W') ans +=1;
	for(int i=1; i<n; i++){
		if(str[i]=='W' and (str[i-1]=='W')){
			ans += 2;
		}
		if(str[i]=='W' and (str[i-1]=='L')){
			ans += 1;
		}
	}
	return ans;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin>>n>>k; 
    	string str;
    	cin>>str;
    	int ans = 0;
    	for(int i=0; i<n; i++){
    		if(str[i]=='L'){
    			ans++;
    		}
    	}
    	if(ans <= k){
    		cout<<(2*n-1)<<endl;
    	}
    	else{
    		ans = helper(str,n,k);
    		cout<<ans<<endl;
    	}
    }
    return 0;
}

////// editorial

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
 
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        int winning_streaks_cnt = 0;
        int wins = 0;
        int losses = 0;
        vector<int> losing_streaks; 
        for (int i = 0; i < N; i++) {
            if (S[i] == 'W') {
                wins++;
                if (i == 0 or S[i-1] == 'L') winning_streaks_cnt++;
            }
            if (S[i] == 'L') {
                losses++;
                if (i == 0 or S[i-1] == 'W') losing_streaks.push_back(0);
                losing_streaks.back()++;
            }
        }
        if (K >= losses) {
            cout << 2*N-1 << "\n";
            continue;
        }
        if (wins == 0) {
            if (K == 0) cout << 0 << "\n";
            else cout << 2*K-1 << "\n";
            continue;
        }
        if (S[0] == 'L') losing_streaks[0] = 1e8;
        if (S[N-1] == 'L') losing_streaks.back() = 1e8;
        sort(losing_streaks.begin(), losing_streaks.end());
        wins += K;
        for (int ls: losing_streaks) {
            if (ls > K) break;
            K -= ls;
            winning_streaks_cnt--;
        }
        cout << 2*wins - winning_streaks_cnt << "\n";
    }
}

/////////////////// p3

//////

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
const int MAXN = 1e5 + 100;
int t[MAXN];
int x[MAXN], y[MAXN];
int ans[MAXN];
int max_ans[MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
 
    x[0] = 1, y[0] = 1;
 
    int R, N;
    cin >> R >> N;

    for (int i = 1; i <= N; i++) 
    {
        cin >> t[i] >> x[i] >> y[i];	
        ans[i] = -1e9;
        for (int j = max(i-2*R, 0); j < i; j++) 
        {
            if (abs(x[i]-x[j]) + abs(y[i]-y[j]) <= t[i]-t[j])
                ans[i] = max(ans[i], 1 + ans[j]);
        }
        if (i > 2*R) ans[i] = max(ans[i], 1 + max_ans[i-2*R]);
 
        max_ans[i] = max(ans[i], max_ans[i-1]);
    }
    cout << max_ans[N] << "\n";
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



