///////https://www.interviewbit.com/problems/longest-valid-parentheses/

///// longest valid parenthesis

int Solution::longestValidParentheses(string s) {
    if (s.length() <= 1) 
    	return 0;

    int curMax = 0;
    vector<int> longest(s.size(), 0);
    for (int i = 1; i < s.length(); i++) 
    {
        if (s[i] == ')' && i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(') 
        {
            longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
            
            curMax = max(longest[i], curMax);
        }
    }
    return curMax;
}

///