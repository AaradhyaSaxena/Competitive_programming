////BYTELANDIAN////
//////// INCORRECT SOLUTION////
// #include <iostream>
// #define ll long long int
// using namespace std;

// ll memoi[100000000] ={0};

// ll byte(ll n){
// 	if(n<100000000){
// 		if(memoi[n] !=0)
// 			return memoi[n];
// 		else
// 			if(n<12)
// 				return n;
// 			else
// 				memoi[n] = (byte(n/2)+ byte(n/3)+ byte(n/4));
// 				return memoi[n];	
// 	}
// 	else{
// 		return (byte(n/2)+ byte(n/3)+ byte(n/4));
// 		}
// 	return 0;
// 	}

// int main() {
// 	ll n;
// 	while(!cin.eof()){
// 		cin>>n;
// 		cout<<byte(n)<<"\n";
// 	}
// }

//////RUNNING SOLUTION/////

// #include <iostream>
// #define ll long long int
// using namespace std;

// ll byte(ll n){
// 	if(n<12)
// 		return n;
// 	else
// 		return (byte(n/2)+ byte(n/3)+ byte(n/4));
// }

// int main() {
// 	ll n;
// 	while(!cin.eof()){
// 		cin>>n;
// 		cout<<byte(n)<<"\n";
// 	}
// 	return 0;
// }