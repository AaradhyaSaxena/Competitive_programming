//https://stackoverflow.com/questions/46244948/algorithm-for-optimal-expected-amount-in-a-profit-loss-game

////// expectation profit

#include <bits/stdc++.h>
using namespace std;

double helper(int g, int b){
	double dp[g+1][b+1];
	for(int i=0; i<=g; i++){
		for(int j=0; j<=b; j++){
			dp[i][j] = 0.0;
		}
	}
	for(int i=0; i<=g; i++) dp[i][0] = i*(1.0);
	cout.precision(2);

	for(int i=1; i<=g; i++){
		for(int j=1; j<=b; j++){
			dp[i][j] = max(0.0, (i* (dp[i-1][j] +1.0) + j* (dp[i][j-1] -1.0)) * (1.0/(i+j)));
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	return dp[g][b];
}


int main() {
	int g = 8, b= 10;
	cout<<helper(g,b)<<endl;
	return 0;
}

//////////









