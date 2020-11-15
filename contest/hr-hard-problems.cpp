////// hackerrank hard problems
///////////////////////////////

////// path to goal

#include <bits/stdc++.h>
using namespace std;
 
#define M 1000000007 
int dp[1001][2501][2];
 
int solveUtil( string moves, int n, int start, int end, int idx, bool flag ){
 
    if( start < 0 || start >n ){
        return 0;
    }
 
    if( idx >= moves.size() ){
        return 0;
    }
 
    if( dp[idx][start][flag] != -1 ){
        return dp[idx][start][flag];
    }
 
    int ans = 0;
    if( (moves[idx] == 'l' && flag) || (moves[idx] == 'r' && !flag) ){
 
        int change = moves[idx] == 'l' ? -1 : 1;
 
        ans = (solveUtil( moves, n, start+change, end, idx+1, flag )%M +
              solveUtil( moves, n, start+change, end, idx+1, !flag )%M)%M;
        
        if(start+change == end){
        	ans++;
        }
    }
    else{
        ans = solveUtil( moves, n, start, end, idx+1, flag );
    }
    return dp[idx][start][flag] = ans;
}
 
int distinctMoves(string moves, int n, int start, int end){

    memset(dp,-1,sizeof(dp));
    return solveUtil( moves, n, start, end, 0, false ) + solveUtil( moves, n, start, end, 0, true );
}

////////////////
///////////////////////////////

////// common prefix

vector<int> commonPrefix(vector<string> inputs) {
    int t = inputs.size();
    vector<int> ans;
    for(int i=0; i<t; i++){
        string str = inputs[i];
        int n = str.size();
        int total =0;
        for(int j=1; j<n; j++){
            if(str[j]==str[0]){
                int cnt =0;
                for(int k=j; k<n; k++){
                    if(str[k]==str[cnt]){
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
                total += cnt;
            }
        }
        ans.push_back(total+n);
    }
    return ans;
}

////////////////////////
///////////////
//////////////////

// is this a tree?

bool IsCycle(char node, vector<vector<bool>> graph, bool visited[]){
    if(visited[node-'A']){
        return true;
    }
    visited[node-'A'] = true;
    for(int i=0; i<26; i++){
        if(graph[node-'A'][i]){
            if(IsCycle((char)(i+'A'), graph, visited)){
                return true;
            }
        }
    }
    return false;
}

string helper(char root, vector<vector<bool>> graph){
    string left = "", right = "";
    for(int i=0; i<26; i++){
        if(graph[root-'A'][i]){
            left = helper((char)(i+'A'), graph);
            for(int j=i+1; j<26; j++){
                if(graph[root-'A'][j]){
                    right = helper((char)(j+'A'), graph);
                    break;
                }
            }
            break;
        }
    }
    string ans = "(";
    ans += root + left + right + ")";
    return ans;
}

string sExpression(string s) {

    vector<vector<bool>> graph(26, vector<bool> (26, false));
    set<char> nodes;

    bool E2 = false;
    for(int i=1; i<s.length(); i+=6){
        int x= s[i]-'A';
        int y= s[i+2]-'A';
        if(graph[x][y]==true){
            E2 = true;
        }
        graph[x][y] = true;
        nodes.insert(s[i]);
        nodes.insert(s[i+2]);
    }

    bool E1 = false;
    for(int i=0; i<26; i++){
        int cnt =0;
        for(int j=0; j<26; j++){
            if(graph[i][j]){
                cnt++;
            }
        }
        if(cnt>2){
            return "E1";
        }
    }
    if(E2){
        return "E2";
    }

    int numOfRoots = 0;
    char root = ' ';
    for( char node: nodes){
        for(int i=0; i<26; i++){
            if(graph[i][node-'A']){
                break;
            }
            if(i==25){
                numOfRoots++;
                root = node;
                bool visited[26] = {false};
                if(IsCycle(node, graph, visited)){
                    return "E3";
                }
            }
        }
    }

    if(numOfRoots==0) return "E3";
    if(numOfRoots>1) return "E4";
    if(root==' ') return "E5";

    return helper(root, graph);
}

////////////////////////
//////////////////
//////////////////////////////

//// paths in warehouse

int numPaths(vector<vector<int>> warehouse) {
    int n = warehouse.size();
    int m = warehouse[0].size();
    long long int dp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = warehouse[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(warehouse[i][j]==1 and i>0){
                dp[i][j] = (dp[i][j] + dp[i-1][j])%(1000000007);
            }
            if(warehouse[i][j]==1 and j>0){
                dp[i][j] = (dp[i][j] + dp[i][j-1])%(1000000007);
            }
        }
    }
    return dp[n-1][m-1];
}

/////////////////////
////////////////
////////////////////////////   

//////// permutation divisible by 8

bool helper(string n, int l){  

    if (l < 3) { 
        if (stoi(n) % 8 == 0) 
            return true; 

        reverse(n.begin(), n.end()); 
        if (stoi(n) % 8 == 0) 
            return true; 
        return false; 
    } 
    
    int hash[10] = { 0 }; 
    for (int i = 0; i < l; i++) 
        hash[n[i] - '0']++; 
  
    for (int i = 104; i < 1000; i += 8) { 
  
        int dup = i; 
        
        int freq[10] = { 0 }; 
        freq[dup % 10]++; 
        dup = dup / 10; 
        freq[dup % 10]++; 
        dup = dup / 10; 
        freq[dup % 10]++; 
  
        dup = i; 
        if (freq[dup % 10] > hash[dup % 10]) 
            continue; 
        dup = dup / 10; 
  
        if (freq[dup % 10] > hash[dup % 10]) 
            continue; 
        dup = dup / 10; 
  
        if (freq[dup % 10] > hash[dup % 10]) 
            continue; 
  
        return true; 
    } 
    return false; 
} 


vector<string> checkDivisibility(vector<string> arr) {
    vector<string> ans;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int l = arr[i].length();
        if(helper(arr[i],l)){
            ans.push_back("YES");
        }
        else{
            ans.push_back("NO");
        }
    }
    return ans;
}

//////////////////////////
//////// split the array
//////////////////

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

unordered_map<pair<int,int>, int, hash_pair> mp;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}

int helper(vector<int> val, int i, int j){
    if(i>j) return 1000005;
    if(i==j) return 1;

    if(gcd(val[i],val[j])>1){
    	mp[make_pair(i, j)] = 1;
    	return 1;
    } 
    if(mp.find(make_pair(i,j))!=mp.end()){
        return mp[{i,j}];
    }

    int cnt = 1000005;
    for(int k=i; k<j; k++){
        cnt = min(cnt, helper(val,i,k) + helper(val,k+1,j));
    }
    mp[make_pair(i, j)] = cnt;
    return cnt;
}

int splitTheArray(vector<int> val) {
    int n = val.size();
    // unordered_map<pair<int,int>, int> mp;
    mp.clear();
    return helper(val,0, n-1);
}

//////////////////////////
////// bio hazard
//////////

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

long angryAnimals(int n,vector<int> a, vector<int> b){

    vector<priority_queue<int> > e(n+1);

    for(int i=0;i<a.size();i++){
        // We will only push smaller element as we will be checking from left to right
        if(a[i]<=n && b[i]<=n){
            if(a[i]<b[i]){
                e[b[i]].push(a[i]);
            }
            else{
                e[a[i]].push(b[i]);
            }
        }   
    }
    long count = 0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(e[i].empty()){
            count++;
            q.push(i);
        }
        else{
            while(!q.empty()&& !e[i].empty() && q.front()<=e[i].top() && q.back() >=e[i].top()){
                if(q.front() >= e[i].top()){
                    e[i].pop();
                }

                q.pop();
                count+=q.size();
            }
            q.push(i);
            count++;
        }
    }
    int size = q.size();
    //number of ways for remaining elements
    count += size*(size-1)/2;
    return count;
}

//////////////

//// moulo arithmatic eqn

#include <bits/stdc++.h>

using namespace std;


typedef unsigned long long int ll;

const ll mod=1000007;

bool isPrime(ll p)
{
    bool num = false;
    if(p==2||p==3)
    return true;

    for(ll i=2;i<=sqrt(p);++i)
    {
        if(p%i==0)
            {
            num = false;
            break;
        }
        else
            num = true;

    }
    return num;
}
ll factors(ll n)
{
   ll ans=1;
   for(ll i=2;i<=n;i++)
   {
       if(isPrime(i))
       {
           ll po=1;
           ll count=0;
           while(pow(i,po)<=n)
           {
               count=count+(n/pow(i,po));
               po++;
           }
           ans=(ans*(2*count+1))%mod;
       }
   }
   return ans%mod;
}



int main()
{
    ll n;
    cin>>n;
    cout<<(factors(n)%mod)<<endl;
}
///////

/////////////////// distinct char

#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX_CHARS = 256; 
  
string findSubString(string str) 
{ 
    int n = str.length(); 
  
    int dist_count = 0; 
    bool visited[MAX_CHARS] = { false }; 
    for (int i = 0; i < n; i++) { 
        if (visited[str[i]] == false) { 
            visited[str[i]] = true; 
            dist_count++; 
        } 
    } 
  
    int start = 0, start_index = -1, min_len = INT_MAX; 
    int count = 0; 
    int curr_count[MAX_CHARS] = { 0 }; 
    for (int j = 0; j < n; j++) { 
        
        curr_count[str[j]]++; // Count occurrence of characters of string 
        
        if (curr_count[str[j]] == 1) 
            count++; // If any distinct character matched, then increment count 

        if (count == dist_count) { // if all the characters are matched 
            while (curr_count[str[start]] > 1) { 
                if (curr_count[str[start]] > 1) 
                    curr_count[str[start]]--; 
                start++; 
            } 
  
            int len_window = j - start + 1; 
            if (min_len > len_window) { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
    return str.substr(start_index, min_len); 
} 

////////////
/////////////////
/// number of distinct substrings

struct suffix 
{ 
    int index; 
    int rank[2]; 
}; 

int cmp(struct suffix a, struct suffix b) 
{ 
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0): (a.rank[0] < b.rank[0] ?1: 0); 
} 

vector<int> buildSuffixArray(string txt, int n) 
{ 
    struct suffix suffixes[n]; 
  
    for (int i = 0; i < n; i++) { 
        suffixes[i].index = i; 
        suffixes[i].rank[0] = txt[i] - 'a'; 
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1; 
    } 
    sort(suffixes, suffixes+n, cmp); 
    int ind[n]; 

    for (int k = 4; k < 2*n; k = k*2) { 
        int rank = 0; 
        int prev_rank = suffixes[0].rank[0]; 
        suffixes[0].rank[0] = rank; 
        ind[suffixes[0].index] = 0; 
  
        for (int i = 1; i < n; i++) { 
            if (suffixes[i].rank[0] == prev_rank && 
               suffixes[i].rank[1] == suffixes[i-1].rank[1]) 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = rank; 
            } 
  
            else 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = ++rank; 
            } 
            ind[suffixes[i].index] = i; 
        } 
  
        for (int i = 0; i < n; i++) 
        { 
            int nextindex = suffixes[i].index + k/2; 
            suffixes[i].rank[1] = (nextindex < n)? suffixes[ind[nextindex]].rank[0]: -1; 
        } 
        sort(suffixes, suffixes+n, cmp); 
    } 
    vector<int>suffixArr; 
    for (int i = 0; i < n; i++) suffixArr.push_back(suffixes[i].index); 

    return  suffixArr; 
} 
  
vector<int> kasai(string txt, vector<int> suffixArr) 
{ 
    int n = suffixArr.size(); 
    vector<int> lcp(n, 0); 
    vector<int> invSuff(n, 0); 
  
    for (int i=0; i < n; i++) invSuff[suffixArr[i]] = i; 
    int k = 0; 
    for (int i=0; i<n; i++){ 
        if (invSuff[i] == n-1){ 
            k = 0; 
            continue; 
        } 
        int j = suffixArr[invSuff[i]+1]; 
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) 
            k++; 
  
        lcp[invSuff[i]] = k; 
        if (k>0) k--; 
    } 
    return lcp; 
} 
  
long substringCalculator(string txt) 
{ 
    int n = txt.length(); 
    vector<int> suffixArr = buildSuffixArray(txt, n); 
    vector<int> lcp = kasai(txt, suffixArr); 

    int result = n - suffixArr[0]; 
    for (int i = 1; i < lcp.size(); i++) result += (n - suffixArr[i]) - lcp[i - 1]; 
  
    return result; 
}

/////////////////////////
/////// super stack
/*
Make a pair for all values with their time stamp
take a time stamp for all the modifications
then when you print the final element and 
check only for modifications that came after that element was added.
use binary search for timestamp.
*/

void superStack(vector <string> operations) {
    vector<int> stk;
    int n = operations.size();
    for(int i=0; i<n; i++){
        stringstream ss(operations[i]);
        string temp; int a,b;
        if(ss>>temp){
            if(temp=="push"){
                if(ss>>a){
                    stk.push_back(a);
                    cout<<a<<endl;
                }
            }
            else if(temp=="inc"){
                if(ss>>a and ss>>b){
                    for(int i=0; i<a and i<stk.size(); i++){
                        stk[i] += b;
                    }
                }
                if(!stk.empty()){
                    int c = stk.back();
                    cout<<c<<endl;
                }else{
                    cout<<"EMPTY"<<endl;
                }
            }
            else{
                stk.pop_back();
                if(!stk.empty()){
                    int c1 = stk.back();
                    cout<<c1<<endl;
                }else{
                    cout<<"EMPTY"<<endl;
                }
            }
        }
    }
}

///////






