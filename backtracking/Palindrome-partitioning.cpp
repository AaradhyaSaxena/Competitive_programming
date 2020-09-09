/////////https://www.interviewbit.com/problems/palindrome-partitioning/

///// Palindrome-partitioning

bool isPalindrome(string &str, int s, int e) {
    while (s < e) {
        if (str[s] != str[e])
            return false;
        s++;
        e--;
    }
    return true;
}

void partitionHelper(int i,vector<string> &current,string &s,vector<vector<string>> &ans){
    if (i == s.length()) {
        ans.push_back(current);
        return;
    }
    for (int j = i; j < s.length(); ++j) {
        if (isPalindrome(s, i, j)) {
            current.push_back(s.substr(i, j - i + 1));
            partitionHelper(j + 1, current, s, ans);
            current.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string s) {
    vector<vector<string> > ans;
    vector<string> current;
    partitionHelper(0, current, s, ans);
    return ans;
}

////