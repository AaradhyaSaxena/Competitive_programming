// // // //// Find product

// #include<iostream>
// using namespace std;

// int main() {
// int t;
// 	cin>>t;
//     int a[10],b[10],rem,i=0,m=0,flag;
//     for (int j=0; j<t; j++){
// 		cin>>b[j];
// 		//// Dealing with zeros
// 		if(b[j]==0){
// 			b[j]=1;
// 		}
// 	}
//     flag = b[0];
	
// 	while(flag!=0)  {
//     	rem = flag%10;
//     	a[i] = rem;
//     	flag = flag/10;
//     	i++;  
//     	m++;
//     } 
 
//     int temp,x=0,index=0;
//     for(i=1;i<t;i++)  {
//     	temp = 0;
//     	for(index=0;index<m;index++) {
//         	x = a[index]*b[i] + temp;
//         	a[index] = x%10;
//         	temp = x/10;
//         }
  
//     	while(temp!=0) {
//         	a[index] = temp % 10;
//         	temp = temp/10;
//         	index++;
//         	m++;
//     	}
//     }
 
// 	while(m--){
// 		int j =0;
// 		cout<<a[j];
// 		j++;
// 		}
//     cout<<"\n";
  
// 	return 0;
// }

////////////////////

// #include<iostream>
// using namespace std;
 
// int main(){
//   long long int n, pr =1;
//   cin>>n;
//   long long int b[1000] = {0};
//   for(int i=0; i<n; i++){
//     cin>>b[i];
// 	//// Dealing with zeros
// 	if(b[i]==0){
// 	    b[i]=1;
// 	}
//     pr = pr*b[i];
//   }
//   cout<<pr;
//   return 0;
// }
////////////////

// #include <stdio.h>

// int main(){
//     long int ans;
//     int n;
//     scanf("%d",&n);
//     int a[n];
//     int i;
//     for(i=0;i<n;i++)
//     {
//     	scanf("%d",&a[i]);
//     }
//     ans=1;
//     for(i=0;i<n;i++)
//     {
//     	ans = (ans*a[i]) % (1000000007);
//     }
//     printf("%ld",ans);
//     return 0;
// }