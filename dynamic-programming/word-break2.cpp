//// https://practice.geeksforgeeks.org/problems/word-break-part-2/0/
////// https://www.interviewbit.com/problems/word-break-ii/

vector<string> wordBreak(string s, vector<string> &dictV) {
    unordered_set<string> dict(dictV.begin(), dictV.end());
    vector<vector<string> > words(s.length() + 1, vector<string>(0));

    // initialize the valid values
    words[s.length()].push_back("");

    // generate solutions from the end
    for(int i = s.length() - 1; i >= 0; i--) {
        vector<string> values;
        for(int j = i + 1; j <= s.length(); j++) {
            if (dict.find(s.substr(i, j - i)) != dict.end()) {
                for (int k = 0; k < words[j].size(); k++) {
                    values.push_back(s.substr(i, j - i) + (words[j][k].empty() ? "" : " ") + words[j][k]);
                }
            }
        }
        words[i] = values;
    }
    return words[0];
}
///////////////////////////
/// pending

bool finds(string s, vector<string> &dict){
    for(int i=0; i<dict.size(); ++i){
        if(s == dict[i]) return true;
    }
    return false;
}

void wordBreakHelp(string s, vector<string> &dict, int start, int len, 
                   string& result, vector<string>& ans, vector<bool>& check)
{
    if(start == len){
        ans.push_back(result.substr(0,result.size()-1));
    }

    else{
        for(int i=start;i<len;++i){
            string temp = s.substr(start, i-start+1);
            if(finds(temp,dict) && check[i+1]){
                result.append(temp).append(" ");
                int oldSize = ans.size();
                wordBreakHelp(s,dict,i+1,len,result, ans,check);
                if(ans.size() == oldSize) 
                    check[i+1] = false;
                result.resize(result.size() - temp.size() - 1);
            } 
        }
    }
}

vector<string> Solution::wordBreak(string s, vector<string> &dict) {
    
    vector<string> ans;
    int len = s.length();
    if(len == 0) return ans;
    string temp;
    vector<bool> check(len + 1, true);
    wordBreakHelp(s, dict, 0, len, temp, ans, check);
    return ans;
}


///////////////////////////
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

