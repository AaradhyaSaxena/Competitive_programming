//////// trie

#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

struct trie{
    int w;
    trie *child[26];
};

trie* getnode(){
    trie* node = new trie();
    node->w = 0;
    for(int i=0; i<26; i++){
        node->child[i] = NULL;
    }
    return node;
}

void insert(trie *A, pair<string,int> pr){
    string s = pr.f; int we = pr.s;
    trie *curr = A;
    for(int i=0; i<s.length(); i++){
        int idx = int(s[i] - 'a');
        if(!curr->child[idx]){
            curr->child[idx] = getnode();
        }
        curr->w = max(curr->w, we);
        curr = curr->child[idx];
    }
}

int find(trie *node, string str){
    int ans =0;
    trie *curr = node;
    for(int i=0; i<str.length(); i++){
        int idx = int(str[i]-'a');
        if(!curr->child[idx]){
            return -1;
        }
        curr = curr->child[idx];
        ans = node->w;
    }
    return ans;
}

int main(){
    int n,q;
    cin>>n>>q;
    string s;
    int x;
    trie *node = getnode();
    for(int i=0; i<n; i++){
        cin>>s; cin>>x;
        insert(node,{s,x});
    }
    vector<string> qr;
    for(int i=0; i<q; i++){
        cin>>s; 
        qr.push_back(s);
    }
    
    for(int i=0; i<q; i++){
        int ans = find(node, qr[i]);
        cout<<ans<<endl;
    }
    return 0;
}

//////////////////////////////

//////// HOTEL REVIEWS
/*
Given a set of reviews provided by the customers for different hotels and a string containing Good Words,
you need to sort the reviews in desc order according to their Goodness Value(Higher goodness value first).
We define the Goodness Value of a string as the number of Good Words in that string.

*/

struct trie{
    int isLeaf;
    trie *child[26];
};
 
trie *getNode(){
    trie *node = new trie();
    for(int i=0; i<26; i++)
        node->child[i] = NULL;
    node->isLeaf = 0;
    
    return node;
}
 
void insert(trie *A, string s){
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            curr->child[idx] = getNode();
        
        curr = curr->child[idx];
    }
    curr->isLeaf = 1; 
}
int search(trie *A, string s){
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            return 0;
        
        curr = curr->child[idx];
    }
    return (curr && curr->isLeaf);
}
void convert(string &str){
    //Convert _ to spaces
    for(int i=0; i<str.size(); i++)     
    {
    if(str[i] == '_')    
         str[i] = ' ';
    }
    return;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first) 
        return a.second < b.second;
    
    return a.first > b.first;    
}

vector<int> Solution::solve(string A, vector<string> &B){
    vector<int > v;
    vector<pair<int, int>> v1;
 
    trie *root = getNode();
    convert(A);
    string word;
    stringstream ss;
    ss<<A;
 
    while(ss>>word)    
        insert(root, word);
    
    int cnt;
    for(int i=0; i<B.size(); i++){
        convert(B[i]);
        ss.clear();
        ss<<B[i];
        cnt = 0;
        while(ss>>word)    {
            if(search(root, word))    
            cnt++;
        }
        v1.push_back({cnt, i});
    }
    
    sort(v1.begin(), v1.end(), cmp);
    
    for(int i=0; i<B.size(); i++)
        v.push_back(v1[i].second);
    
    return v;  
}

/////////////////////////

////// Shortest unique prefix

/*
Find shortest unique prefix to represent each word in the list.
Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov

*/



struct trie{
    int leaf;
    trie *child[26];
};

trie *getnode(){
    trie *node = new trie();
    node->leaf= 0;
    for(int i=0; i<26; i++){
        node->child[i] == NULL;
    }
    return node;
}

trie *insert(trie *root, string s){
    trie *curr = root;
    for(int i=0; i<s.length(); i++){
        int idx = int(s[i] - 'a');
        curr->leaf += 1;
        if(!curr->child[idx]){
            curr->child[idx] = getnode();
        }
        curr = curr->child[idx];
    }
    return curr;
}

string findPrefix(trie* head, string s){
    int n = s.length();
    string prefix = "";
    trie *current = head;
    int i = 0;
    current = current->child[s[i]-'a'];
    prefix += s[i];
    
    for (i = 1; i<n; ++i)
    {
        if (current->leaf == 1)
            return prefix;
        current = current->child[s[i]-'a'];
        prefix += s[i];
    }
    return prefix;
}
vector<string> Solution::prefix(vector<string> &A) {
    vector<string> vec;
    trie *root = new trie();
    for(int i=0; i<A.size(); i++){
        insert(root,A[i]);
    }
    root->leaf = A.size();
    
    for(int i=0; i<A.size(); i++){
        string str ="";
        str = findPrefix(root,A[i]);
        vec.push_back(str);
    }
    
    return vec;
}

/////////////////////////////////









