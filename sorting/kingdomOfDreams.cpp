// #include<iostream>
// using namespace std;

// void bubble_sort( int A[ ], int n ) {
//     int temp;
//     for(int k = 0; k< n-1; k++) {
//         for(int i = 0; i < n-k-1; i++) {
//             if(A[ i ] > A[ i+1] ) {
//                 temp = A[ i ];
//                 A[ i ] = A[ i+1 ];
//                 A[ i + 1] = temp;
//             }
//         }
//     }
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n,min=0,min1=0;
// 		cin>>n;
// 		int a[n];
// 		for(int i=0;i<n;i++){
// 			cin>>a[i];
// 		}
// 		bubble_sort(a,n);
		
// 		for(int i=0; i<(n/2)-1; i++){
// 			if( 2*a[1] < a[0] + a[n-2-(2*i)]){
// 				min += a[0] + 2*a[1] + a[n-1-(2*i)];
// 			}
// 			else{
// 				min += 2*a[0] + a[n-1-(2*i)] + a[n-2-(2*i)];
// 			}
// 		}
// 		if(n%2==0){
// 			min += a[1];
// 		}
// 		else
// 			min += a[0]+ a[1]+ a[2];

// 		cout<<min<<"\n";
// 	}
// }