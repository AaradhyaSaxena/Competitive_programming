// #include<iostream>
// #include<stdio.h>
// using namespace std;


// int scan(){
//     register int c = getchar_unlocked();
//     register int n = 0;
//     for( ; (c<48 || c>57); c = getchar_unlocked() );
//     for( ; (c>47 && c<58); c = getchar_unlocked() ){
//         n = (n<<1) + (n<<3) +c -48;
//     }
//     return n;
// }

// int main(){
//     int r,c;
//     r = scan();
//     c = scan();
//     // cin>>r>>c;
//     int mat[r][c];
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             mat[i][j] = scan();
//             // cin>>mat[i][j];
//         }
//     }
//     for(int i=0;i<c;i++){
//         for(int j=0;j<r;j++){
//             cout<<mat[j][i]<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }