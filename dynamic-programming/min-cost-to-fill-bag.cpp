#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

int MinimumCost(int cost[], int n, int W){
    vector<int> val, wt;

    int size = 0;
    for (int i=0; i<n; i++){
        if (cost[i]!= -1){
            val.push_back(cost[i]);
            wt.push_back(i+1);
            size++;
        }
    }

    n = size;
    int min_cost[n+1][W+1];

    for (int i=0; i<=W; i++)
        min_cost[0][i] = INF;

    for (int i=1; i<=n; i++)
        min_cost[i][0] = 0;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=W; j++)
        {
            if (wt[i-1] > j)
                min_cost[i][j] = min_cost[i-1][j];

            else
                min_cost[i][j] = min(min_cost[i-1][j], min_cost[i][j-wt[i-1]] + val[i-1]);
        }
    }

    return (min_cost[n][W]==INF)? -1: min_cost[n][W];
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int cost[n];
        for(int i=0; i<n; i++){
            cin>>cost[i];
        }
        cout << MinimumCost(cost, n, w)<<endl;
    }
    return 0;
}

////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,w;
	    cin>>n>>w;
	    long long int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    long long int dp[n+1][w+1];
	    memset(dp,-1,sizeof(dp));
	    for(int j=0; j<=w; j++){
	    	dp[0][j] = INT_MAX;
	    }
	    for(int i=0; i<=n; i++){
	    	dp[i][0] = 0;
	    }
	    for(int i=1; i<=n; i++){
	        if(arr[i-1]==-1){
	            continue;
	        }
	    	for(int j=1; j<=w; j++){
	    		if(j>=i){
	    			dp[i][j] = min(dp[i-1][j], arr[i-1]*(j/i) + dp[i-1][j%i]);
	    		}else{
	    			dp[i][j] = dp[i-1][j];
	    		}
	    		//cout<<dp[i][j]<<" ";
	    	}//cout<<endl;
	    }
	    cout<<dp[n][w]<<endl;
	}
	return 0;
}

/////////////////////////


