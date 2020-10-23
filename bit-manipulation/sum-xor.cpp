///// https://www.geeksforgeeks.org/find-two-numbers-sum-xor/

//// Sum and XOR of number

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll s,x;
	cin>>s>>x;
	ll A =(s-x)/2;
	ll a = 0, b = 0;
	for(int i=0; i<64; i++){
		int xi = x&(1<<i);
		int Ai = A&(1<<i);
		if(Ai==0 and xi==0){
		}
		if(xi==0 and Ai>0){
			a = a|(1<<i);
			b = b|(1<<i);
		}
		if(xi>0 and Ai==0){
			a = a|(1<<i);
		}
		else{
			// cout<<"not possible"<<endl;
		}
	}
	cout<<a<<" "<<b<<endl;
}


//////////
/*
S = X + 2*A
where A = a AND b

We can verify above fact using the sum process. 
In sum, whenever we see both bits 1 (i.e., AND is 1), 
we make resultant bit 0 and add 1 as carry,
which means every bit in AND is left shifted by 1 OR value of AND is multiplied by 2 and added.

So we can find A = (S – X)/2.
Once we find A, we can find all bits of ‘a’ and ‘b’ using below rules.

If X[i] = 0 and A[i] = 0, then a[i] = b[i] = 0. Only one possibility for this bit.
If X[i] = 0 and A[i] = 1, then a[i] = b[i] = 1. Only one possibility for this bit.
If X[i] = 1 and A[i] = 0, then (a[i] = 1 and b[i] = 0) or (a[i] = 0 and b[i] = 1), we can pick any of the two.
If X[i] = 1 and A[i] = 1, result not possible (Note X[i] = 1 means different bits)

Let the summation be S and XOR be X.

Below is the implementation of above approach:



*/