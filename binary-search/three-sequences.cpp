////////https://codeforces.com/contest/1406/problem/D
//// https://codeforces.com/blog/entry/82560

///// three sequences

//// editorial solution
// #include<cstdio>
// #include<cmath>
// #define re register
// #define int long long
// using namespace std;

// inline int read(){
// 	re int t=0,f=0;re char v=getchar();
// 	while(v<'0')f|=(v=='-'),v=getchar();
// 	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
// 	return f?-t:t;
// }

// int n, a[100002], sumg, suml, a1, A, B, C, q;

// inline int check(){
// 	return ceil((double)(a1+sumg)/2.0);
// }

// inline void cg(re int x, re int y){
// 	if(x>n) return;
// 	a[x] > 0 ? sumg -= a[x] : suml += a[x];
// 	a[x] += y;
// 	a[x] > 0 ? sumg += a[x] : suml -= a[x];
// }

// signed main(){

//    	n=read();
   	
//    	for(re int i=1; i<=n; ++i) a[i] = read();
//    	for(re int i=2; i<=n; ++i){
//    		if(a[i]>a[i-1]) sumg += a[i]-a[i-1];
//    		else suml += a[i-1]-a[i];
//    	}
//    	for(re int i=n; i; --i) a[i] = a[i]-a[i-1];
//    	a1 = a[1];

//    	printf("%lld\n",check());
   	
//    	q=read();
   	
//    	while(q--){
//    		re int l=read(), r=read(), x=read();
//     	if(l==1) a1 += x;
//     	else cg(l,x);
//     	cg(r+1, -x);
//     	printf("%lld\n",check());
//     }
// }

////////////////////////
///////////////////////
//////////// slower

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; 
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int sumg = 0, suml = 0;
	for(int i=1; i<n; i++){
		if(a[i]>a[i-1]) sumg += a[i] - a[i-1];
		else suml += a[i-1] - a[i];
	}
	long long int ans = ceil((double)(a[0]+sumg)/2.0);
	cout<<ans<<endl;

	int q; cin>>q;
	while(q--){
		int l, r, x, a1 = a[0];
		cin>>l>>r>>x;

		for(int i=l-1; i<r; i++){
			a[i] += x;
		}
		sumg = 0, suml = 0;
		for(int i=1; i<n; i++){
			if(a[i]>a[i-1]) sumg += a[i] - a[i-1];
			else suml += a[i-1] - a[i];
		}
		ans = ceil((double)(a[0]+sumg)/2.0);
		cout<<ans<<endl;
	}
}
//////////////////////
























/////////////

/*
Since sequence 𝑏 is non-decreasing and sequence 𝑐 is non-increasing, we need to mimimize max(𝑐1,𝑏𝑛).

Now observe that if 𝑎𝑖 > 𝑎𝑖−1 then  𝑏𝑖 = (𝑏𝑖−1)+ 𝑎𝑖 − (𝑎𝑖−1) and  𝑐𝑖 = (𝑐𝑖−1).
Else if  𝑎𝑖 < 𝑎𝑖−1 then 𝑏𝑖 = 𝑏𝑖−1 but 𝑐𝑖 = 𝑐𝑖−1 + 𝑎𝑖 − 𝑎𝑖−1. 

Now we calculate ∑𝑖 = 2𝑛 max(0, 𝑎𝑖 − 𝑎𝑖−1). Let this sum be 𝐾. Now lets assume 𝑐1 is 𝑥. So then 𝑏1 is 𝑎1 − 𝑥. 
And as observed before  𝑏𝑛 = 𝑎1 − 𝑥 + 𝐾.

Now we just need to minimize max (𝑥 , 𝑎1 − 𝑥 + 𝐾). Now it is easily observable that 𝑥 should be 𝑎1 + 𝐾2.

For the changes, since we only need to know ∑max(0, 𝑎𝑖 − 𝑎𝑖−1), so only 𝑎𝑙 − 𝑎𝑙−1 and 𝑎𝑟 − 𝑎𝑟−1 will change.

Total time complexity: 𝑂(𝑛 + 𝑞).

*/



