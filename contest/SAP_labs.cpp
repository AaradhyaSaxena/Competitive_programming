////// SAP Labs

/////// Number of distinct substrings

#include <bits/stdc++.h>
using namespace std;

struct suffix{
    int index;
    string suff;
};

int cmp(suffix a, suffix b){
    return (a.suff).compare(b.suff)<0 ? 1:0;
}

vector<int> const_Suffix_arr(string txt, int n){
    suffix sa[n];
    for(int i=0; i<n; i++){
        sa[i].index = i;
        sa[i].suff = txt[i];
    }
    sort(sa, sa+n, cmp);
    vector<int> suffix_arr(n);
    for(int i=0; i<n; i++){
        suffix_arr[i] = sa[i].index;
    }

    return suffix_arr;
}

vector<int> kasai(vector<int> sa, string ss){
    int n = ss.length(), k=0;
    vector<int> lcp(n,0), inv_sa(n,0);

    for(int i=0; i<n; i++) {
        inv_sa[sa[i]] = i;
    }

    for(int i=0; i<n; i++){
        if (i==n-1) continue;
        int j = sa[inv_sa[i] +1];
        while(i+k<n && j+k<n && ss[i+k]==ss[j+k]) k++;
        lcp[inv_sa[i]] = k;
        if(k>0) k--;
    }

    return lcp;
}

int main(){
    int n; cin>>n; 
    string str;
    cin>>str;
    vector<int> sa = const_Suffix_arr(str,n);
    vector<int> lcp = kasai(sa, str);
    long long int sum = 0, ans = 0;
    for(int i=0; i<lcp.size(); i++){
        sum += lcp[i];
    }
    ans = (n*(n+1)/2) - sum;
    cout<<ans<<endl;
}

/////////////

/*
binary string given, find number of substring with only one 1,0 boundary 
and having equal number of 0's and 1's.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string ss;
    cin>>ss;
    int n = ss.length();
    vector<int> vec;
    vec.push_back(0);
    for(int i=1; i<n; i++){
        if(ss[i-1]!=ss[i]){
            vec.push_back(i);
        }
    }
    vec.push_back(n);
    int sum = 0;
    for(int i=1; i<vec.size()-1; i++){
        int left = vec[i-1], right = vec[i+1];
        sum += min(vec[i]-left, right-vec[i]);
    }
    cout<<sum<<endl;
}

////////////////////////// SAP 19

////// Sorted Arrangement
//// https://leetcode.com/discuss/interview-question/371225/Sorted-Arrangements-or-Infosys-Specialist-Programmer-or-On-campus-hackerrank

int BIT[100005], a[100005], n;
void update(int x, int delta)
{     
    for(; x <= n; x += x&-x){
        BIT[x] += delta;
    }
}

int query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
} 
 
long getCount( long number, int i){
    int left = query(number-1);
    int right = i - query(number);
    return left < right ? 2*left+1 : 2*right+1; 
}

long minimumOperations(vector<int> numbers) {
    long ans=0;
    n = 0;
    for(int i=0; i<numbers.size(); i++){
        n = max(n, numbers[i]);
    }
    for(int i=0; i<numbers.size(); i++){
        ans += getCount(numbers[i], i);
        update(numbers[i],1);
    }
    return ans;
}

////////////
///////////////
/// Can you make palindrome

// /// https://leetcode.com/problems/can-make-palindrome-from-substring/submissions/
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int mask = 0;
    vector<int> ps(1);
    for (char c : s)
        ps.push_back(mask ^= 1 << (c - 'a'));

    vector<bool> r;
    for (auto &q : queries) {
        int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
        r.push_back(q[2] >= odds / 2);
    }
    return r;
}

///////////////////////
//////////
////////////////////

//// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

int smallestDivisor(vector<int>& A, int threshold) {
    int left = 1, right = 1e6, m, sum;
    while (left < right) {
        m = (left + right) / 2, sum = 0;
        for (int i : A)
            sum += (i + m - 1) / m;
        if (sum > threshold)
            left = m + 1;
        else
            right = m;
    }
    return left;
}

//////////////////////
////////////////

//// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

int minTaps(int n, vector<int>& A) {
    vector<int> dp(n + 1, n + 2);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = max(i - A[i] + 1, 0); j <= min(i + A[i], n); ++j)
            dp[j] = min(dp[j], dp[max(0, i - A[i])] + 1);
    return dp[n]  < n + 2 ? dp[n] : -1;
}

////////////////
/////////////////////



