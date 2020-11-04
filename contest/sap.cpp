////// sap

////// Sorted Arrangement

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

/////////////

def getCount(arr, num):
    if(len(arr) == 0 or len(arr) == 1 or max(arr) == num):
        return 1
    else:
        left = 0
        right = 0
        for i in range(len(arr)):
            if(num < arr[i]):
                left = left + 1
            if(num > arr[i]):
                right = right + 1
        return right * 2 + 1 if right <= left else left * 2 + 1

def minimumOperations(numbers):
    arr = []
    tot = 0
    for i in range(len(numbers)):
        tot = tot + getCount(arr, numbers[i])
        arr.append(numbers[i])
    return tot

test1 = [10, 7, 3, 2, 1, 5, 2, 5]
test2 = [1, 1, 1, 1, 2, 2, 3, 4, 5]

print minimumOperations(test1)
print minimumOperations(test2)

//////////////////////////////////
////////////////////////////
/////////////////////////////

////////// city attraction
///////////////////////////

int dfs(int i, vector<vector<int>> adj, int time){
	vis[i] = true;
	int score = vec[i];

	for(int to: adj[i]){
		if(vis[to]==0 and (2*adj[i][to])<= time){
			score += dfs(to, adj, time-2*adj[i][to]);
		}
	}

	return score;
}

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



