	// #include<bits/stdc++.h>
	// using namespace std;

// int main(){
// 	int t;
// 	cin>>t;
// 	long double arr[t];
// 	vector<int> vec;
// 	vector<int> integers;
// 	int cnt = 0, ans = 0, dec;
// 	for(int i=0; i<t; i++){
// 		cin>>arr[i];
// 		if(arr[i]==int(arr[i])){
// 			integers.push_back(arr[i]);
// 			cnt++;
// 		}else{
// 			dec = arr[i] - floor(arr[i]);
// 			if(int(1/dec) == 1/dec){
// 				vec.push_back(1/dec);
// 			}
// 		}
// 	}
// 	ans = cnt*(cnt - 1)/2;

// 	for(int i=0; i<integers.size(); i++){
// 		for(int j=0; j<vec.size(); j++){
// 			if(integers[i]%vec[j]==0){
// 				ans++;
// 			}
// 		}
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }

