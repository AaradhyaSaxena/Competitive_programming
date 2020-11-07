////// sprinklr

/////https://www.hackerearth.com/practice/algorithms/dynamic-programming/
/////introduction-to-dynamic-programming-1/practice-problems/algorithm/avoid-traps-0b92455e/

#include<bits/stdc++.h>
using namespace std;
 
vector<int> A(100001);
void SieveOfEratosthenes(int n) { 
    vector<bool> prime(n+1,true);    
    for (int p=2; p*p<=n; p++) {  
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
	A[0]=0;
	A[1]=0;
    for (int p=2; p<=n; p++) {
       	if (prime[p])
    		A[p]=A[p-1]+1;
		else
			A[p]=A[p-1];
	}
}
 
bool isSpecial(int r1, int r2, int A, int i){
	if(A*r2>=i*r1)
		return true;
	return false;
}
 
int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int T;
	cin>>T;
	SieveOfEratosthenes(100000);
	while(T){
		int r1,r2,n;
		string cells;
		cin>>r1>>r2>>n>>cells;
		cells=" "+cells;
		vector<int> dp(n+1,INT_MAX);
		if(cells[1]=='*' || cells[n]=='*'){
			cout<<"No way!"<<endl;
		}
		else{
			dp[0]=0;
			dp[1]=0;;
			for(int i=1;i<=n;i++){
				if(cells[i]!='*' && dp[i]!=INT_MAX){
					if(i+1<=n && cells[i+1]!='*')
						dp[i+1]=min(dp[i+1],dp[i]+1);
					if(i+2<=n && cells[i+2]!='*')
						dp[i+2]=min(dp[i+2],dp[i]+1);
					if(isSpecial(r1,r2,A[i],i) && i+A[i]<=n && cells[i+A[i]]!='*')
						dp[i+A[i]]=min(dp[i+A[i]],dp[i]+1);
				}
			}
			if(dp[n]!=INT_MAX && dp[n]>=0)
				cout<<dp[n]<<endl;
			else	
				cout<<"No way!"<<endl;
		}
		T--;
	}
}


//////////////////////

////Favorite String
#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N=100005;

int solve(string s)
{
    int n = s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }

    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
    int ans = 0;
    for (int i = 0;i<n;i++)
        ans += d1[i] + d2[i];
    return ans;
}
bool palin(string s)
{
    int n=s.length();
    for(int i=0;i<=(n/2);i++)
        if(s[i]!=s[n-1-i])
            return 0;
    return 1;

}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int z=solve(s);
    int ans=(n*(n+1))/2;
    ans-=z;
    if(palin(s))
        ans++;
    cout<<ans<<endl;



}



int32_t main()
{

        solve();
    return 0;
}

