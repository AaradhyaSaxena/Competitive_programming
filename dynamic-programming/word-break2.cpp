////https://practice.geeksforgeeks.org/problems/word-break-part-2/0/

#include <bits/stdc++.h>
#define endll "\n";
using namespace std;

set<string> ss;
unordered_map<string,int> mp;

bool iscur(string s){
    return mp.find(s)!=mp.end();
}

void f(int i,int n,string s,string cur,string ans){
    cur+=s[i];
    if(i==n){
        if(iscur(cur)){
            ans+=cur;
            ss.insert(ans);
        }
        return;
    }
    if(iscur(cur)){
        f(i+1,n,s,"",ans+cur+" ");
    }
    f(i+1,n,s,cur,ans);
    return;
    
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        ss.clear();mp.clear();
        int n;cin>>n;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            mp[s]++;
        }
        cin>>s;
        f(0,s.length()-1,s,"","");
        for(auto it=ss.begin();it!=ss.end();it++){
            cout<<"("<<*it<<")";
        }
        cout<<endll;
    }
    return 0;
}

///////////////////////

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n;
// 		cin>>n;
// 		unordered_map<string,int> mp;
// 		string s, temp_s;
// 		for(int i=0; i<n; i++){
// 			cin>>s;
// 			mp[s] = 1;
// 		}
// 		cin>>s;
// 		int len = s.length();
// 		vector<vector<string>> vec;
// 		vector<string> temp;
// 		int dp[len+1];
// 		memset(dp,0,sizeof(dp));
// 		dp[0] =1;
// 		for(int i=1; i<=len; i++){
// 			for(int j=i-1; j>=0; j--){
// 				temp_s = s.substr(j, i-j);
// 				if(mp.find(temp_s) != mp.end()){
// 					dp[i] |= dp[j];
// 					temp.push_back(temp_s);
// 					if(i==len){
// 					    vec.push_back(temp);
// 					    temp.pop_back();
// 					}
// 				}
// 			}
// 		}
// 		for(int i=len; i>0; i--){
// 			for(int )
// 		}


// 		for(int i=0; i<vec.size(); i++){
// 		    cout<<"(";
// 		    for(int j=0; j<vec[i].size(); j++){
// 		        cout<<vec[i][j];
// 		        if(j!=vec[i].size()-1) cout<<" ";
// 		    }cout<<")";
// 		}
// 	}
// }

