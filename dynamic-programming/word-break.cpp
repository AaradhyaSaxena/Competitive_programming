//// https://practice.geeksforgeeks.org/problems/word-break/0

#include <bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        mp.clear();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            mp[s] = 1;
        }
        string s, temp;
        cin>>s;
        int len = s.length();
        int dp[len+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i=1; i<=len; i++){
            for(int j=i-1; j>=0; j--){
                temp = s.substr(j,i-j);
                if(mp.find(temp) != mp.end()){
                    dp[i] |= dp[j];
                }
            }
        }
        int ans = (dp[len]==1)?1 :0;
        cout<<ans<<endl;
    }
    return 0;
}

//////////////////////////

// #include <bits/stdc++.h>
// using namespace std;

// struct Trie_Node {
//     struct Trie_Node *child[26];
//     bool isleaf;
// };

// struct Trie_Node *get_node(){
//     struct Trie_Node *ptr = (struct Trie_Node *)(malloc(sizeof(Trie_Node)));
//     if (ptr != NULL){
//         ptr->isleaf = false;
//         for (int i=0; i<26; i++)
//             ptr->child[i] = NULL;
//     }
//     else
//         cout<<"Pointer NULL !!"<<endl;
//     return ptr;

// }

// void insert_string(struct Trie_Node *root, const string s){
//     struct Trie_Node *ptr = root;
//     int index, len = s.length();
//     for (int i=0; i<len; i++){
//         index = CHAR_TO_INT(s[i]);
//         if (ptr->child[index] == NULL)
//             ptr->child[index] = get_node();
//         ptr = ptr->child[index];
//     }
//     ptr->isleaf = true;

// }
// bool search_string(struct Trie_Node *root, string s, int start, int end){
//     struct Trie_Node *ptr = root;
//     int index = CHAR_TO_INT(s[start]);
//     if (root->child[index] == NULL)
//         return false;
//     for (int i=start; i<end; i++){
//         index = CHAR_TO_INT(s[i]);
//         if (ptr->child[index] == NULL)
//             return search_string(root, s, i, end);
//         ptr = ptr->child[index];
//     }
//     if (ptr->isleaf && ptr != NULL)
//         return true;
//     else
//         return false;
// }

// int main(){
//     int t;
//     cin>>t;
//     while (t--){
//         struct Trie_Node *root = get_node();
//         int n;
//         string s;
//         cin>>n;
//         for (int i=0; i<n; i++){
//             cin>>s;
//             insert_string(root, s);
//         }
//         cin>>s;
//         bool ans = search_string(root, s, 0, s.length());
//         if (ans)
//             cout<<1<<endl;
//         else
//             cout<<0<<endl;
//         delete root;
//         root = NULL;

//     }
// }


