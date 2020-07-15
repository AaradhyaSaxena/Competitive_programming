// #include<iostream>
// #include<stdio.h>
// using namespace std;

// int main(){
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         int r,flag=1;
//         cin>>r;
// /////// The next line is important
//         char mat[r][r];
// /////// int mat[r][r];

//         for(int i=0;i<r;i++){
//             for(int j=0;j<r;j++){
//                 cin>>mat[i][j];
//             }
//         }
//         //// along vertical axis
// 		for(int i=0;i<r;i++){
// 			for(int j=0;j<r/2;j++){
// 				if(mat[i][j] != mat[i][r-1-j]){
// 					flag =0;
// 					break;
// 				}
// 			}
// 			if(flag==0){
// 				break;
// 			}
// 		}
// 		// along horizontal axis
// 		for(int j=0;j<r;j++){
// 			for(int i=0;i<r/2;i++){
// 				if(mat[i][j] != mat[r-1-i][j]){
// 					flag =0;
// 					break;
// 				}
// 			}
// 			if(flag==0){
// 				break;
// 			}
// 		}
// 		if(flag==0){
// 			cout<<"NO\n";
// 		}
// 		else
// 			cout<<"YES\n";   
//     }
//     return 0;
// }

//// In the question, the input does not have spaces in between different numbers of the array
//// so when we use int mat[][] then it takes the whole first line as a single entry, but when we use char mat[][] the different letters of each line are taken as single entries