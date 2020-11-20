/////// hackerrank

// Good binary strings

/*
Special binary strings are binary strings with the following two properties:
The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.

Given a special string S, a move consists of choosing two consecutive, non-empty, 
special substrings of S, and swapping them. 
(Two strings are consecutive if the last character of the first string
is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible? 
*/

string largestMagical(string S) {
    int count = 0, i = 0;
    vector<string> res;
    for (int j = 0; j < S.size(); ++j) {
    	if (S[j] == '1') count++;
      	else count--;
      	if (count == 0) {
        	res.push_back('1' + largestMagical(S.substr(i + 1, j - i - 1)) + '0');
        	i = j + 1;
      	}
    }
    sort(res.begin(), res.end(), greater<string>());
    string res2 = "";
    for (int i = 0; i < res.size(); ++i) res2 += res[i];
    return res2;
}

//////////
///////////////////
/////////////////

///// Equal circle segments

/*
Given the radii of a number of circles and a number of segments to cut, 
determine the largest area of segments of equal area that can be cut. 
Return the value, rounded to 4 decimals and cast as a string.
*/

bool check(double &x ,vector<double> &A, int &K){
    int k = 0;
       for(auto a : A){
        k += a/x;
         if(k >= K) return true;
       }
       return false;
}

double maximum_serving_area(vector<int> v,int k){
    double l=0, m=0, x;
      vector<double> A;
      for(int i=0; i<v.size(); i++)  {
        x = (double)v[i]*3.14159265359*v[i];
        m = max(m,x);
        A.push_back(x);
      }
      while(m-l >= 1e-5){
        x = (l+m)/2;
        if(check(x,A,k)) l=x;
        else m=x;
      }
      return x;
}

string largestSegment(vector<int> radius, int segments) {
    double res = maximum_serving_area(radius, segments);
    string ans ="";
    stringstream stream;
    stream<<fixed<<setprecision(4)<<res;
    if(stream>>ans){
        return ans;
    }
    return " ";
}

///////////////////////

///// Active fountain

////// Fountain

def fountainActivation(locations):
    n = len(locations)
    extents = [0] * n
    for i in range(n):
        left =  max(0, i - locations[i])
        right = min(n, i + locations[i] + 1)
        extents[left] = max(extents[left], right)
    for i in range(1, n):
        extents[i] = max(extents[i], extents[i-1])
    answer = 1
    already_occupied = extents[0]
    for i in range(n):
        if i == already_occupied:
            answer += 1
            already_occupied = extents[i]
    return answer

///////////////////////
////// Bus stand

#define MAX 100005
vector<int> kthPerson(int k, vector<int> p, vector<int> q) {
    int maxx = *max_element(p.begin(), p.end());
    int dp[maxx+10];
    for(int i=0; i<maxx+10; i++) dp[i]=0;
    
    int nq = q.size(), np = p.size();
    
    for(int i=0; i<np; i++){
        dp[p[i]]++;
    }
    for(int i=maxx; i>=0; i--){
        dp[i] += dp[i+1];
    }
    // for(int i=0; i<maxx+2; i++){
    //     cout<<dp[i]<<" ";
    // }cout<<endl;
    vector<int> ans;
    for(int i=0; i<nq; i++){
        int cnt = 0;
        if(dp[q[i]]<k){
            ans.push_back(0);
            continue;
        }
        for(int j=0; j<np; j++){
            if(p[j] >= q[i]){
                cnt++;
            }
            if(cnt==k){
                ans.push_back(j+1);
                break;
            }
        }
        if(cnt<k){
            ans.push_back(0);
        }
    }
    return ans;
}

/////////////////////
//// quantity and protein

long maximumHMI(vector<int> quantity, vector<int> protein, int max_allowed) {
    long long n,m,k,i,j,ans=0;
    n=quantity.size();
    k=max_allowed;
    pair<long long,long long> p[n];
    for(i=0;i<n;i++){
        p[i]=make_pair(protein[i],quantity[i]);
    }
    sort(p,p+n);
    long long tot=0;
    priority_queue<long long,vector<long long>,greater<long long> > pq;
    for(i = n-1; i>=0; i--){
        pq.push(p[i].second);
        tot += p[i].second;
        if(pq.size() > k){
            tot -= (pq.top());
            pq.pop();
        }
        ans = max(ans,tot*p[i].first);
    }
    return ans;
}

//////////////////////
//// Lifting weights

/*
Ollie is new to the gym and is figuring out the maximum weights she can lift. 
The maximum capacity of the barbell is given as maxCapacity.
*/

typedef long long int ll;
ll ans, n;

void helper(int i, vector<int> weights, ll maxCap){
    // cout<<maxCap<<endl;
    if(maxCap<0 or i>n) return;
    if(maxCap == 0){
        ans = 0;
        return;
    }
    ans = min(ans, maxCap);
    for(int j=i; j<n; j++){
        helper(j+1,weights, maxCap-weights[j]);
        if(ans==0) return;
        helper(j+1, weights, maxCap);
        if(ans==0) return;
    }
}

int weightCapacity(vector<int> weights, int maxCapacity) {
    n = weights.size();
    ans = INT_MAX;
    sort(weights.begin(),weights.end());
    helper(0, weights, maxCapacity);
    return maxCapacity-ans;
}

//////////////////////////////////////
/// weight is too large for knapsack

int knapSack(int W, vector<int> wt, vector<int>val, int n){ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] 
                          + K[i - 1][w - wt[i - 1]], 
                          K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
}

int weightCapacity(vector<int> weights, int maxCapacity) {
    int n = weights.size();
    return knapSack(maxCapacity, weights, weights, n);
} 

/*
#Importing combinations from itertools
from itertools import combinations
def weightCapcity(weights, maxSize):
    #Creating all sublists and appending into subs
    subs = []
    for i in range(0, len(weights) + 1):
        #Creating sublist using combinations, which is built in function in python
        temp = [list(x) for x in combinations(weights, i)]
        if len(temp) > 0:
            subs.extend(temp)
    #Intializing maximum with zero value
    maximum = 0
    #For each list calculating a value
    for i in subs:
        count = 0
        for j in i:
            count = count + j
        #Finding maximum using condition
        if count > maximum and count <= maxSize:
            maximum = count
    #Returning maximum
    return maximum
#Taking input size
size = int(input())
weights = []
#Appending into weights for each weight input
for i in range(size):
    weights.append(int(input()))
#Getting max size
maxSize = int(input())
#Calling function with two arguments
print(weightCapcity(weights,maxSize))
*/

/////////////////////
///////////////////////

/////// Deveopment team threshold

int devTeam(vector<vector<int>> marks, int r) {
    int n = marks.size();
    pair<long,long> sum = {0,1};
    for(int i=0; i<n; i++){
        int a = marks[i][0];
        int b = marks[i][1];
        sum.first = sum.first*b + sum.second*a;
        sum.second = sum.second*b;
        long g = __gcd(sum.first, sum.second);
        sum.first /= g;
        sum.second /= g;
    }
    priority_queue<pair<double,pair<int,int>>> q;
    for(int i=0; i<n; i++){
        q.push({((marks[i][1]-marks[i][0])*1.0)/(marks[i][1]*(marks[i][1]+1)),{marks[i][0],marks[i][1]}});
    }
    int ans=0;
    while(sum.first*100<sum.second*n*r){
        sum.first = sum.first*(q.top().second.second+1)+sum.second*(q.top().second.first+1);
        sum.second = sum.second*(q.top().second.second+1);
        sum.first = sum.first*q.top().second.second - sum.second*q.top().second.first;
        sum.second = sum.second*q.top().second.second;
        int g = __gcd(sum.first, sum.second);
        sum.first /= g;
        sum.second /= g;
        ans++;
        pair<int,int> prev = q.top().second;
        prev.first += 1;
        prev.second += 1;
        q.pop();
        q.push({((prev.second-prev.first)*1.0)/(prev.second*(prev.second+1)),{prev.first,prev.second}});
    }
    return ans;
}

///////////////////////////////
///////// Best telescope site

int findTheCity(int n, int distanceThreshold, vector<int> from, vector<int> to, vector<int> wt){
    vector<vector<int>> dis(n+1, vector<int>(n+1, 10001));
    int res = 0, smallest = n;
    for (int i=0; i<from.size(); i++){
        dis[from[i]][to[i]] = dis[to[i]][from[i]] = wt[i];
    }
    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; ++j)
            if (dis[i][j] <= distanceThreshold)
                ++count;
        if (count <= smallest) {
            res = i;
            smallest = count;
        }
    }
    return res;
}

int findBestCity(int distanceThreshold, int city_nodes, vector<int> city_from, vector<int> city_to, vector<int> city_weight) {
    int n = city_nodes, th = distanceThreshold;
    int e = city_from.size();
    return findTheCity(n,th,city_from,city_to,city_weight);
}

///////////////////////////
/////// Aladdin and his carpet

int optimalPoint(vector<int> &A, vector<int> &B) {
    int n = A.size(), sumA =0, sumB =0;
    for(int i=0; i<n; i++){
        sumA += A[i];
        sumB += B[i];
    }
    if(sumB>sumA) return -1;
    
    int fuel = 0;
    for(int i=0; i<n; i++){
        fuel = 0;
        for(int j=i; j<n; j++){
            if(fuel<0) break;
            fuel += (A[j]-B[j]);
        }
        if(fuel>=0){
            return i;
        }
    }
    return -1;
}

/////////////////////////////
//////// Coloring a grid

/// Ans = 24𝑛−(9×8𝑛)+(18×3𝑛)+(9×2𝑛)−24
const int mod = 1000000007;
typedef long long int ll;

ll power(int x, int n) {
    if (n == 0) return 1 % mod;
    ll ans = 1, base = x;
    while (n > 0) {
        if (n % 2 == 1) {
            ans = (ans * base) % mod;
            n--;
        } 
        else {
            base = (base * base) % mod;
            n /= 2;
        }
    }
    if (ans < 0) ans = (ans + mod) % mod;
    return ans%mod;
}

int countPatterns(int n) {
    ll total = (ll(power(24,n))%mod - ll(9*power(8,n))%mod+ ll(18*power(3,n))%mod + 
                ll(9*power(2,n))%mod - 24 + mod)%mod;
    return total;
}

////////////////////////
//////// Priority caching

def cacheContents(callLogs):
    count_dict = {}
    cache_values = []
    call_log_dict = {}
    min_time = math.inf
    max_time = -math.inf
    for time, value in callLogs:
        if time > max_time:
            max_time = time
        if time < min_time:
            min_time = time
        if call_log_dict.get(time):
            call_log_dict[time].append(value)
        else:
            call_log_dict[time] = [value]
    for time in range(min_time, max_time+1):
        if(time not in call_log_dict):
            continue
        values = call_log_dict[time]
        for c_key, c_value in count_dict.items():
            if c_value > 0 and c_key not in values:
                count_dict[c_key] -= 1
        for value in values:
            if count_dict.get(value):
                count_dict[value] += 2
            else:
                count_dict[value] = 2
		for count_key, value in count_dict.items():
		    if value > 5 and count_key not in cache_values:
		        cache_values.append(count_key)
		    if value <= 3 and count_key in cache_values:
		        cache_values.remove(count_key)
    return cache_values

/////////////////////////////
///////// Scatter palindrome

int countSubstring(string s){
    int answer = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    
    int x = 0; // Store mask in x from 0 to i
    for (int j = 0; j < s.length(); j++) {
        x ^= 1 << (s[j] - 'a');
        answer += m[x];
        for (int i = 0; i < 26; ++i) {
            answer += m[x ^ (1 << i)];
        }
        m[x] += 1;
    }
    return answer;
}
vector<int> scatterPalindrome(vector<string> strToEvaluate) {
    vector<int> ans;
    for(int i=0; i<strToEvaluate.size(); i++){
        ans.push_back(countSubstring(strToEvaluate[i]));
    }
    return ans;
}

///////////////////////////////
///////// Throttling Gateway

int droppedRequests(vector<int> requests) {
    int n = requests.length;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 3 && requests[i] - requests[i-3] < 1) {
            ++count;
        } else if (i >= 20 && requests[i] - requests[i-20] < 10) {
            ++count;
        } else if (i >= 60 && requests[i] - requests[i-60] < 60) {
            ++count;
        }
    }
    return count;
}

///////////////////////////////
///////// Error digit range 

class Result {
public static long findRange(long num)
   {
        //Declare minimumValue,maximumValue as type of String
        String minimumValue,maximumValue;
        //Declare maximum,minimum as type of long
        long maximum,minimum;
       //The variable num is converted to string and store in maximumValue
        maximumValue = new Long(num).toString();
       //Declare i as type of integer and assign 0 to i
       int i = 0;
       //Iterate the loop
       while(i<maximumValue.length()){
           //if the digit 1 is misinterpreted as 9.
           if (maximumValue.charAt(i) == '1'){
           //call replace function through maximumValue
               maximumValue = maximumValue.replace(maximumValue.charAt(i), '9');
           }
           //increment i by 1
       i++;
       }
       //The variable num is converted to string and store in minimumValue
       minimumValue = new Long(num).toString();
       //Declare k as type of integer
       int k = 0;
       //Iterate the loop
       while(k<minimumValue.length())
       {
       //if the digit is 2 misinterpreted as 0
           if (minimumValue.charAt(k) == '2')
           {
           //call replace function through minimumValue.
               minimumValue = minimumValue.replace(minimumValue.charAt(k), '0');
           }
           //increment k by 1
           k++;
       }
       //The value of variable maximumValue is
       //converted into Long and store in maximum
       maximum = new Long(maximumValue);
       //The value of variable minimumValue is
       //converted into Long and store in minimum
       minimum = new Long(minimumValue);
       //return the value of difference between
       //maximum and minimum
       return maximum - minimum;
   }
   //Implementation of main function
   public static void main(String[] args){
       //Declare object1 as type of Scanner
        Scanner object1 = new Scanner(System.in);
       //Declare the num as long type
       long num;
       //Get the value through object1
       num = object1.nextLong();
       //check the constraint 1<=num<=10^9
       if(1<=num && num<=(long)Math.pow(10, 9))
       {
       //Display statement
       System.out.println(findRange(num));
       }
   }
}

//////////////////
/////// anagram difference

int getDifference(string a, string b) {
    vector<int> cnt(26, 0);
    int r = 0;
    if (a.size() != b.size())
        return -1;
    else {
        for (auto &c : a)
            cnt[c-'a']++;
        for (auto &c : b) {
            cnt[c-'a']--;
            if (cnt[c-'a']<0)
                r++;
        }
        return r;
    }
}
vector<int> getMinimumDifference(vector<string> a, vector<string> b) {
    vector<int> res;
    for(int i = 0; i < a.size(); i++) {
        res.push_back(getDifference(a[i], b[i]));
    }
    return res;
}

//////////////////
/////// Count string permutation
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

//////////////////////////////
///////// Matrix Summation
/*
def findBefore(x,y,after):
# Takes positions of x and y and after matrix
# and returns before matrix element at that position
	s = 0
	for i in range(x+1):
		for j in range(y+1):
			if i != x or j != y:
				s = s + after[i][j]
	after[x][y] = after[x][y] - s
	return after[x][y]
  
def findBeforeMatrix(after):
# This method finds the before matrix element of each element in after matrix
# and returns the before metrix
	for i in range(len(after)):
		for j in range(len(after[0])): // # Calls findBefore function to get before matrix element
			after[i][j] =findBefore(i,j,after)
	return after
*/
////////////////////////////
/////// Arranging Numbers

int countArrangement(int N) {
    vector<int> vs;
    for (int i=0; i<N; ++i) vs.push_back(i+1);
    return counts(N, vs);
}

int counts(int n, vector<int>& vs) {
    if (n <= 0) return 1;
    int ans = 0;
    for (int i=0; i<n; ++i) {
        if (vs[i]%n==0 || n%vs[i]==0) {
            swap(vs[i], vs[n-1]);
            ans += counts(n-1, vs);
            swap(vs[i], vs[n-1]);
        }
    }
    return ans;
}

////////////////////////////




































