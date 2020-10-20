////////
//// Gameskraft

//// p1 >> Reconstructing arrays

#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<vector<long long int>>>> dp;
int mod = 1e9+7;

int solve(int num, int maxx, int tc, int last_idx){
	if(num==0){
		if(tc==0) return 1;
		return 0;
	}
	if(dp[num][maxx][tc][last_idx]==-1) return dp[num][maxx][tc][last_idx];
	long long val = 0;
	for(int i=last_idx+1; i<maxx; i++){
		val += solve(num-1,maxx,tc-1,i);
	}
	val += last_idx * 1ll * solve(num-1,maxx,tc,last_idx);
	val %= mod;
	
	return dp[num][maxx][tc][last_idx] = val;
}

void generate_ans(vector<int> num, vector<int> maxx, vector<int> tc, int n){
	dp.resize(51,vector<vector<vector<long long>>> (101,vector<vector<long long>>(51, vector<long long> (51,-1)) ))
	int val =0;
	for(int i=0; i<n; i++){
		val = 0;
		for(int j=1; j<=maxx[i]; j++){
			val += solve(num[i]-1,maxx[i],tc[i],j);
			val %= mod;
		}
		cout<<val<<endl;
	}
}

int main(){
	int t, n, x;
	cin>>t;
	vector<int> num, maxx ,tc;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x;
		num.push_back(x);
	}
	cin>>n; 
	for(int i=0; i<n; i++){
		cin>>x;
		maxx.push_back(x);
	}
	cin>>n; 
	for(int i=0; i<n; i++){
		cin>>x;
		tc.push_back(x);
	}
	generate_ans(num,maxx,tc,t);
}

////////////

    #include <bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    #define MAX 100005
    int BIT[MAX];
    int n;

    void initialize(){
    	for(int i=0; i<MAX; i++){
    		BIT[i] = 0;
    	}
    }
     
    void update(int i, int val){
    	while(i<MAX){
    		BIT[i] += val;
    		i += i&(-i);
    	}
    }
     
    int sum(int i){
    	int res = 0;
    	while(i>0){
    		res += BIT[i];
    		i -= i&(-i);
    	}
    	return res;
    }
     
     
    int main() {
    	n=0;
    	cin>>n;
    	vector<int> vec;
    	initialize();
    	for(int i=0; i<n; i++){
    		int x; cin>>x;
    		vec.push_back(x);
    	}
    	int res = 0;
    	for(int i=0; i<n; i++){
    		update(vec[i],1);
    		int large = i+1-sum(vec[i]);
    		int small = sum(vec[i]-1);
    		res += 2*1ll*min(large,small)+1;
    	}
    	cout<<res<<endl;
    	return 0;
    }

///////////////////
////////////////////


/// gamesckraft 20

// https://leetcode.com/discuss/interview-question/800573/path-to-a-goal-coding-question-asked-at-gameskraft

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int calc(string str,int n,int x,int y)
{
	const ll mod=1e9+7;
	ll i,j,len = str.length();
	ll src=x,dest=y,pos,val=n,flag;
	string temp;
	set<string> st;
	for(i=0;i<(1<<len);i++)
	{
		pos=src;
		flag=1;
		for(j=0;j<len;j++)
		{
			if(i&(1<<j))
			{
				if(str[i]=='l')
					pos--;
				else
					pos++;
				if(pos<;0 || pos>n)
				{
					flag=0;
					break;
				}
			}
		}
		if(pos==dest && flag)
		{
			temp="";
			for(j=0;j<len;j++)
			{
				if((1<<j)&i)
					temp+=str[j];
			}
			st.insert(temp);
		}
	}
	return (int)(st.size()%mod);
}

int main()
{
	string str;
	int n,x,y;
	cin>>str;
	cin>>n>>x>>y;
	cout<<calc(s,n,x,y)<<endl;	
}

//////////////////





