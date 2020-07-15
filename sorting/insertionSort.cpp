// #include<iostream>
// using namespace std;

// // void insertion_sort ( int A[ ] , int n) {
// //      for( int i = 0 ;i < n ; i++ ) {
// //       int temp = A[ i ];    
// //       int j = i;
// //           while(  j > 0  && temp < A[ j -1]) {
// //                 A[ j ] = A[ j-1];   
// //                 j= j - 1;
// //           }
// //           A[ j ] = temp;       
// //      }  
// // }

// void insertion_sort( int a[], int b[], int n){
//     for(int i=0;i<n;i++){
//         int temp = a[i];
//         int j = i;
//         while(j>0 && temp<a[j-1]){
//             b[a[j]] = j;
//             a[j] = a[j-1];
// 			b[a[j-1]] = j+1;
//             j = j-1;
//         }
//         a[j] = temp;
        
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     int a[n],o[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
// 		o[i] = a[i];
//     }
// ////////////////////    
//     // for(int i=0;i<n;i++){
//     //     cout<<a[i]<<" ";
//     // }
//     // cout<<endl;
// ////////////////////    
//     int b[1000];
// 	for(int i=0;i<n;i++){
// 		b[a[i]] = i+1;
// 	}
// //////////////////////////////////	
// // 	for(int i=0;i<n;i++){
// //         cout<<b[a[i]]<<" ";
// //     }
// //     cout<<endl;
// /////////////////////////////////	

//     insertion_sort(a,b,n);

// ///////////////////////////////////////    
// //     for(int i=0;i<n;i++){
// //         cout<<a[i]<<" ";
// //     }
// //     cout<<endl;
    
// // 	for(int i=0;i<n;i++){
// //         cout<<b[a[i]]<<" ";
// //     }
// //     cout<<endl;
    
// 	for(int i=0;i<n;i++){
// 		cout<<b[o[i]]<<" ";
// 	}
// 	cout<<"\n";
// }