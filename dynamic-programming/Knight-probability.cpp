/////////https://practice.geeksforgeeks.org/problems/probability-of-knight/0

//// knight probability

#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];

int dx = {-2,-2,-1,-1,1,1,2,2};
int dy = {-1,1,-2,2,-2,2,-1,1};

bool isvalid(int x,int y, int n){
    if(x>n or x<=0 or y>n or y<=0){
        return false;
    }
    return true;
}

int helper(int n,int k,int x,int y){
	if(k==0){
		return dp[x][y][1];
	}
    if(dp[i][j][1] != 0 or dp[i][j][0] != 0){
    	return dp[i][j][1];
    }
    for(int i=0; i<8; i++){
    	int X = x+dx[i];
    	int Y = y+dy[i];
    	if(!isValid(X,Y,n)){
    		dp[x][y][0] += 1;
    	}else{
    		dp[x][y][1] += helper(n,k-1,X,Y);
    	}
    }
    return dp[x][y][1];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k,x,y;
	    cin>>n>>k>>x>>y;
	    memset(dp,0,sizeof(dp));
	    helper(n,k,x,y);

	    // float ans = dp[x][y][1]/(dp[x][y][1] + dp[x][y][0]);

	    // cout<<ans<<endl;
	    // cout<<dp[x][y][1]<<" "<<dp[x][y][0]<<endl;
	}
	return 0;
}
////////////////////////////////////////
///////////////////////////////////////

double a[101][101][101];
int n;

int u[] = {-2,-2,2,2,-1,-1,1,1};
int v[] = {-1,1,1,-1,2,-2,2,-2};

int main() {
    int t,x,y,i,j,k,z,l;
    cin>>t;
    double d;
    while(t--){
        d = 0;
        cin>>n>>x>>y>>z;
        if(k == 0){
            cout<<1<<endl;
            continue;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                for(k=0;k<=z;k++)
                    a[i][j][k] = 0;
        }
        a[x][y][0] = 1;
        for(k=0;k<z;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    for(l=0;l<8;l++)
                        if(u[l]+i < n and u[l]+i >= 0 and 
                            v[l]+j < n and v[l]+j >= 0)
                        a[u[l]+i][v[l]+j][k+1] += (1/8.0)*a[i][j][k];
                }
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                d += a[i][j][z];
        printf("%.6lf\n",d);
    }
	return 0;
}