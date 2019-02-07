// #include<iostream>
// using namespace std;

// void bubble_sort( int A[ ], int n ) {
//     int temp;
//     for(int k = 0; k< n-1; k++) {
//         // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

//         for(int i = 0; i < n-k-1; i++) {
//             if(A[ i ] > A[ i+1] ) {
//                 // here swapping of positions is being done.
//                 temp = A[ i ];
//                 A[ i ] = A[ i+1 ];
//                 A[ i + 1] = temp;
//             }
//         }
//     }
// }

//     int main()
//     {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int t;
//         cin>>t;
//         while(t--)
//         {
//             int n,m;
//             cin>>n>>m;
//             int a[n];
//             for(int i=0;i<n;i++)
            
//             {
//                 cin>>a[i];
//             }
//             bubble_sort(a, n);
//             int y=n-m;
//             int p=0,q=0;
//             for(int i=0,j=n-1;i<n-m;i++,j--)
//             {
//                p+=a[i];
//                q+=a[j];
//             }
//             cout<<q-p<<"\n";
            
//         }
//     }
