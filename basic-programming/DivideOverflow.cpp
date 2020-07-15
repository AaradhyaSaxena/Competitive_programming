//// Divide overflow
// ///////////////////
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll a[1000005];
// int main()
// {
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","wb",stdout);
    
//     for(ll i=1;i<=1000000;i++){
//         ll r=1;
//         for(ll j=1;j<=20;j++){
//             r=r*2;
//             if(r>i){
//                 break;
//             }
//         }
//         ll z= (i*r)-1;
//         a[i]=z;
//         //cout<<a[i]<<endl;
//     }
//     ll t,x;
//     cin>>t;
//     while(t--)
//     {
//         cin>>x;
//         ll id = lower_bound(a+1,a+1000000+1,x)-a;
//         cout<<(x-id+1)<<endl;
//     }
// }
// ///////////////////////////////

// // EXPLANATION:
// // We can precompute the maximum value of valid X for each divisor D. For each integer i, from 1 to 10^6, find the lowest integer which has no. of bits in its binary representation 1 greater than that of i. Let this integer be r. So we have int (log2(r)) = int (log2(i)) +1. This r is our quotient, to find the number X, multiply r and i. Thus r*i gives us the lowest invalid value for our divisor D. So the required value is (r*i-1) for each divisor D in our precomputed array.
// // Now for each test case we have to find maximum value of D which has value in the precomputed array lower than X. All other possible integers greater than this D and less than X are valid divisors. This count gives us our answer.

// ///////////////////////////////

// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define mp make_pair
// #define rep(i,a,b) for(int i=a;i<=b;i++)
// #define irep(i,a,b) for (int i=a;i>=b;i--)
// #define pii pair <int, int>
// #define pll pair <ll,ll>

// using namespace std;
// const int ma = 1e5+5;

// int bit(ll x)
// {
//   int ans=0;
//   while(x)
//   {
//     x/=2;
//     ans++;
//   }
//   return ans;
// }
// bool check(ll d, ll x)
// {
//   if(bit(x/d)<=bit(d))
//     return true;
//   return false;
// }

// ll solve(ll x)
// {
//   ll l =1, r = sqrt(x);
//   while(l<r)
//   {
//     ll m = (l+r)/2;
//     if(check(m,x))
//       r = m;
//     else
//       l = m+1;
//   }
//   if(!check(l,x))
//     return l+1;
//   else
//     return l;
// }

// int main(int argc, char* argv[])
// {
//   if(argc == 2 or argc == 3) 
//      freopen(argv[1], "r", stdin);
//   if(argc == 3) 
//      freopen(argv[2], "w", stdout);
//   ios::sync_with_stdio(false);
//   int t;
//   cin>>t;
//   assert(1<=t and t<=1e6);
//   rep(i,1,t)
//   {
//     ll x,ans=0;
//     cin>>x;
//     assert(1<=x and x<=1e12);
//     ll tp = solve(x);
    
//     cout<<x-tp+1<<endl;
//   }
  
//   return 0;
// }