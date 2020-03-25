// #include<iostream>
// #include<stdio.h>
// using namespace std;

// int scan(){
//     register int c = getchar_unlocked();
//     register int n = 0;
//     for( ; (c<48 || c>57); c = getchar_unlocked() );
//     for( ; (c>47 && c<58); c = getchar_unlocked() ){
//         n = (n<<1) + (n<<3) +c -48;
//     }
//     return n;
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	int s;
// 	s = scan();
// 	while(s--){
// 		int n,r;
// 		n = scan(); r = scan();
// 		int h[n];
// 		for(int i=0;i<n;i++){
// 			h[i] = scan();
// 		}
// 		int max = h[0];
// 		int count=1;
// 		for(int i=0;i<n;i++){
// 			if(h[i]>max){
// 				max=h[i];
// 				count++;
// 				// cout<<count<<"\n";
// 			}
// 		}
// 		cout<<count*r<<"\n";
// 	}

// }