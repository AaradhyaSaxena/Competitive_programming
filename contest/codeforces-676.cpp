/////////////////////

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
    	ll a,b; cin>>a>>b;
    	ll mn = min(a,b);
    	cout<<((mn^a) + (mn^b))<<endl;
    }
    return 0;
}

/////////////////////


// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){

//     }
//     return 0;
// }

/////////////////////