///// codeforces-672

////// p1

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
//     	int arr[n], brr[n];
//     	for(int i=0; i<n; i++){
//     		cin>>arr[i];
//     		brr[i] = arr[i];
//     	}
//     	sort(brr, brr+n);
//     	int flag = 0;
//     	for(int i=0; i<n; i++){
//     		if(arr[i] != brr[n-1-i]){
//     			flag = 1;
//     		}
//     	}
//     	for(int i=1; i<n; i++){
//     		if(brr[i] == brr[i-1]){
//     			flag = 0;
//     			break;
//     		}
//     	}

//     	if(flag==0){
//     		cout<<"NO"<<endl;
//     	}else{
//     		cout<<"YES"<<endl;
//     	}
//     }
//     return 0;
// }

/////


#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int max_value(int arr[], vector<int> &dp, int n){
	int sum = 0;
	int i = n-1;
	int index = n;
	while(i>0){
		int temp = 0;
		if(arr[i] > arr[i-1]){
			
			temp += arr[i];
			int minn = INT_MAX;

			for(int j=i; j<=index; j++){
				minn = min(minn, arr[j]);
			}
			temp -= minn;
			if(temp>0 and index-i>1){
				dp[i] = dp[index] + temp;
				index = i-1;
				i--;
			}
			else{
				dp[i] = dp[i+1];
				i--;
			}
		}else{
			dp[i] = dp[i+1];
			i--;
		}
	}
	if(index < 1){
		int minn = INT_MAX;
		for(int k=0; k<index; k++){
			minn = min(minn, arr[k]);
		}
		if(arr[0]-minn>0){
			dp[0] = dp[index] + arr[0]-minn;
		}
	}
	else{
		dp[0] = dp[1];
	}
	return dp[0];
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
    	int arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	vector<int> dp(n+2);
    	for(int i=0; i<n+2; i++){
    		dp[i] = 0;
    	}
    	cout<<max_value(arr,dp,n)<<endl;
    	for(int i=0; i<n; i++){
    		cout<<dp[i]<<" ";
    	}cout<<endl;
    }
    return 0;
}


//////

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
//     	int arr[n];
//     	for(int i=0; i<n; i++){
//     		cin>>arr[i];
//     	}
//     	int bit[32];
//     	for(int i=0; i<32; i++){
//     		bit[i] = 0;
//     	}

//     	for(int i=0; i<n; i++){
//     		for(int j=31; j>=0; j--){
//     			if(arr[i] & (1<<j)){
//     				bit[j]++;
//     				break;
//     			}
//     		}
//     	}
//     	int cnt = 0;

//     	for(int i=0; i<32; i++){
//     		if(bit[i]>0){
//     			cnt += bit[i]*(bit[i]-1)/2;
//     		}
//     	}
//     	int cnt_zero = 0;
//     	for(int i=0; i<n; i++){
//     		if(arr[i]==0) cnt_zero++;
//     	}
//     	cnt += cnt_zero*(cnt_zero-1)/2;

//     	cout<<cnt<<endl;
//     }
//     return 0;
// }
/////


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