// #include<iostream>
// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;

// int partition( ll arr[], int start, int end){
// 	int i = (start-1);
// 	int temp;
// 	int piv = end;
// 	for(int j= start; j<= end-1; j++){
// 		if(arr[j] < arr[piv]){
// 			i++;
// 			temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
// 			// swap(&arr[i], &arr[j]);
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
// 		int pvtpos = partition( a, start, end);
// 		quick_sort(a, start, pvtpos-1);
// 		quick_sort(a, pvtpos+1, end);
// 	}
// }

// int main(){
// 	// ios_base::sync_with_stdio(false); cin.tie(NULL);

// 	int n;
// 	cin>>n;
// 	ll a[n];
// 	for(int i=0; i<n; i++){
// 		cin>>a[i];
// 	}
// 	quick_sort(a,0,n-1);
// 	for(int i=0; i<n; i++){
// 		cout<<a[i]<<" ";
// 	}
//     cout<<endl;
// 	return 0;
// }