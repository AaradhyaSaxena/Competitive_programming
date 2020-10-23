///// Dgraph labs

///// IIT BHU

///// Binary search
////https://www.geeksforgeeks.org/maximum-of-minimum-difference-of-all-pairs-from-subsequences-of-given-size/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool possible(int mid, int n, int k, int arr[]){
	int cnt =1;
	int elem = arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]-elem>=mid){
			cnt++;
			elem = arr[i];
		}
		if(cnt>=k){
			return true;
		}
	}
	return false;
}

int helper(int n, int k, int arr[]){
	sort(arr, arr+n);
	int ans = 0;
	int start = 0, end = arr[n-1]-arr[0];
	while(start<=end){
		int mid = start+(end-start)/2;
		if(possible(mid,n,k,arr)){
			start = mid+1;
			ans = mid;
		}
		else{
			end = mid-1;
		}
	}
	return ans;
}

int main(){
	int n, k; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>k;
	int ans = helper(n,k,arr);
	cout<<ans<<endl;
}

////////////////////////////
////////////////////////////
///// https://www.geeksforgeeks.org/find-two-numbers-sum-xor/
//// Sum and XOR of number

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll s,x;
	cin>>s>>x;
	ll A =(s-x)/2;
	ll a = 0, b = 0;
	for(int i=0; i<64; i++){
		int xi = x&(1<<i);
		int Ai = A&(1<<i);
		if(Ai==0 and xi==0){
		}
		if(xi==0 and Ai>0){
			a = a|(1<<i);
			b = b|(1<<i);
		}
		if(xi>0 and Ai==0){
			a = a|(1<<i);
		}
		else{
			// cout<<"not possible"<<endl;
		}
	}
	cout<<a<<" "<<b<<endl;
}
///////////////
/////// Office location
// https://imgur.com/a/ooNNVhd

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int minDist(int w, int h, vector<pi> arr){

    int res = 0;

    // for(auto it: arr) cout<<it.first<<" "<<it.second<<endl;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int k1 = 10000;
            for(auto it: arr){
                int k = abs(i - it.first) + abs(j - it.second);
                k1 = min(k1, k);
            }
            res = max(k1, res);
        }
    }

    return res;
}


int findMinDistance(int w, int h, int n) {

    vector<pi> points;

    int ans = INT_MAX;
    int tot = w*h;

    for(int i = 0; i < tot; i++){
        int xi = i/w, yi = i%w;
        points.push_back({xi, yi});
        if(n == 1) ans = min(ans, minDist(w, h, points));
        if(n > 1){
            for(int j = i+1; j < tot; j++){
                int xj = j/w, yj = j%w;
                points.push_back({xj, yj});
                if(n == 2) ans = min(ans, minDist(w, h, points));
                if(n > 2){
                    for(int k = j+1; k < tot; k++){
                        int xk = k/w, yk = k%w;
                        points.push_back({xk, yk});
                        if(n == 3) ans = min(ans, minDist(w, h, points));
                        if(n > 3){
                            for(int l = k+1; l < tot; l++){
                                int xl = l/w, yl = l%w;
                                points.push_back({xl, yl});
                                if(n == 4) ans = min(ans, minDist(w, h, points));
                                if(n > 4){
                                    for(int m = l+1; m < tot; m++){
                                        int xm = m/w, ym = m%w;
                                        points.push_back({xm, ym});
                                        ans = min(ans, minDist(w, h, points));
                                        points.pop_back();
                                    }
                                }
                                points.pop_back();
                            }
                        }
                        points.pop_back();
                    }
                }
                points.pop_back();
            }
        }
        points.pop_back();
    }

    return ans;
}


///////////////////////////
/////////////////// IIT D

/// https://leetcode.com/problems/cherry-pickup/solution/

int cherryPickup(vector<vector<int>>& grid) {
    int N = grid.size();
    int P_LEN = N + N - 1;
    vector<vector<int> > dp = vector<vector<int>>(N, vector<int>(N, -1));
    dp[0][0] = grid[0][0];
    
    for (int p = 2; p <= P_LEN; p++) {//p is the length of the path
        for (int x1 = N - 1; x1 >= 0; x1--) {
            for (int x2 = x1; x2 >= 0; x2--) {
                int y1 = p - 1 - x1;
                int y2 = p - 1 - x2;
                if (y1 < 0 || y2 < 0 || y1 >= N || y2 >= N)
                    continue;
                if (grid[y1][x1] < 0 || grid[y2][x2] < 0) {
                    dp[x1][x2] = -1;
                    continue;
                }   
                int best = -1, delta = grid[y1][x1];
                if (x1 != x2)
                    delta += grid[y2][x2];
                if (x1 > 0 && x2 > 0 && dp[x1 - 1][x2 - 1] >= 0) //from left left
                    best = max(best, dp[x1 - 1][x2 - 1] + delta);
                if (x1 > 0 && y2 > 0 && dp[x1 - 1][x2] >= 0) //from left up
                    best = max(best, dp[x1 - 1][x2] + delta);
                if (y1 > 0 && x2 > 0 && dp[x1][x2 - 1] >= 0) //from up left
                    best = max(best, dp[x1][x2 - 1] + delta);
                if (y1 > 0 && y2 > 0 && dp[x1][x2] >= 0) //from up up
                    best = max(best, dp[x1][x2] + delta);
                dp[x1][x2] = best;
            }
        }
    }
    return dp[N - 1][N - 1] < 0 ? 0 : dp[N - 1][N - 1];
}

///////////



/////////////////
///////////////// IIT G

/*
Find the count of all pairs of integers in an array such that their sum is a multiple of 60. 
One element can be present in multiple pairs. For example if the given  array is [20,40,100], 
answers are [20,40] and [20,100] => Use map.
*/

#include <bits/stdc++.h> 
using namespace std; 

 
int main() 
{ 
    int n,i;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int ans=0; //no of pairs
	unordered_map<int,int> mp; //storing count of remainders (arr[i]%60)
	for(i=0;i<n;i++)
	{
	    if(arr[i]%60==0)
	    {
	        ans+= mp[0]; //Two multiples of 60 can be added together to form another multiple of 60
	    }
	    else
	    {
	        //If curent guy has remainder= z and there are k guys that we have found earlier
	        //having remainder= 60-z, then there will be k no of pairs having remainder 0 when divided
	        //by 60
	        int tofind= 60-(arr[i]%60);
    	    if(mp[tofind]>=1)
    	    {
    	        ans+=mp[tofind];
    	    }
	    }
	    //we add current guy to our remainders map
	    mp[arr[i]%60]++;
	    
	    
	}
	cout<<ans;
} 

//////////



