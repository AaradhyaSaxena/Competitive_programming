///// jpmc

#include<bits/stdc++.h>
using namespace std;

int main() {
	int input1;
	cin>>input1;
	int dp[input1+1];
	for(int i=0; i<input1+1; i++){
		dp[i]= -1;
	}
	dp[0]=0,dp[1]=0,dp[2]=1,dp[3]=1,dp[4]=1;

	for(int i=4; i<=input1; i++){
		for(int j=0; j<i-1; j++){
			if((dp[j]==0 and dp[i-j-2]==0) or ((dp[j]==1 and j<4) and (dp[i-j-2]==1 and (i-j-2<4) ))){
				dp[i]=1;
				break;
			}
		}
		if(dp[i]==-1) dp[i] = 0;
	}
	
	int cnt = 0;
	for(int i=0; i<input1; i++){
		if(dp[i]==1) cnt++;
	}

	return cnt;
	// cout<< cnt;
}




/*
# Write code here
        size = max(input1+1, 6)
        dp = [0]*size
        dp[0] = dp[1] = 0
        dp[2] =dp[3] =dp[4] = 1

        for i in range(4, input1):
            for j in range(i):
                if((dp[j]==0 and dp[i-j-2]==0) or ((dp[j]==1 and j<4) and (dp[i-j-2]==1 and (i-j-2<4) ))):
                    dp[i] = 1
                    break
        
        cnt= 0
        for i in range(input1):
            if(dp[i]==1):
                cnt = cnt +1
        print(cnt)
        return cnt

*/

/////////////////////

#include <bits/stdc++.h>
using namespace std;

int countDivisors(int n) { 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, count only one 
            if (n / i == i) 
                cnt++;
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

int sum_max(int p, int m){
	int dp[p+2], dpm[p+2];
	dp[0] = 0, dpm[0] = 0;
	int maxx = 0;
	for(int i=1; i<=p+2; i++){
		dp[i] = countDivisors(i);
		maxx = max(maxx, dp[i]);
		dpm[i] = maxx;
	}
	int ans = 0;
	for(int i=m; i<=p+m-1; i++){
		ans += dpm[i];
	}
	return ans;
}

int main(){
	int p,m;
	cin>>p>>m;
	cout<<sum_mac(p,m);
}

/////////////////////////

int k = t.K;
    vector<double> p = t.p;
    int num = t.M;
    vector<vector<int>> vec = t.d;
    sort(vec.begin(), vec.end(), comp);
    int head[k] = 0;
    double prob[k] = 0;
    if(vec[0][1]==1){
    	head[0] = 1;
    	prob[0] = 1
    }else{
    	head[0] = 0;
    	prob[0] = 0;
    }
    for(int i=1; i<num; i++){
        if(vec[i][1]==1){
            head[i] = head[i-1]+1;
            prob[i] = head[i]/i;
        }
        else{
            head[i] = head[i-1];
            prob[i] = head[i]/i;
        }
    }
    


    cout<<head<<" "<<tail<<endl;