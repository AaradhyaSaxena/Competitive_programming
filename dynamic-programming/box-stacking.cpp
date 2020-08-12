///// https://practice.geeksforgeeks.org/problems/box-stacking/1

#include<bits/stdc++.h>
using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}

bool comp(const vector<int> &a,const vector<int> &b){
    return (a[1]*a[2]) < (b[1]*b[2]);
}
int maxHeight(int h[],int w[],int l[],int n)
{
    vector<vector<int> > v;
    vector<int> z;
    for(int i=0;i<n;i++){
        z.push_back(h[i]); z.push_back(w[i]); z.push_back(l[i]);
        v.push_back(z); z.clear();
        z.push_back(w[i]); z.push_back(l[i]); z.push_back(h[i]);
        v.push_back(z); z.clear();
        z.push_back(l[i]); z.push_back(h[i]); z.push_back(w[i]);
        v.push_back(z); z.clear();
    }
    sort(v.begin(),v.end(),comp);
    int x = 3*n;
    int dp[x];
    int ans = 0;
    
    for(int i=0; i<x; i++)
    {
        dp[i] = v[i][0];
        
        int l1 = min(v[i][1],v[i][2]);
        int b1 = max(v[i][1],v[i][2]);
        
        for(int j=0; j<i; j++)
        {
            int l2 = min(v[j][1],v[j][2]);
            int b2 = max(v[j][1],v[j][2]);
            
            if(l2 < l1 && b2 < b1)
                dp[i] = max(dp[i],dp[j] + v[i][0]);
        }
        ans = max(ans,dp[i]);
    }
    
    return ans;
}





