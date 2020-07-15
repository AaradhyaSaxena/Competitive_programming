// #include<iostream>
// using namespace std;

// int max(int a[], int n){
// 	int m = a[0];
// 	for(int i=1; i<n; i++){
// 		if(m<a[i]){
// 			m = a[i];
// 		}
// 	}
// 	return m;
// }

// void countingSort( int a[], int aux[], int sortA[], int n){
// 	int k = max(a,n);

// 	for(int i=0; i<=k; i++){
// 		aux[i] = 0;
// 	}

// 	for(int i=0; i<n; i++){
// 		aux[a[i]]++;
// 	}

// 	int j = 0;
// 	for (int i=0; i<=k; i++){
// 		int temp = aux[i];
// 		while(temp--){
// 			sortA[j] = i;
// 			j++;
// 		}
// 	}
// }

// void countSort(int arr[], int n, int exp) 
// { 
//     int output[n]; // output array 
//     int i, count[10] = {0}; 
  
//     // Store count of occurrences in count[] 
//     for (i = 0; i < n; i++) 
//         count[ (arr[i]/exp)%10 ]++; 
  
//     // Change count[i] so that count[i] now contains actual 
//     //  position of this digit in output[] 
//     for (i = 1; i < 10; i++) 
//         count[i] += count[i - 1]; 
  
//     // Build the output array 
//     for (i = n - 1; i >= 0; i--) 
//     { 
//         output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
//         count[ (arr[i]/exp)%10 ]--; 
//     } 
  
//     // Copy the output array to arr[], so that arr[] now 
//     // contains sorted numbers according to current digit 
//     for (i = 0; i < n; i++) 
//         arr[i] = output[i]; 
// } 

// void radixSort( int a[], int n){
// 	int mx = max(a, n);

// 	for( int exp=1; mx/exp>0; exp *= 10){
// 		countSort(a, n, exp);
// 		for(int i=0; i<n; i++){
// 			cout<<a[i]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }

// int main(){
// 	int n, i;
// 	cin>>n;
// 	int a[n];
// 	for(i=0; i<n; i++){
// 		cin>>a[i];
// 	}
// 	radixSort(a, n);
// 	////Prints for all values of exp
// }