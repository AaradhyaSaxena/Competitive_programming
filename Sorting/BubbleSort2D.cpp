// #include<iostream>
// using namespace std;

// // int a[1000000][2];

// void bubble_sort(int a[][2],int n, int c){
// 	int temp,temp1;
// 	for(int k=0;k<n-1;k++){
// 		for(int i=0;i<n-k-1;i++){
// 			if(a[i][1]> a[i+1][1]){
// 				temp = a[i][1];
// 				temp1 = a[i][0];
// 				a[i][1] = a[i+1][1];
// 				a[i][0] = a[i+1][0];
// 				a[i+1][1] = temp;
// 				a[i+1][0] = temp1;
// 			}
// 		}
// 	}
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int n;
// 	cin>>n;
// 	int a[n][2];

// 	for(int i=0;i<n;i++){
// 		a[i][0] = i;
// 		cin>>a[i][1];
// 	}

// 	bubble_sort(a,n,1);
// 	for(int i=0;i<n;i++){
// 		cout<<a[i][0]<<" ";
// 	}
// 	cout<<"\n";

// }