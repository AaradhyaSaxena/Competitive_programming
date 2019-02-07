// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		long long int z,n,i,flag=0,res;
// 		cin>>z>>n;
// 		int a[1000005];
// 		for(i=0;i<n;i++){
// 			cin>>a[i];
// 		}
// 		res= z&a[0];
// 		for(i=1;i<n;i++){
// 			if(res==0){
// 				flag=1;
// 				break;
// 			}
// 			else{
// 				res=res&a[i];
// 				if(res==0){
// 					flag=1;
// 					break;
// 				}
// 			}

// 		}
// 		if(flag==1){
// 			cout<<"Yes"<<"\n";
// 		}
// 		else{
// 			cout<<"No"<<"\n";
// 		} 
// 	}
// }