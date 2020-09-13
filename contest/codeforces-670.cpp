/////////https://codeforces.com/contests/1406

//// p1

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
    	int A[101] = {0};
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    		A[arr[i]]++;
    	}
    	int sum = 0, flag = 0;
    	for(int i=0; i<=100; i++){
    		if(flag==2){
    			break;
    		}
    		if(A[i]==0 and flag==0){
    			sum += 2*i;
    			flag =2;
    			break;
    		}
    		if(A[i]==1 and flag==0){
    			sum += i;
    			flag = 1;
    		}
    		if(A[i]==0 and flag==1){
    			sum += i;
    			flag=2;
    			break;
    		}
    	}
    	cout<<sum<<endl;
    }
    return 0;
}

////////////////

//// p2

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
    	for(ll i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	sort(arr, arr+n);
    	ll ans = arr[0]*arr[1]*arr[2]*arr[3]*arr[4];
    	if(n==5){
    		cout<<ans<<endl;
    	}
    	else{
    		ans = max(ans,arr[n-5]*arr[n-4]*arr[n-3]*arr[n-2]*arr[n-1]);
    		ans = max(ans,arr[0]*arr[1]*arr[n-3]*arr[n-2]*arr[n-1]);
    		ans = max(ans,arr[0]*arr[1]*arr[2]*arr[n-2]*arr[n-1]);
    		ans = max(ans,arr[0]*arr[1]*arr[2]*arr[3]*arr[n-1]);
    		cout<<ans<<endl;
    	}
    }
    return 0;
}

//////////////

////// p3 /// incorrect

#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long int ll;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, x, y; 
    	cin>>n;
    	int arr[n+1][2];
    	vector<int> gr[n+1];
    	for(int i=1; i<n; i++){
    		cin>>x>>y;
    		arr[i][0] = x;
    		arr[i][1] = y;
    		gr[x].push_back(y);
    		gr[y].push_back(x);
    	}
    	int dp[n] = {0};
    	int maxx = INT_MIN;
    	for(int i=1; i<=n; i++){
    		dp[i] = gr[i].size();
    		maxx = max(maxx,dp[i]);
    	}
    	int cnt = 0;
    	vector<int> centroid;
    	for(int i=1; i<=n; i++){
    		if(dp[i]==maxx){
    			cnt++;
    			centroid.push_back(i);
    		}
    	}
    	int flag = 0;
    	if(cnt==1){
    		cout<<arr[1][0]<<" "<<arr[1][1]<<endl;
    		cout<<arr[1][0]<<" "<<arr[1][1]<<endl;
    	}
    	else{
    		for(int i=0; i<centroid.size(); i++){
    			for(int j=i+1; j<centroid.size(); j++){
    				for(int k=0; k<gr[centroid[i]].size(); k++){
    					if(gr[centroid[i]][k]==centroid[j]){
    						cout<<centroid[i]<<" "<<centroid[j]<<endl;
    						if(k != 0) cout<<gr[centroid[i]][k-1]<<" "<<centroid[j]<<endl;
    						else cout<<gr[centroid[i]][k+1]<<" "<<centroid[j]<<endl;
    						flag =1;
    						break;
    					}
    					if(flag==1) break;
    				}
    				if(flag==1) break;
    			}
    			if(flag==1) break;
    		}
    	}
    }
    return 0;
}

///// p3 editorial

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, size[100005], fa[100005], minn=1e9, cent1, cent2;
vector<int> g[100005];
void dfs(int x,int f){
    fa[x]=f,size[x]=1;
    int mx=0;
    for(int y:g[x]){
        if(y==f)continue;
        dfs(y,x);
        size[x]+=size[y];
        mx=max(mx,size[y]);
    }
    mx=max(mx,n-size[x]);
    if(mx<minn)minn=mx,cent1=x,cent2=0;
    else if(mx==minn)cent2=x;
}

int S;

void dfs2(int x,int f){
    if(g[x].size()==1){
        S=x;
        return ;
    }
    for(int y:g[x]){
        if(y==f)continue;
        dfs2(y,x);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n,cent1=cent2=0,minn=1e9;
        for(int i=1;i<=n;i++) g[i].clear(),fa[i]=0;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y), g[y].push_back(x);
        }
        dfs(1,0);
        if(!cent2){
            printf("1 %d\n1 %d\n",g[1][0],g[1][0]);
            continue;
        }
        if(fa[cent1] != cent2) swap(cent1, cent2);
        dfs2(cent1, cent2);
        printf("%d %d\n%d %d\n",S,fa[S],S,cent2);
    }
    return 0;
}

/////////// p4

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int sumg = 0, suml = 0;
    for(int i=1; i<n; i++){
        if(a[i]>a[i-1]) sumg += a[i] - a[i-1];
        else suml += a[i-1] - a[i];
    }
    long long int ans = ceil((double)(a[0]+sumg)/2.0);
    cout<<ans<<endl;

    int q; cin>>q;
    while(q--){
        int l, r, x, a1 = a[0];
        cin>>l>>r>>x;

        for(int i=l-1; i<r; i++){
            a[i] += x;
        }
        sumg = 0, suml = 0;
        for(int i=1; i<n; i++){
            if(a[i]>a[i-1]) sumg += a[i] - a[i-1];
            else suml += a[i-1] - a[i];
        }
        ans = ceil((double)(a[0]+sumg)/2.0);
        cout<<ans<<endl;
    }
}

///////////

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

///////////////////

