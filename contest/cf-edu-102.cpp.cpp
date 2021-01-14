/////////////////// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, d; cin>>n>>d;
    	int arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);
        if(arr[n-1]<=d){
            cout<<"YES"<<endl;
        }
        else if(arr[0]+arr[1]<=d){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    	
    }
    return 0;
}

/////////////////// B

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int x = a.length(), y = b.length();
        int z = x*y/(__gcd(x,y));
        string c; int flag =0;
        for(int i=0;i<z;i++){
            if(a[i%x]!=b[i%y]) flag =1;
            else c += a[i%x];
        }
        if(flag==0) cout<<c<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}

//////////////// D

//// incorrect
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;
     
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
            int dmax = dp[n][0]-dp[min(r+1,n)][0], dmin = dp[n][1]-dp[min(r+1,n)][1];
            cout<<"dmax = "<<dmax<<"\t"<<"dmin = "<<dmin<<endl;

            maxx = dp[l-1][0]; minn = dp[l-1][1];
            cout<<"maxx = "<<maxx<<"\t"<<"minn = "<<minn<<endl;

            if(r<n){
                x += (dp[max(l,0)][2] - dp[min(n,r)][3]);
                cout<<"x = "<<x<<endl;
                maxx = max(maxx, x+dmax), minn = min(minn, x+dmin);
            }

            cout<<"maxx = "<<maxx<<"\t"<<"minn = "<<minn<<endl;
            cout<<maxx-minn+1<<endl;
        }
    }
    return 0;
}
////////////////////////

#include <stdio.h>
#define N   200000
 
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
 
int main() {
    int t;
  
    scanf("%d", &t);
    while (t--) {
        static char cc[N + 1];
        static int pp[N], ppl[N], ppr[N], qql[N], qqr[N];
        int n, m, i, p, l, r;
 
        scanf("%d%d", &n, &m);
        scanf("%s", cc);
        p = 0;
        for (i = 0; i < n; i++) {
            p += cc[i] == '+' ? 1 : -1;
            pp[i] = p;
            ppl[i] = min(i == 0 ? 0 : ppl[i - 1], p), ppr[i] = max(i == 0 ? 0 : ppr[i - 1], p);
        }
        l = 0, r = 0;
        for (i = n - 1; i >= 0; i--) {
            l += cc[i] == '+' ? 1 : -1, r += cc[i] == '+' ? 1 : -1;
            l = min(l, 0), r = max(r, 0);
            qql[i] = l, qqr[i] = r;
        }
        while (m--) {
            int l, r, p, pl, pr, ql, qr;
 
            scanf("%d%d", &l, &r), l--, r--;
            if (l == 0)
                p = pl = pr = 0;
            else
                p = pp[l - 1], pl = ppl[l - 1], pr = ppr[l - 1];
            if (r + 1 == n)
                ql = qr = 0;
            else
                ql = qql[r + 1], qr = qqr[r + 1];
            printf("%d\n", max(pr, p + qr) - min(pl, p + ql) + 1);
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
