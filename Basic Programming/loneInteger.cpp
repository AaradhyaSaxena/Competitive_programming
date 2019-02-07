// #include<iostream>
// using namespace std;
// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n, a, count =0;
// 		cin>>n;
// 		int A[n];
// 		for(int i=0;i<n;i++){
// 			cin>>A[i];
// 		}
// 		if(n%2==0){
// 			cout<<"-1"<<endl;
// 			continue;
// 		}
// 		for(int i=0;i<n;i++){
// 			if(A[i]>0){
// 				for(int j=i+1;j<n;j++){
// 					if((A[i]>0 && A[j]>0) && (A[i] == A[j])){
// 					A[i] = -1;
// 					A[j] = -1;
// 					count = count+2;
// 					}	
 
// 				}
// 			}
			
// 		}
// 		for(int i=0;i<n;i++){
// 			if(A[i]>0){
// 				cout<<A[i]<<endl;
// 			}
// 		}
// 		if(count == n)
//             cout<<"-1"<<endl;
// 	}
// }