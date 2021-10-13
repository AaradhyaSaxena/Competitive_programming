#include<iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int partition ( int A[],int start ,int end) {
    int i = start + 1;
    int piv = A[start] ;                        //make the first element as pivot element.
    for(int j=start+1; j<= end ; j++ )  {       //rearrange the array by putting elements which are less than pivot
        if ( A[ j ] < piv) {                    //on one side and which are greater that on other.
            swap (A[ i ],A [ j ]);
            i += 1;
        }
    }
    swap(A[start], A[i-1]) ;         //put the pivot element in its proper place.
    return i-1;                      //return the position of the pivot
}

void quick_sort (int A[], int start, int end) {
    if( start < end ) {
        int piv_pos = partition(A, start, end) ; //stores the position of pivot element    
        quick_sort (A, start, piv_pos -1);       //sorts the left side of pivot.
        quick_sort ( A, piv_pos+1, end) ;        //sorts the right side of pivot.
    }
}

int main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	quick_sort(a,0,n-1);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
    cout<<endl;
	return 0;
}