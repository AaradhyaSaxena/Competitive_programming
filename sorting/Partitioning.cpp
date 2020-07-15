// #include<iostream>
// using namespace std;

// void bubble_sort_mod(int b[][2],int n){
// 	int temp,temp1;
// 	for(int k=0;k<n-1;k++){
// 		for(int i=0;i<n-k-1;i++){
// 			if( (b[i][0]) > (b[i+1][0])){
// 				temp = b[i][0];
// 				b[i][0] = b[i+1][0];
// 				b[i+1][0] = temp;
// 				temp1 = b[i][1];
// 				b[i][1] = b[i+1][1];
// 				b[i+1][1] = temp1;
// 			}
// 			if(b[i][0] == b[i+1][0]){
// 			    b[i][1] += b[i+1][1];
// 			    b[i+1][1] = 0;
// 			}
// 		}
// 	}
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n,flag=0;
// 		cin>>n;
// 		int a[n][3], b[n][2];
// 		for(int i=0;i<n;i++){
// 			for(int j=0;j<3;j++){
// 				cin>>a[i][j];
// 			}
// 		}
// 		for(int i=0;i<n;i++){
// 		    b[i][0] = a[i][0] - a[i][1];
// 		    b[i][1] = a[i][2];
// 		}
		
// 		bubble_sort_mod(b,n);
// // 		for(int i=0;i<n;i++){
// // 		    cout<<b[i][1];
// // 		}
// 		int sum, tsum=0;
// 		for(int i=0;i<n;i++){
// 		    tsum += b[i][1];
// 		}

// 		for(int i=0;i<n;i++){
// 		    sum=0;
// 			for(int j=0;j<i;j++){
// 				sum += b[j][1];
// 			}

// 			//// Dealing with the collinear points

// 			// int l=1; coll=b[i][1];
// 			// if( i-l>=0 && (b[i][1] == b[i-l][1])){
// 			// 	coll += b[i-l][1];
// 			// 	l++;
// 			// }
// 			// l=1;
// 			// if( i+l<=n && (b[i][1] == b[i+l][1])){
// 			// 	coll += b[i+l][1];
// 			// 	l++;
// 			// }

// 			// if( (sum == tsum - sum ) || (sum == tsum - sum - coll)) {
// 			// 	flag=1;
// 			// 	break;
// 			// }

// 			if( (sum == tsum - sum ) || (sum == tsum - sum - b[i][1])) {
// 				flag=1;
// 				break;
// 			}
// 		}
// 		if(flag==0){
// 			cout<<"NO\n";
// 		}
// 		else{
// 			cout<<"YES\n";
// 		}
// 	}
// 	return 0;
// }