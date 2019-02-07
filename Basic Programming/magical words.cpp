// #include<iostream>
// #include<cmath>
// using namespace std;

// int prime(int a);
// int convert(int a);
// // int main(){
// // 	int t,n;
// // 	string s;
// // 	cin>>t;
// // 	while(t--){
// // 		cin>>n;
// // 		cin>>s;
// // 		int a[500] ={0};
// // 		for (int i=0;i<n;i++){
// // 			a[i] = int(s[i]);
// // 			if(!prime(a[i])){
// // 				a[i] = convert(a[i]);
// // 			}
// // 		}
// // 		for(int i=0;i<n;i++){
// // 			cout<<char(a[i]);
// // 		}
// // 	}
// // }
// int main(){
// 	int a,b,c;
// 	cin>>a>>b>>c;
// 	if(prime(a)){
// 		cout<<"ddsfd";
// 	}
// }

// int prime(int a){
// 	int n,r =0;
// 	for(int i=2;i*i<n;i++){
// 		if(a%i==0){
// 			r= 1;
// 		}
// 	}
// 	return r;
// }

// int convert(int a){
// 	int clone,bigger,smaller;
// 	for(int i=0;i<20;i++){
// 		if(prime(a+i)){
// 			bigger = a+i;
// 			break;
// 		}
// 	}
// 	for(int i=0;i<20;i++){
// 		if(prime(a-i)){
// 			smaller = a-i;
// 			break;
// 		}
// 	}
// 	if(abs(a-smaller)<=abs(bigger-a)){
// 		clone = smaller;
// 	}
// 	else 
// 		clone = (bigger);
// 	return clone;
// }