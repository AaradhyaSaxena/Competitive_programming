///////

//// path finder with pathholes

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pp pair<pair<int,int>,int>
vector<int>row={1,0,0,-1};
vector<int>col={0,1,-1,0};

bool isValid(int i,int j,int n,int m)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {
        return 1;
    }
    else return 0;
}

int main()
{
    ll m,n,y,x,p;
    cin>>n>>m>>x>>y>>p;
    x--;y--;
    vector<vector<ll>>A(n,vector<ll>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
            if(A[i][j]==0)
            {
                A[i][j]=INT_MAX;
            }
            if(A[i][j]==1)
            {
                A[i][j]=INT_MIN;
            }
        }
    }
    vector<vector<ll>>pot(p,vector<ll>(3));
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>pot[i][j];
            if(j==0||j==1)
            {
                pot[i][j]--;
            }
        }
        ll xx=pot[i][0];
        ll yy=pot[i][1];
        A[xx][yy]=pot[i][2];
    }
    
    queue<pp>q;
    q.push({{0,0},0});
    
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    visited[0][0]=1;
    while(!q.empty())
    {
        ll xx=q.front().first.first;
        ll yy=q.front().first.second;
        ll tim=q.front().second;
        q.pop();
        if(xx==x && yy==y)
        {
            cout<<tim-1<<endl;
            return 0;
        }
        for(int k=0;k<4;k++)
        {
            ll newx=xx+row[k];
            ll newy=yy+col[k];
            if(isValid(newx,newy,n,m) && visited[newx][newy]==0 && A[newx][newy]!=INT_MIN && 1+tim<=A[newx][newy])
            {
                
                visited[newx][newy]=1;
                q.push({{newx,newy},tim+1});
            }
        }
    }
    cout<<"Work From Home"<<endl;
    
    return 0;
}


//// two strings subsequence

/*
Two strings S and T (T is a subsequence of S) are given and an array of indices is given. 
Find the maximum number of characters at the index 
(given by each array element) can be removed such that T is still a subsequence of S.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n = s1.length(), m = s2.length();
	int arr[n+1];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int ans = 0;
	int start = 0, end = n;
	while(start<end){
		int mid = start + (end-start)/2;
		string s = s1;
		int p1=0,p2 =0;
		for(int i=0; i<mid; i++){
			s[arr[i]-1] = '#';
		}
		while(p1<n and p2<m){
			if(s[p1]==s2[p2]){
				p1++; p2++;
			}
			else p1++;
		}
		if(p2==m){
			start = mid+1;
			ans = mid;
		}
		else end = mid-1;
	}
	cout<< ans<<endl;
}

//// GCD from root to leaf number of ways



