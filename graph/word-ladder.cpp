////////////https://www.interviewbit.com/problems/word-ladder-i/

////// word ladder

int diff(string A, string B){
    int n = A.length();
    int d = 0;
    for(int i=0; i<n; i++){
        if(A[i]!=B[i]) d++;
    }
    return d;
}

int Solution::solve(string A, string B, vector<string> &C) {
    C.push_back(B);
    unordered_map<string,int> mp;
    int n = C.size();
    vector<bool> visit(n,false);
    queue<string> qt;
    qt.push(A);
    mp[A] = 0;
    
    while(!qt.empty()){
        string s1 = qt.front();
        qt.pop();

        if(s1==B){
        	return mp[B]+1;
        }
        
        for(int i=0; i<C.size(); i++){
        	if(diff(s1,C[i])==1 and visit[i]==false){
        		qt.push(C[i]);
        		visit[i] = true;
        		if(mp.find(C[i]) == mp.end()){
        		    mp[C[i]] = mp[s1] + 1;
        		}
        	}
        }
    }
    return 0;
}

/////////////////////////

// Word ladder 1 is bfs, as we are searching for shortest path, 
// while for word ladder 2, we will use dfs, as that makes more sense, (going through one path then through next path).

/// https://www.interviewbit.com/problems/word-ladder-ii/
//////// word ladder 2

vector<vector<string> > res;
int nd, minL;
string en;
 
bool isAdj(string a, string b){
    int n = a.length();
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])
            cnt++;
        if(cnt>1)
            return false;
    }
    return (cnt==1)? true : false;
}
 
void dfs(vector<string> &dict, vector<string> &temp, bool vis[], int len)
{
    if(len>minL)
        return;
    if(temp[len-1] == en){
        if(minL > len){
            minL = len;
            res.clear();
        }
        res.push_back(temp);
        return;
    }
    string s = temp[len-1];
    for(int i=0;i<nd;i++){
        if(vis[i] == false && isAdj(s,dict[i])){
            vis[i] = true;
            temp.push_back(dict[i]);
            dfs(dict,temp,vis,len+1);
            temp.pop_back();
            vis[i] = false;
        }
    }
}
 
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict)
{
    res.clear();
    dict.push_back(end);
    unordered_set<string> st;
    for(auto x : dict)
        st.insert(x);
    dict.assign(st.begin(), st.end());  ////// no duplicates
    sort(dict.begin(), dict.end());
 
    nd = dict.size();
    minL = INT_MAX;
    en = end;

    vector<string> temp;
    bool vis[nd];
    memset(vis,false,sizeof(vis));
 
    temp.push_back(start);
    dfs(dict,temp,vis,1);
 
    return res;
}

////////////////////







