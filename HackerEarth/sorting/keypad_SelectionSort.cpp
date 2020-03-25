// #include<iostream>
// using namespace std;

// void selection_sort_rev( int A[ ], int n ) {
// 	int max,temp;
//     for(int i=0;i<n;i++){
// 		max = i;
// 		for(int j=i+1;j<n;j++){
// 			if(A[j]>A[max]){
// 				max=j;
// 			}
// 		}
// 		temp = A[i];
// 		A[i] = A[max];
// 		A[max] = temp;
// 	}
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int n;
// 	cin>>n;
// 	int a[n];
// 	for(int i=0;i<n;i++){
// 		cin>>a[i];
// 	}
// 	selection_sort_rev(a,n);
// 	/////////////////////
// // 	for(int i=0;i<n;i++){
// // 	    cout<<a[i];
// // 	}
// // 	cout<<endl;
// 	/////////////////////
// 	int c,count=0;
// 	cin>>c;
// 	int b[n] = {0};
// 	int check=0;
// 	for(int i=0;i<c;i++){
// 		cin>>b[i];
// 		check += b[i];
// 	}
// // 	for(int i=0;i<c;i++){
// // 	    cout<<b[i]<<"  ";
// // 	}
// // 	cout<<check;
    
//     int flag=1;
//     if(n > check){
//         flag=0;
//         // cout<<"flag = "<<flag<<endl;;
//     }
    
//     if(flag==1){
//         int k=0;
// 	    for(int i=0;i<n;i++){
// 		    for(int j=0; j<n; j++){
// 			    if(b[j]>0 && k !=n){
// 				    count = count + a[k]*(i+1);
// 				    k++;
// 				    // cout<<count<<endl;
// 				    b[j] = b[j] -1;
// 				    // cout<<b[j]<<endl;
// 			    }
// 		    }	
// 	    }
// 	    cout<<count<<"\n";
//     }
//     else 
//         cout<<"-1\n";
// }