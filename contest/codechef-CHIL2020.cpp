////// codechef CHIL2020

///prob1
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n, m, c, x, y;
// 	    cin>>n>>m>>c;
// 	    int cntp = 0, cntn =0;
// 	    for(int i=0; i<n; i++){
// 	        cin>>x>>y;
// 	        if(m*x + c -y> 0){
// 	            cntp++;
// 	        }
// 	        if(m*x + c -y< 0){
// 	            cntn++;
// 	        }
// 	    }
// 	    int ans = cntp*cntn;
// 	    cout<<ans<<endl;
// 	}
// 	return 0;
// }


/// prob2
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    string s;
// 	    cin>>s;
// 	    int ans = 0;
// 	    if(s[0]=='0'){
// 	    	cout<<0<<endl;
// 	    }
// 	    else{
// 	    	int flag = 0;
// 	    	for(int i=0; i<s.length(); i++){
// 	    		if(s[i]=='0'){
// 	    			ans++;
// 	    		}if(s[i]=='1' and ans!=0){
// 	    			break;
// 	    		}
// 	    	}
// 	    }
// 	    cout<<ans<<endl;
// 	}
// 	return 0;
// }

//////p3
// #include <iostream>
// using namespace std;

// int main() {
// 	int n, q;
// 	cin>>n>>q;
// 	int arr[n];
// 	for(int i=0; i<n; i++){
// 	    cin>>arr[i];
// 	}
// 	int inv[n];
// 	for(int i=0; i<n; i++){
// 	    inv[i] = 0;
// 	}
// 	for(int i=1; i<n; i++){
// 	    int cnt = 0;
// 	    for(int j=i-1; j>=0; j--){
// 	        if(arr[j]<arr[i] and inv[j]==0){
// 	            break;
// 	        }
// 	        if(arr[j]>arr[i]){
// 	            cnt++;
// 	        }
// 	    }
// 	    inv[i] = cnt;
// 	}
// 	int x,y,ans =0;
// 	for(int i=0; i<q; i++){
// 	    cin>>x>>y;
// 	    ans = 0;
// 	    for(int j=x-1; j<y; j++){
// 	        ans += inv[j];
// 	    }
// 	    cout<<ans<<endl;
// 	}
// 	return 0;
// }
/////p4

