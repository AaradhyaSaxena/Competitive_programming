// #include<iostream>
// #define ll long long
// using namespace std;

// ll countbits(ll n){
//     ll count =0;
//     while(n){
//         n = n&(n-1);
//         count++;
//     }
//     return count;
// }

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

//     ll x;
//     while(!cin.eof())
////   
//     {
//         cin>>x;
//         cout<<countbits(x)<<"\n";
//     }
//     return 0;   
// }

///////FASTER////////
//// add cin.tie(NULL) below ios_base::sync_with_stdio(false)
//// also use "\n" instead of endl

// //////////////////
//  /// MYSTERY/////
// //////////////////
// #include<iostream>
// #define ll long long
// using namespace std;

// int main(){
//     ll n,a;
//     while(!cin.eof()){
//         cin>>n;
//         a = n&(n-1);
//         a = n^a;
//         cout<<a<<"\n";
//     }
    
// }