///// paypal

///// vowel permutations

#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;
vector<vector<int>> relation = {{1},{0,2},{0,1,3,4},{2,4},{0}};
vector<vector<int>> memo;

int dp(int n,int v){  //'v' represents the vowel

    if(n==1){
        return 1;
    }
    if(memo[n][v] != -1){
        return memo[n][v];
    }
    memo[n][v] = 0;

    for(int &i : relation[v]){
        memo[n][v] += dp(n-1, i);
        memo[n][v] %= MOD;
    }
    return memo[n][v];
}

int countVowelPermutation(int n) 
{
    int result = 0;
    memo.resize(n+1, vector<int>(5,-1));
    for(int i=0; i<5; i++){
        result += dp(n,i);
        result %= MOD;
    }
    return result;
}

//////////////////////
///////////////////

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
////// construct office
//////////

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int minDist(int w, int h, vector<pi> arr){

    int res = 0;

    // for(auto it: arr) cout<<it.first<<" "<<it.second<<endl;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int k1 = 10000;
            for(auto it: arr){
                int k = abs(i - it.first) + abs(j - it.second);
                k1 = min(k1, k);
            }
            res = max(k1, res);
        }
    }

    return res;
}


int findMinDistance(int w, int h, int n) {

    vector<pi> points;

    int ans = INT_MAX;
    int tot = w*h;

    for(int i = 0; i < tot; i++){
        int xi = i/w, yi = i%w;
        points.push_back({xi, yi});
        if(n == 1) ans = min(ans, minDist(w, h, points));
        if(n > 1){
            for(int j = i+1; j < tot; j++){
                int xj = j/w, yj = j%w;
                points.push_back({xj, yj});
                if(n == 2) ans = min(ans, minDist(w, h, points));
                if(n > 2){
                    for(int k = j+1; k < tot; k++){
                        int xk = k/w, yk = k%w;
                        points.push_back({xk, yk});
                        if(n == 3) ans = min(ans, minDist(w, h, points));
                        if(n > 3){
                            for(int l = k+1; l < tot; l++){
                                int xl = l/w, yl = l%w;
                                points.push_back({xl, yl});
                                if(n == 4) ans = min(ans, minDist(w, h, points));
                                if(n > 4){
                                    for(int m = l+1; m < tot; m++){
                                        int xm = m/w, ym = m%w;
                                        points.push_back({xm, ym});
                                        ans = min(ans, minDist(w, h, points));
                                        points.pop_back();
                                    }
                                }
                                points.pop_back();
                            }
                        }
                        points.pop_back();
                    }
                }
                points.pop_back();
            }
        }
        points.pop_back();
    }


    return ans;
}

///////////////
///////////////////
////////////////








