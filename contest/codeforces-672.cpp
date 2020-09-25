///// codeforces-672

////// p1

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
    	int n; 
    	cin>>n;
    	int arr[n], brr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		brr[i] = arr[i];
    	}
    	sort(brr, brr+n);
    	int flag = 0;
    	for(int i=0; i<n; i++){
    		if(arr[i] != brr[n-1-i]){
    			flag = 1;
    		}
    	}
    	for(int i=1; i<n; i++){
    		if(brr[i] == brr[i-1]){
    			flag = 0;
    			break;
    		}
    	}

    	if(flag==0){
    		cout<<"NO"<<endl;
    	}else{
    		cout<<"YES"<<endl;
    	}
    }
    return 0;
}

///// p3

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
    	int n, k; 
    	cin>>n>>k; 
    	ll arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	
    	ll ans = 0;
    	ans += arr[0];
    	for(int i=1; i<n; i++){
    		ans += max(0, arr[i]-arr[i-1]);
    	}
    	cout<<ans<<endl;
    }
    return 0;
}


////// p2

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
    	ll n; cin>>n;
    	ll arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	ll bit[32];
    	for(int i=0; i<32; i++){
    		bit[i] = 0;
    	}

    	for(int i=0; i<n; i++){
    		for(int j=31; j>=0; j--){
    			if(arr[i] & (1<<j)){
    				bit[j]++;
    				break;
    			}
    		}
    	}
    	ll cnt = 0;

    	for(int i=0; i<32; i++){
    		if(bit[i]>0){
    			cnt += bit[i]*(bit[i]-1)/2; /// signed integer overflow
    			// cnt += (bit[i]/2)*(bit[i]-1); // this does not work
    		}
    	}
    	ll cnt_zero = 0;
    	for(int i=0; i<n; i++){
    		if(arr[i]==0) cnt_zero++;
    	}
    	cnt += cnt_zero*(cnt_zero-1)/2;

    	cout<<cnt<<endl;
    }
    return 0;
}

///// p4

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
    	int n, k; 
    	cin>>n>>k; 
    	ll arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	
    	ll ans = 0;
    	ans += arr[0];
    	for(int i=1; i<n; i++){
    		ans += max(0, arr[i]-arr[i-1]);
    	}
    	cout<<ans<<endl;
    	while(k--){
    		ll l ,r;
    		cin>>l>>r;
    		ll temp = arr[l];
    		arr[l] = arr[r];
    		arr[r] = temp;
    		ll ans = 0;
    		ans += arr[0];
    		for(int i=1; i<n; i++){
    			ans += max(0, arr[i]-arr[i-1]);
    		}
    		cout<<ans<<endl;
    	}
    }
    return 0;
}

/////// editorial

#include<iostream>
using namespace std;
#define int long long
int a[1000000+5];
int n;
int ans=0;

inline void insert(int i)
{
    if (i==0||i==n+1) return;
    if (a[i-1]<a[i] && a[i]>a[i+1]) ans+=a[i];
    if (a[i-1]>a[i] && a[i]<a[i+1]) ans-=a[i];
}

inline void erase(int i)
{
    if (i==0||i==n+1) return;
    if (a[i-1]<a[i] && a[i]>a[i+1]) ans-=a[i];
    if (a[i-1]>a[i] && a[i]<a[i+1]) ans+=a[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int q;
        cin>>n>>q;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        a[0]=-1;
        a[n+1]=-1;
        ans=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i-1]<a[i]&&a[i]>a[i+1]) ans+=a[i];
            if (a[i-1]>a[i]&&a[i]<a[i+1]) ans-=a[i];
        }
        cout<<ans<<'\n';
        while (q--)
        {
            int l,r;
            cin>>l>>r;
            erase(l-1);
            erase(l);
            erase(l+1);
            if (l!=r)
            {
                if (r-1!=l+1&&r-1!=l) erase(r-1);
                if (r!=l+1) erase(r);
                erase(r+1);
            }
            swap(a[l],a[r]);
            insert(l-1);
            insert(l);
            insert(l+1);
            if (l!=r)
            {
                if (r-1!=l+1&&r-1!=l) insert(r-1);
                if (r!=l+1) insert(r);
                insert(r+1);
            }
            cout<<ans<<'\n';
        }
    }
}


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