/////


///// p1

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		ll n, sum=0; 
// 		cin>>n;
// 		ll arr[n];
// 		unordered_map<int,int> mp;
// 		for(int i=0; i<n; i++){
// 			cin>>arr[i];
// 			mp[arr[i]]++;
// 		}
// 		int maxx = 0;
// 		for(int i=0; i<n; i++){
// 			maxx = max(maxx, mp[arr[i]]);
// 		}
// 		if(maxx==n){
// 			cout<<n<<endl;
// 		} 
// 		else {
// 			cout<<1<<endl;
// 		}
// 	}
// }	

//// p1 b inc
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		ll n, sum=0; 
// 		cin>>n;
// 		ll arr[n];
// 		for(int i=0; i<n; i++){
// 			cin>>arr[i];
// 			sum += arr[i];
// 		}
// 		ll i = n-1, j = n-1, k=1;

// 		ll num = n;
// 		while(num--){
// 			j = i;
// 			while(j>0){
// 				k = 1;
// 				while( j-k >= 0 and arr[j]==-1){
// 					j--;
// 				}
// 				while(j-k >= 0 and arr[j-k]==-1){
// 					k++;
// 				}
// 				if(j-k >= 0 and arr[j] != arr[j-k]){
// 					arr[j-k] = arr[j-k] + arr[j];
// 					arr[j] = -1;
// 					if(arr[j-k]==sum){
// 						goto END;
// 					}
// 					j= j-k;
// 				}
// 				j--;
// 			}
// 			// i--;
// 		}
// 		END:;
// 		ll cnt = 0;
// 		for(int i=0; i<n; i++){
// 			// cout<<arr[i]<<" ";
// 			if(arr[i]>0) cnt++;
// 		}
// 		cout<<cnt<<endl;
// 	}
// }	


/////////// p2

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	long long int t;
// 	cin>>t;
// 	while(t--){
// 		long long int n, k, x, minn=INT_MAX, maxx=INT_MIN, flag = 0;
// 		cin>>n>>k;
// 		vector<long long int> vec1;
// 		for(int i=0; i<n; i++){
// 			cin>>x;
// 			vec1.push_back(x);
// 			minn = min(minn,x);
// 			maxx = max(maxx,x);
// 		}
// 		for(int i=0; i<n; i++){
// 			vec1[i] = maxx - vec1[i];
// 		}
// 		vector<long long int>vec2 = vec1;
// 		for(int i=0; i<n; i++){
// 			vec1[i] = (maxx-minn) - vec1[i];
// 		}
// 		if(k%2==0){
// 			for(int i=0; i<n; i++){
// 				cout<<vec1[i]<<" ";
// 			}cout<<endl;
// 		}else{
// 			for(int i=0; i<n; i++){
// 				cout<<vec2[i]<<" ";
// 			}cout<<endl;
// 		}
// 	}
// }

//// p3

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main(){
// 	ll t;
// 	cin>>t;
// 	while(t--){
// 		ll n;
// 		cin>>n;
// 		ll arr[n];
// 		for(int i=0; i<n; i++){
// 			cin>>arr[i];
// 		}
// 		ll cnt= 0;
// 		for(int i=n-1; i>0; i--){
// 			if(arr[i] < arr[i-1]){
// 				cnt += arr[i-1] - arr[i];
// 			}
// 		}
// 		cout<<cnt<<endl;
// 	}
// }

//// p4

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// bool issame(string str, int i){
// 	if(str[i] == str[i+1] and str[i+1] == str[i+2])
// 		return true;
// 	return false;
// }

// string flip(string str, int i){
// 	if(str[i] == 'L')
// 		str[i] = 'R';
// 	else
// 		str[i] = 'L';
// 	return str;
// }

// int main(){
// 	ll t;
// 	cin>>t;
// 	while(t--){
// 		ll n, r=0, l=0;
// 		cin>>n;
// 		string str;
// 		cin>>str;
// 		str += str[0];
// 		ll cnt = 0;

// 		if(str[0] == str[1] and str[0]==str[n-1]){
// 			str = flip(str,0);
// 			cnt++;
// 		}

// 		for(int i=0; i<n-2; i++){
// 			if(issame(str,i)){
// 				str = flip(str, i+1);
// 				cnt++;
// 			}
// 		}
// 		cout<<cnt<<endl;
// 	}
// }

/////p4b

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool issame(string str, int i){
	if(str[i] == str[i+1] and str[i+1] == str[i+2])
		return true;
	return false;
}

bool isValid(string str, int i){
	if((str[i-1]=='R' and str[i] =='L') or (str[i+1]=='L' and str[i]=='R') or (str[i-1]=='L' and str[i+1]=='R') or (str[i-1]=='R' and str[i+1]=='L'))
		return true;
	return false;
} 

string flip(string str, int i){
	if(str[i] == 'L')
		str[i] = 'R';
	else
		str[i] = 'L';
	return str;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n, r=0, l=0;
		cin>>n;
		string str;
		cin>>str;
		str += str[0];
		ll cnt = 0;

		if(str[0] == str[1] and str[0]==str[n-1]){
			str = flip(str,0);
			cnt++;
		}

		for(int i=1; i<n-1; i++){
			if(!isValid(str,i)){
				str = flip(str, i);
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}


