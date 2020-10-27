///////////////////
/////////////// edu round 97


///// p1

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
    	ll l,r;
    	cin>>l>>r;
    	int flag = 0;
    	for(ll i=(2*(r-l)); i<r+3; i++){
    		if((l%i> i/2 or (l%i==i/2 and i%2==0)) and (r%i > i/2 or (r%i == i/2 and i%2==0))){
    			flag=1;
    			break;
    		}
    	}
    	if(flag==1){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}


///////////////////


/////// p2

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
    	string num;
    	cin>>num;
    	string str1 = "", str2 = "";
    	for(int i=0; i<n; i++){
    		if(i%2==0){
    			str1 += "1";
    			str2 += "0";
    		}
    		else{
    			str2 += "1";
    			str1 += "0";
    		}
    	}
    	cout<<str1<<" "<<str2<<endl;
    	for(int)





    	int num1 = 0, num2 = 0;
    	num1 = stoi(str1), num2 = stoi(str2);
    	int xor1, xor2;
    	xor1 = num^num1; xor2 = num^num2;
    	cout<<xor1<<" "<<xor2<<endl;
    	str1 = to_string(xor1), str2 = to_string(xor2);
    	cout<<str1<<" "<<str2<<endl;
    	int minn = INT_MAX, cnt = 0;
    	for(int i=1; i<str1.length(); i++){
    		if(str1[i] != str1[i-1]){
    			cnt++;
    		}
    	}
    	minn = cnt; cnt = 0;
    	for(int i=1; i<str2.length(); i++){
    		if(str2[i]!=str2[i-1]){
    			cnt++;
    		}
    	}
    	minn = min(minn, cnt);
    	cout<<minn<<endl;
    }
    return 0;
}

/////////////////////////////
///////////////////


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
    	string num; cin>>num;
    	string str1 = "", str2 = "";
    	for(int i=0; i<n; i++){
    		if(i%2==0){
    			str1 += "1";
    			str2 += "0";
    		}
    		else{
    			str2 += "1";
    			str1 += "0";
    		}
    	}

    	int state = 0;
    	int i=0, j=n-1;
    	int cnt = 0, minn = INT_MAX;

    	while(i<j){
    		if((num[i]==str1[i] and state==0) or (num[i]!=str1[i] and state==1)){
    			i++;
    			continue;
    		}
    		if((num[j]==str1[j] and state==0) or (num[j]!=str1[j] and state==1)){
    			j--;
    			continue;
    		}
    		if((num[i] != str1[i] and num[j] != str1[j] and state==0) or (num[i] == str1[i] and num[j] == str1[j] and state==1)){
    			state = 1-state;
    			i++; j--; cnt++;
    		}
    		else{

    		}
    	}
    	minn = cnt; state = 0;
    	i =0; j=n-1;
    	cnt = 0;
    	while(i<j){
    		if((num[i]==str2[i] and state==0) or (num[i]!=str2[i] and state==1)){
    			i++;
    			continue;
    		}
    		if((num[j]==str2[j] and state==0) or (num[j]!=str2[j] and state==1)){
    			j--;
    			continue;
    		}
    		if((num[i] != str2[i] and num[j] != str2[j] and state==0) or (num[i] == str2[i] and num[j] == str2[j] and state==1)){
    			state = 1-state;
    			i++; j--; cnt++;
    		}
    		else{

    		}
    	}
    	minn = min(minn,cnt);
    	cout<<minn<<endl;
    }
    return 0;
}

///////////////////

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
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	int cnt = 1;
    	for(int i=1; i<n; i++){
    		if(arr[i-1]>arr[i]) cnt++;
    	}
    	cout<<cnt<<endl;
    }
    return 0;
}

///////////////////

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
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);
    	
    }
    return 0;
}

///////////////////

