//////// trie

#include<bits/stdc++.h>
using namespace std;

struct trieNode 
{
	trieNode *children[26];
	bool endofword;
	int weight;
};

trieNode *newNode() {
	trieNode *node = new trieNode();
	for (int i = 0; i < 26; ++i) {
		node->children[i] = NULL;
	}
	node->endofword = false;
	node->weight = -1;
	return node;
}

void insert(trieNode *root, string s,int weight) {
	trieNode *node = new trieNode();
	node = root;
	for (int i = 0; i < s.length(); ++i) {
		int index = s[i] - 'a';
		if (!node->children[index])
			node->children[index] = newNode();
			node = node->children[index];

		if (node->weight < weight)
			node->weight = weight;
	}
	node->endofword = true;
}

void search(trieNode *root, string s) {
	trieNode *node = new trieNode();
	node = root;
	for (int i = 0; i < s.length(); ++i) {
		int index = s[i] - 'a';
		if (!node->children[index]) {
			cout << -1 << endl;
			return;
		}
		node = node->children[index];
	}
	cout << node->weight << endl;
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	trieNode *root = newNode();
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) 
	{
		string s;
		int weight;
		cin >> s >> weight;
		insert(root, s, weight);
	}
	while(q--) 
	{
		string s;
		cin >> s;
		search(root, s);
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

/*
Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.
Return this maximum xor value.

Solution::
You should use a Trie data structure here:

    Create a binary trie using all the elements of the second array. Start with the Most Significant Bit and
     head towards the Least Significant Bit.
    Each non-leaf node of the trie has 1-2 children. Going down the left child is like getting a bit equal to zero, 
     right means getting a one.
    Initialise result to zero, maximum to -infinity.
    For each element of the first array
        Set BIT = MSB of this element. Go to the root of the trie.
        If there is only one child, follow it.
        Else
            If the element_bit is 1, follow the left child. This will give the maximum xor.
            Else, follow the right child.
        When following a child pointer, set the bit at BIT of result to (child_pointer ^ element_BIT_bit).
        Decrement BIT and go back to point a, as long as BIT>=0.
    If the result is greater than maximum, set maximum to result.
    Output maximum.

The time complexity is O(max(A.size(),B.size())).
*/


class trienode{
    public:
    trienode* left;
    trienode* right;
    trienode(){
        left=NULL;
        right=NULL;
    }
};
class Trie{
    public:
    trienode* root;
    int mxor;
    Trie(){
        root = new trienode();
        mxor=0;
    }
    void insert(int n){
        trienode* temp=root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i) & 1;
            if(bit==0){
                if((temp->left) != NULL) temp=temp->left;
                else{
                    trienode* nw = new trienode();
                    temp->left=nw;
                    temp=nw;
                }
            }
            else{
                if((temp->right) != NULL) temp=temp->right;
                else{
                    trienode* nw = new trienode();
                    temp->right = nw;
                    temp=nw;
                }
            }
        }
    }
    void findmxor(int n){
        int ans=0;
        trienode* temp=root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit==0){
                if((temp->right) != NULL){
                    ans += (1<<i);
                    temp=temp->right;
                }
                else  temp=temp->left;
            }
            else{
                if((temp->left) !=NULL){
                    ans+=(1<<i);
                    temp=temp->left;
                }
                else  temp=temp->right;
            }
        }
        if (ans>mxor) mxor=ans;
    }
};
int Solution::solve(vector<int> &A, vector<int> &B) {
    Trie t;
    for(int i=0;i<A.size();i++)t.insert(A[i]);
    for(int i=0;i<B.size();i++)t.findmxor(B[i]);
    return t.mxor;
}

/////////////////////













