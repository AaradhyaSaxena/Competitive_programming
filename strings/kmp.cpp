///////// KMP

vector<int> prefix_function (string s) {

    int n = (int) s.length();
    vector<int> pi(n);
    pi[0]=0;

    for (int i=1; i<n; ++i){
        int l = pi[i-1];

        // if s[i] != s[l] then, reduce l one at a time.
        while (l > 0 && s[i] != s[l])
            l = pi[l-1];

        // if ith character matches, character at s[l]
        if (s[i] == s[l])  ++l; // (biggest suffix possible)   
        pi[i] = l;
    }
    return pi;
}


/////////////





