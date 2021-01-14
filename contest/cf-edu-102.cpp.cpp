/////////////////// A

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
//     	int n, d; cin>>n>>d;
//     	int arr[n];
//     	for(int i=0; i<n; i++){
//     		cin>>arr[i];
//     	}
//     	sort(arr,arr+n);
//         if(arr[n-1]<=d){
//             cout<<"YES"<<endl;
//         }
//         else if(arr[0]+arr[1]<=d){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
    	
//     }
//     return 0;
// }

/////////////////// B

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
// typedef long long int ll;

// int gcd(int m, int n) {
//     if(m < n) swap(m, n);
//     if(n == 0) return m;
//    return gcd(m % n, n);
// }

// int lcm(int a, int b){
//     return (a*b)/gcd(a,b);
// }

// string helper(string a, int n){
//     string ans = "";
//     for(int i=0; i<n; i++){
//         ans += a;
//     }
//     return ans;
// }

// int isDiv(string a, string b){
//     int n = a.length(), m = b.length();
//     if(n%m==0){
//         for(int i=0; i<m; i++){
//             if(a[i]!=b[i]){
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     else{
//         string nn = helper(a, m);
//         for(int i=0; i<n*m; i++){
//             if(nn[i]!=b[i%m]){
//                 return 0;
//             }
//         }
//         return 2;
//     }
// }
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//         string a, b;
//         cin>>a>>b;
//         int n = a.length(), m = b.length();
//         int gg = lcm(n,m), flag = 0;
//         for(int i=0; i<max(n,m); i++){
//             if(a[i%n]!=b[i%m]){
//                 flag = 1;
//                 cout<<-1<<endl;
//             }
//         }
//         if(flag==0){
//             if(n>m){
//                 if(isDiv(a,b)==2) cout<<helper(a,gg/n)<<endl;
//                 else if(isDiv(a,b)==1) cout<<a<<endl;
//                 else cout<<-1<<endl;
//             }
//             else{
//                 if(isDiv(b,a)==2) cout<<helper(b,gg/m)<<endl;
//                 else if(isDiv(b,a)==1) cout<<b<<endl;
//                 else cout<<-1<<endl;
//             }
//         }
//     }
//     return 0;
// }

// ///////////////// D

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//         int n,m; cin>>n>>m;
//         string str; cin>>str;
//         int arr[n];
//         for(int i=0; i<n; i++){
//             arr[i] = (str[i]=='+')? 1: -1;
//         }
//         for(int i=0; i<m; i++){
//             int l,r;
//             cin>>l>>r;
//             int minn = 0, maxx = 0, x=0;
//             for(int i=1; i<l; i++){
//                 x += arr[i-1];
//                 maxx = max(maxx, x); minn = min(minn, x);
//             }
//             for(int i=r+1; i<=n; i++){
//                 x += arr[i-1];
//                 maxx = max(maxx, x); minn = min(minn, x);
//             }
//             cout<<maxx-minn+1<<endl;
//         }
//     }
//     return 0;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,m; cin>>n>>m;
        string str; cin>>str;
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i] = (str[i]=='+')? 1: -1;
        }
        int gmin = 0, gmax =0, gx=0;
        int dp[n+5][4];
        for(int i=0; i<=n+1; i++){
            dp[i][0] = 0; dp[i][1] = 0;
            dp[i][2] = 0; dp[i][3] = 0;
        }
        for(int i=1; i<=n; i++){
            gx += arr[i-1];
            gmax = max(gmax, gx); gmin = min(gmin, gx);
            dp[i][0] = gmax; dp[i][1] = gmin;
            if(arr[i-1]==1) {
                dp[i][2] = dp[i-1][2]+1;
                dp[i][3] = dp[i-1][3];
            }
            if(arr[i-1]==-1){
                dp[i][3] = dp[i-1][3]+1;
                dp[i][2] = dp[i-1][2];
            } 
        }
        for(int j=0; j<4; j++){
            for(int i=0; i<=n; i++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
        for(int i=0; i<m; i++){
            int l,r;
            cin>>l>>r;
            int minn = 0, maxx = 0, x=0;
            int dmax = dp[n][0]-dp[min(r+1,n)][0], dmin = dp[min(r+1,n)][1]-dp[r+1][1];

            maxx = dp[l-1][0]; minn = dp[l-1][1];
            cout<<"maxx = "<<maxx<<"\t"<<"minn = "<<minn<<endl;

            x += (dp[l][2] - dp[r][3]);
            cout<<"x = "<<x<<endl;
            maxx = max(maxx, x+dmax), minn = min(minn, x+dmin);

            cout<<"maxx = "<<maxx<<"\t"<<"minn = "<<minn<<endl;
            cout<<maxx-minn+1<<endl;
        }
    }
    return 0;
}

// ///////////////////

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
//         int n; cin>>n;
//         int arr[n];
//         for(int i=0; i<n; i++){
//             cin>>arr[i];
//         }
//         sort(arr,arr+n);
        
//     }
//     return 0;
// }

// ///////////////////
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
//         int n; cin>>n;
//         int arr[n];
//         for(int i=0; i<n; i++){
//             cin>>arr[i];
//         }
//         sort(arr,arr+n);
        
//     }
//     return 0;
// }

///////////////////
