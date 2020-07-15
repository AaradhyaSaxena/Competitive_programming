// #include<iostream>
// using namespace std;

// int main(){
// 	int t;
// 	int a[15];
// 	cin>>t;
// 	while(t--){
// 		int n,s,flag=0;
// 		cin>>n;
// 		for(int i=0;i<n;i++){
// 			cin>>a[i];
// 		}
// 		cin>>s;
// 		////allPossibleSubSet///
// 		for(int i=0;i<(1<<n);i++){
// 			int sum=0;
// 			for(int j=0;j<n;j++){
// 				if(i & (1<<j)){
// 					sum = sum +a[j];
// 				}
// 			}
// 			if(sum==s){
// 				flag =1;
// 				break;
// 			}
// 		}
// 		if(flag == 1)
// 			cout<<"YES\n";
// 		else if(flag==0)
// 			cout<<"NO\n";
// 	}
// }