////////////  698
///////// A
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
    	int arr[n];
    	int maxx = 0;
    	unordered_map<int,int> mp;
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		mp[arr[i]]++;
    		maxx = max(maxx, mp[arr[i]]);
    	}
    	cout<<maxx<<endl;
    }
    return 0;
}
///////// B
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
    	long long dp[101], arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	for(int i=0; i<90; i++){
    		dp[i] = 0;
    	}
    	dp[d] = 1;
    	for(int i=0; i<100; i++){
    		if(i >= d*10 or i%10==d or i%d==0){
    			dp[i] = 1;	
    		} 
    		if(dp[i]==1){
    			for(int j=i; j<100; j+=d){
    				dp[j] = 1;
    			}
    		}
    	}
    	dp[0] = 0;
    	for(int i=0; i<n; i++){
    		if(arr[i]>=90){
    			cout<<"YES"<<endl;
    		}
    		else if(dp[arr[i]]==1){
    			cout<<"YES"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
    return 0;
}
//////////// C

#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=200007;
int t;
int n,a[maxn],b[maxn],d[maxn];
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=0;i<2*n;++i) cin>>a[i];
        sort(a,a+2*n,greater<int>());
        for (int i=0;i<n;++i){
            if (a[i*2]!=a[i*2+1]){
                cout<<"NO\n";
                goto cont;
            }
            b[i]=a[i*2];
        }
        for (int i=1;i<n;++i){
            if (b[i-1]==b[i]||(b[i-1]-b[i])%(2*(n-i))){
                cout<<"NO\n";
                goto cont;
            }
            d[i]=(b[i-1]-b[i])/2/(n-i);
        }
        for (int i=1;i<n;++i){
            b[n-1]-=2*i*d[i];
        }
        if (b[n-1]<=0||b[n-1]%(2*n)) cout<<"NO\n";
        else cout<<"YES\n";
 
        cont:;
    }
    return 0;
}
/////////// D

#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=200007;
int t;
int n,k;
int x[maxn];
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i=0;i<n;++i) cin>>x[i];
        sort(x,x+n);
        int g=0;
        for (int i=1;i<n;++i){
            g=__gcd(g,x[i]-x[0]);
        }
        if ((k-x[0])%g) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}

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