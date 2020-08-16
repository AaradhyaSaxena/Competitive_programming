///////https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

bool strmatch(string str, string pattern, int n, int m){ 
    if (m == 0) return (n == 0); 
  
    bool lookup[n + 1][m + 1]; 
    memset(lookup, false, sizeof(lookup)); 
  
    lookup[0][0] = true; 
  
    // Only '*' can match with empty string 
    for (int j = 1; j <= m; j++) 
        if (pattern[j - 1] == '*') 
            lookup[0][j] = lookup[0][j - 1]; 
  
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= m; j++) 
        { 
            if (pattern[j - 1] == '*') 
                lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j]; 
  
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1]; 
  
            else lookup[i][j] = false; 
        } 
    } 
  
    return lookup[n][m]; 
} 

int wildCard(string pattern,string str){
    if (strmatch(str, pattern, str.length(), pattern.length())) 
        return 1; 
    else
        return 0; 
}










