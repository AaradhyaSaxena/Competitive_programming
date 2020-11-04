///////////////
/// Can you make palindrome

// /// https://leetcode.com/problems/can-make-palindrome-from-substring/submissions/

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int mask = 0;
    vector<int> ps(1);
    for (char c : s)
        ps.push_back(mask ^= 1 << (c - 'a'));

    vector<bool> r;
    for (auto &q : queries) {
        int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
        r.push_back(q[2] >= odds / 2);
    }
    return r;
}

///////////