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

// int main(){
// 	int n;
// 	cin>>n;
// 	int a[n], sortA[n];
// 	for(int i=0; i<n; i++){
// 		cin>>a[i];
// 	}
// 	int k = max(a,n);
// 	int aux[k+1];
// 	countingSort(a, aux, sortA, n);
// 	int i=0;
// 	while(i<n){
// 	    cout<<sortA[i]<<" "<<aux[sortA[i]]<<endl;
// 	    i = i+aux[sortA[i]];
// 	}
// 	return 0;
// }