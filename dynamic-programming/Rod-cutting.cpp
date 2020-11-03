////////https://www.interviewbit.com/problems/rod-cutting/

//// Rod Cutting

vector<int> ans;

void find_ans(vector<vector<int>> pa, int l, int r)
{
    if(pa[l][r] == -1) return;
    else
    {
        ans.push_back(pa[l][r]);
        find_ans(pa, l, pa[l][r]);
        find_ans(pa, pa[l][r], r);
    }
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    int m = B.size();
    ans.clear();
    vector<int> B1(m+2);
    B1[0] = 0; B1[m+1] = A;
    for(int i = 0; i<m; i++){
        B1[i+1] = B[i];
    } 
    vector<vector<int>> dp(m+2,vector<int>(m+2, INT_MAX)), pa(m+2,vector<int>(m+2,-1));
    for(int i = m+1; i>=0; i--)
    {
        for(int j = 0; j<m+2; j++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            if(i>j) continue;
            int cost = B1[j] - B1[i];
            for(int k = i+1; k<j; k++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j] + cost)
                {
                    dp[i][j] = dp[i][k] + dp[k][j] + cost;
                    pa[i][j] = k;
                }
            }
        }
    }
    find_ans(pa, 0, m+1);
    vector<int> final_ans(m);
    for(int i = 0; i<m; i++){
        final_ans[i] = B[ans[i]-1];
    }
    return final_ans;
}

//////////////////////////////
///////////////////////////

void getAns(vector<int> &ans, vector<vector<int>> &dp, int i, int j, vector<int> p) {
    if (i + 1 == j) return;

    for (int k = i + 1; k < j; k++) 
    {
        if (dp[i][k] + dp[k][j] + p[j] - p[i] == dp[i][j]) 
        {
            ans.push_back(p[k]);
            getAns(ans, dp, i, k, p);
            getAns(ans, dp, k, j, p);
            return ;
        }
    }
    return ;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    vector<int> p;
    p.push_back(0);
    for (int b : B) 
    	p.push_back(b);
    p.push_back(A);
    sort(p.begin(), p.end());
    
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l <= n; l++) 
    {
        for (int i = 0; i + l - 1 < n; i++) 
        {
            dp[i][i+l-1] = INT_MAX;
            for (int k = i + 1; k < i + l - 1; k++)
            {
                dp[i][i+l-1] = min(dp[i][i+l-1], dp[i][k] + dp[k][i+l-1] + p[i+l-1] - p[i]);
            }
        }    
    }

    vector<int> ans;
    getAns(ans, dp, 0, n - 1, p);
    return ans;
}

//////////////


typedef long long LL;

//ans vector
vector<int> ans;

//cuts vector
vector<int> ar;

//dp array
vector<vector<LL> > dp;

//parent array
vector<vector<int> > parent;

//solve for dp(l, r)
LL rec(int l, int r){
    //base case
    if(l+1>=r)return 0;

    //for memoisation
    LL &ret=dp[l][r];

    if(ret!=-1)return ret;


    ret=LLONG_MAX;
    int bestind;    //stores the best index

    for(int i=l+1; i<r; i++){
        //recurrence
        LL p=rec(l,i)+rec(i,r) + (LL)ar[r]-(LL)ar[l];

        //update best
        //note that we choose lexicographically smallest index
        //if multiple give same cost
        if(p<ret){
            ret=p;
            bestind=i;
        }
    }
    //store parent of (l, r)
    parent[l][r]=bestind;
    return ret;
}

//function for building solution
void back(int l, int r){
    //base case
    if(l+1>=r)return;

    //first choose parent of (l,r)
    ans.push_back(ar[parent[l][r]]);

    //call back recursively for two new segments
    //calling left segment first because we want lexicographically smallest
    back(l,parent[l][r]);
    back(parent[l][r],r);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    //insert A and 0
    B.push_back(A);
    B.insert(B.begin(),0);


    int n=B.size();
    ar.clear();
    for(int i=0; i<n; i++)
        ar.push_back(B[i]);

    //initialise dp array
    dp.resize(n);
    parent.resize(n);
    ans.clear();
    for(int i=0; i<n; i++){
        dp[i].resize(n);
        parent[i].resize(n);
        for(int j=0; j<n; j++)
            dp[i][j]=-1;
    }

    //call recurrence
    LL best=rec(0,n-1);

    //build solution
    back(0,n-1);

    return ans;
}
