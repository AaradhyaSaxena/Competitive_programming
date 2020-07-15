// #include<iostream>
// using namespace std;

// int bubble_sort( int a[], int n){
// 	int temp;
// 	int flag =1;
// 	for(int k=0; k<n; k++){
// 		for(int i=0; i<n-k-1; i++){
// 			if(a[i] - a[i+1] > 1){
// 				temp = a[i];
// 				a[i] = a[i+1]+ 1;
// 				a[i+1] = temp - 1;
// 			}
// 			else if(a[i] - a[i+1] == 1){
// 				flag = 0;
// 				return flag;
// 			}
// 		}
// 	}
// 	return flag;
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n, flag;
// 		cin>>n;
// 		int a[n];
// 		for(int i=0; i<n; i++){
// 			cin>>a[i];
// 		}
// 		flag = bubble_sort(a, n);
// 		if(flag==1){
// 			cout<<"YES\n";
// 			for(int i=0; i<n; i++){
// 				cout<<a[i]<<" ";
// 			}
// 			cout<<"\n";
// 		}
// 		else if(flag==0){
// 			cout<<"NO\n";
// 		}
// 	}
// }

////////////////////
////////////////////

// #include<iostream>
// using namespace std;

// // int bubble_sort( int a[], int n){
// // 	int temp;
// // 	int flag =1;
// // 	for(int k=0; k<n; k++){
// // 		for(int i=0; i<n-k-1; i++){
// // 			if(a[i] - a[i+1] > 1){
// // 				temp = a[i];
// // 				a[i] = a[i+1]+ 1;
// // 				a[i+1] = temp - 1;
// // 			}
// // 			else if(a[i] - a[i+1] == 1){
// // 				flag = 0;
// // 				return flag;
// // 			}
// // 		}
// // 	}
// // 	return flag;
// // }

// int merge( int a[], int start, int mid, int end, int flag){
//     int p = start, q = mid +1;
//     int arr[end - start + 1], k= 0;
//     for(int i=0; i<end; i++){
//         if(p>mid){
//             arr[k++]= a[q++];}
//         else if(q>end){
//             arr[k++] = a[p++] -1;}
//         else if(a[p] - a[q]>1){
//             arr[k++] = a[p++];}
// 		else if(a[p] - a[q] == 1){
// 			flag = 0;
// 			return flag;}
//         else{
//             arr[k++] = a[q++] + 1;}
//     }
//     for(int p=0; p<k; p++){
//         a[start++] = arr[p];
//     }
//     return flag;
// }

// int merge_sort( int a[], int start, int end, int f){
//     if(start<end){
//         int mid = (start + end)/2;
//         f = merge_sort(a, start, mid, f);
//         f = merge_sort(a, mid+1, end, f);
    
//         f = merge(a, start, mid, end, f);
//     }
//     return f;
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n, flag=1;
// 		cin>>n;
// 		int a[n];
// 		for(int i=0; i<n; i++){
// 			cin>>a[i];
// 		}
// 		flag = merge_sort(a, 0, n-1, flag);
// 		if(flag==1){
// 			cout<<"YES\n";
// 			for(int i=0; i<n; i++){
// 				cout<<a[i]<<" ";
// 			}
// 			cout<<"\n";
// 		}
// 		else if(flag==0){
// 			cout<<"NO\n";
// 		}
// 	}
// }
//////////////////
//////////////////

/////////////////////
// #include<iostream>
// using namespace std;

// // int bubble_sort( int a[], int n){
// // 	int temp;
// // 	int flag =1;
// // 	for(int k=0; k<n; k++){
// // 		for(int i=0; i<n-k-1; i++){
// // 			if(a[i] - a[i+1] > 1){
// // 				temp = a[i];
// // 				a[i] = a[i+1]+ 1;
// // 				a[i+1] = temp - 1;
// // 			}
// // 			else if(a[i] - a[i+1] == 1){
// // 				flag = 0;
// // 				return flag;
// // 			}
// // 		}
// // 	}
// // 	return flag;
// // }

// int merge( int a[], int start, int mid, int end, int flag){
//     int p = start, q = mid +1;
//     int arr[end - start + 1], k= 0;
//     for(int i=0; i<end; i++){
//         if(p>mid){
//             arr[k++]= a[q++];}
//         else if(q>end){
//             arr[k++] = a[p++] -1;}
//         else if(a[p] - a[q]>1){
//             arr[k++] = a[p++];}
// 		else if(a[p] - a[q] == 1){
// 			flag = 0;
// 			return flag;}
//         else{
//             arr[k++] = a[q++] + 1;}
//     }
//     for(int p=0; p<k; p++){
//         a[start++] = arr[p];
//     }
//     return flag;
// }

// int merge_sort( int a[], int start, int end, int f){
//     if(start<end){
//         int mid = (start + end)/2;
//         f = merge_sort(a, start, mid, f);
//         f = merge_sort(a, mid+1, end, f);
    
//         f = merge(a, start, mid, end, f);
//     }
//     return f;
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n, flag=1;
// 		cin>>n;
// 		int a[n];
// 		for(int i=0; i<n; i++){
// 			cin>>a[i];
// 		}
// 		flag = merge_sort(a, 0, n-1, flag);
// 		if(flag==1){
// 			cout<<"YES\n";
// 			for(int i=0; i<n; i++){
// 				cout<<a[i]<<" ";
// 			}
// 			cout<<"\n";
// 		}
// 		else if(flag==0){
// 			cout<<"NO\n";
// 		}
// 	}
// }

// ////////////////////
// ///quick bubble_sort/////////
// //////////////////////
// #include<iostream>
// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;

// int partition( ll arr[], int start, int end, int flag){
// 	int i = (start-1);
// 	int temp;
// 	int piv = end;
// 	for(int j= start; j<= end-1; j++){
// 		if(arr[piv] - arr[j] > 1){
// 			i++;
// 			temp = arr[i];
//             arr[i] = arr[j] +1;
//             arr[j] = temp -1;
// 			// swap(&arr[i], &arr[j]);
// 		}
// 		else if(arr[piv] - arr[j] = 1){
// 			flag = 0;
// 		}
// 	}
// 	// swap(&arr[i+1], &arr[end]);
// 	temp = arr[i+1];
//     arr[i+1] = arr[end];
//     arr[end] = temp;
// 	return (i+1);
// }

// void quick_sort( ll a[], int start, int end){
// 	if( end > start ){
// 		int pvtpos = partition( a, start, end, flag);
// 		quick_sort(a, start, pvtpos-1);
// 		quick_sort(a, pvtpos+1, end);
// 	}
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n, flag=1;
// 		cin>>n;
// 		int a[n];
// 		for(int i=0; i<n; i++){
// 			cin>>a[i];
// 		}
// 		flag = merge_sort(a, 0, n-1, flag);
// 		if(flag==1){
// 			cout<<"YES\n";
// 			for(int i=0; i<n; i++){
// 				cout<<a[i]<<" ";
// 			}
// 			cout<<"\n";
// 		}
// 		else if(flag==0){
// 			cout<<"NO\n";
// 		}
// 	}
// }