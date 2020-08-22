// ///////// 

// #include<bits/stdc++.h> 
// #define endl '\n'
// using namespace std;
     
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int k, n, t;
//     cin >> t;
//     for(;t--;){
//         cin >> n >> k;
//         if(n < k)
//             cout << k - n << endl;
//         else if(n % 2 == k % 2)
//             cout << 0 << endl;
//         else
//             cout << 1 << endl;
//     }
//     return 0;
// }

/////// p2

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		ll x1,y1,z1,x2,y2,z2;
// 		cin>>x1>>y1>>z1;
// 		cin>>x2>>y2>>z2;

// 		ll sum = 0, zero = 0;
// 		sum += 2*min(z1,y2);
// 		z1 = max(z1-y2,zero);
// 		y2 = max(y2-z1,zero);

// 		z2 = max(z2-x1,zero);
// 		z2 = max(z2-z1,zero);
// 		sum -= 2*min(z2,y1);

// 		cout<<sum<<endl;
// 	}
// }

/////// p3

// #import<bits/stdc++.h>
// #define endl '\n'

// using namespace std;
// int a[100005], x[100005], y[100005];

// main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int t;
//     cin >> t;
//     while(t--){
// 		int k = 0, m = 1000000000, n;
// 		cin >> n;
// 		for(int i = 1; i <= n; i++){
// 		    cin >> a[i];
// 		    m = min(m, a[i]);
// 		}
// 		for(int i = 1; i <= n; i++){
// 		    if(a[i] % m == 0){
// 				x[k] = i;
// 				y[k] = a[i];
// 				k++;
// 		    }
// 		}
// 		sort(y, y + k);
// 		for(int i = 0; i < k; i++){
// 			a[x[i]] = y[i];
// 		}
// 		for(int i = 1, k = 0; i < n; i++){
// 			if(a[i] > a[i+1]){
// 				k = 1;
// 			}
// 		}
// 		if(k){
// 			cout<<"NO"<<endl;
// 		}
// 		else{
// 			cout<<"YES"<<endl;
// 		}
//     }
// }












