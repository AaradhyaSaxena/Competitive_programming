//// Number of ordered pairs
////////////////////////////
// #include<iostream>
// #define ll long long int
// using namespace std;

// ll merge(ll A[ ] , ll start, ll mid, ll end, ll count) {
// 	ll p = start ,q = mid+1;
// 	ll Arr[end-start+1] , k=0;
// 	for(ll i = start ;i <= end ;i++) {
// 		if(p > mid)    
//     		Arr[ k++ ] = A[ q++] ;
// 		else if ( q > end)  
//     		Arr[ k++ ] = A[ p++ ];
// 		else if( A[ p ] <= A[ q ])   
//     		Arr[ k++ ] = A[ p++ ];
// 		else{
// 		    Arr[ k++ ] = A[ q++];
// 			count = count + (mid- p+ 1);
// 		}
// 	}
// 	for (ll p=0 ; p< k ;p ++) {
//     	A[ start++ ] = Arr[ p ] ;                          
// 	}
		
// 	return count;
// }

// ll merge_sort(ll a[], ll start, ll end, ll c){
// 	if(start<end){
// 		ll mid = (start + end)/2;

// 		c = merge_sort(a, start, mid, c);
// 		c = merge_sort(a, mid+1, end, c);

// 		c = merge(a, start, mid, end, c);
// 	}
// 	return c;
// }
// int main()
// {
// 	ll n;
// 	cin>>n;
// 	ll a[n];
// 	ll c=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>a[i];
// 	}
// 	c = merge_sort(a,0,n,c);
// 	cout<<c<<"\n";
// }