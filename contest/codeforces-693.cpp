////////// codeforces 693

///// A

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

ll max(ll a, ll b){
    if(a>b)return a;
    else return b;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll w,h,n;
        cin>>w>>h>>n;
        ll cnt1=1, cnt2=1;
        while(w%2==0){
            cnt1 *= 2;
            w /=2;
        }
        while(h%2==0){
            cnt2 *= 2;
            h /=2;
        }
        if(cnt1*cnt2>=n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

/////////////// B

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
        int n; cin>>n;
        int temp = 0, c1 =0, c2 =0;
        for(int i=0; i<n; i++){
            cin>>temp;
            if(temp==1) c1++;
            else c2++;
        }
        if(c1%2==0 and c2%2==0) cout<<"YES"<<endl;
        else if(c2%2!=0 and c1==0) cout<<"NO"<<endl;
        else if(c1%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

///////////////
////C

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

ll helper(int n, vector<ll> vec){
    ll ans = 0;
    vector<ll> dp(n, 0);
    for(int i=n-1; i>=0; i--){
        dp[i] += vec[i];
        if(i+vec[i]<n){
            dp[i] += dp[i+vec[i]];
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
     
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin>>n;
        vector<ll> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        cout<<helper(n,vec)<<endl;
    }
    return 0;
}

///////////////
/// D

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
    ll arr[200005];
    while(t--){
        ll n; cin>>n; 
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        reverse(arr,arr+n);

        ll alice = 0, bob = 0;
        for(ll i=0; i<n; i++){
            if(i%2==0){
                if(arr[i]%2==0){
                    alice += arr[i];
                }
            }
            else{
                if(arr[i]%2 !=0){
                    bob += arr[i];
                }
            }
        }
        if(alice>bob){
            cout<<"Alice"<<endl;
        }
        else if(alice==bob){
            cout<<"Tie"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}

/////////////////
///// E

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
        ll n; cin>>n;
        ll h[n] , w[n];
        ll minhx=INT_MAX, minwy=INT_MAX;
        ll minhy=w[0], minwx=h[0];
        ll ih=0, iw=0;
        for(int i=0; i<n; i++){
            cin>>h[i]>>w[i];
            if(h[i]<minhx){
                minhx = h[i];
                ih = i;
                minhy = w[i];
            }
            if(w[i]<minwy){
                minwy = w[i];
                iw = i;
                minwx = h[i];
            }
        }
        for(int i=0; i<n; i++){
            ll temp1 = min(h[i],w[i]);
            ll temp2 = max(h[i],w[i]);
            if(temp1 > minhx and temp2 > minhy){
                cout<<ih+1<<" ";
            }else if(temp1 > minwy and temp2 > minwx){
                cout<<iw+1<<" ";
            }else{
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

/////////////////
/////////////////

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

/////////////////
