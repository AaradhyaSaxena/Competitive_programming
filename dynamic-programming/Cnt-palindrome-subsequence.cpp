//// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
/// count palindromic sub-sequence

/// recursive solution

int helper(string str, int i, int j){
    if(i==j){
        return 1;
    }
    if(str[i]==str[j]){
        return helper(str,i+1,j) + helper(str,i,j-1) + 1; 
    }
    else{
        return helper(str,i+1,j) + helper(str,i,j-1) - helper(str, i+1, j-1);
    }
}


int countPS(string str){
    int n = str.length();
    return helper(str,0,n-1);
}
 
//////////////////////////////

//// dynamic-prorgamming

int dp[30][30];

int helper(int dp[][], string str, int i, int j){
	if(i>j) return 0;
    if(i==j){
    	dp[i][j] = 1;
        return 1;
    }
    if(dp[i][j]!=-1){
    	return dp[i][j];
    }
    if(str[i]==str[j]){
    	dp[i][j] = helper(str,i+1,j) + helper(str,i,j-1) + 1;
        return dp[i][j]; 
    }
    else{
    	dp[i][j] = helper(str,i+1,j) + helper(str,i,j-1) - helper(str, i+1, j-1);
        return dp[i][j];
    }
}

int countPS(string str){
    int n = str.length();
    memset(dp,-1,sizeof(dp));
    return helper(str,0,n-1);
}


///////////////////
// editorial

int countPS(int i,int j) 
{ 
      
    if(i>=n||j<0) 
    	return 0; 
      
    if(dp[i][j]!=-1) 
    	return dp[i][j]; 
      
    // base cases 
    if(abs(i-j)==1) { 
        if(str[i]==str[j]) // eg-> aaa 
        	return dp[i][j] = 3; 
        else             // eg-> ab 
        	return dp[i][j] = 2; 
    } 
      
    if(i==j) 
    	return dp[1][j] = 1; 
      
    else if (str[i] == str[j]) 
		return dp[i][j] = countPS(i+1, j) + countPS(i, j-1) + 1; 
      
	else
		return dp[i][j] = countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1); 
      
} 
