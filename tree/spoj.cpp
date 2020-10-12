////////https://www.spoj.com/problems/NDS/

///// inc num

#include <bits/stdc++.h>
using namespace std;

void build_tree(int *tree, int s, int e, int index){
	if(s>e){
		return;
	}
	if(s==e){
		cin >> tree[index];
		return;
	}
	int mid = (s+e)/2;
	build_tree(tree, s, mid, 2*index);
	build_tree(tree, mid+1, e, 2*index+1);
	tree[index] = tree[2*index] ^ tree[2*index+1];
}

int query(int *tree, int ns, int ne, int qs, int qe, int index){
	if(ne<qs || ns>qe){
		return 0;
	}
	if(ns>=qs && ne<=qe){
		return tree[index];
	}
	int mid = (ns+ne)/2;
	return query(tree, ns, mid, qs, qe, 2*index) ^ query(tree, mid+1, ne, qs, qe, 2*index+1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		int *tree = new int[4*n+1];
		build_tree(tree, 0, n-1, 1);
		while(q--){
			int l, r;
			cin >> l >> r;
			cout << (tree[1] ^ query(tree, 0, n-1, l-1, r-1, 1) ) << endl;
		}
		delete [] tree;
	}
	return 0;
}
///////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// void build(int node, int start, int end, vector<int> arr, vector<int> tree){
//     if(start>end) {
//         return;
//     }
//     if(start==end){
//         tree[node] = arr[start];
//         return;
//     }
//     else{
//         int mid = (start+end)/2;
//         build(2*node, start,mid,arr,tree);
//         build(2*node+1, mid+1,end,arr,tree);
//         tree[node] = tree[2*node]^tree[2*node+1];
//     }
// }

// int query(int node, int start, int end, int l, int r, vector<int> arr, vector<int> tree){
//     if(r<start or end<l){
//         return 0;
//     }
//     if(l<= start and end<=r){
//         return tree[node];
//     }
//     int mid = (start+end)/2;
//     int p1 = query(2*node, start, mid,l,r,arr,tree);
//     int p2 = query(2*node+1, mid+1,end,l,r,arr,tree);
//     return p1^p2;
// }

// int main() {
// 	int t; 
// 	cin>>t;
// 	while(t--){
// 	    int n,q;
// 	    cin>>n>>q;
// 	    vector<int> arr(2*n+1), tree(2*n+1);
// 	    int xorall = 0;
// 	    for(int i=1; i<=n; i++){
// 	        cin>>arr[i];
// 	    }
// 	    build(1, 1, n, arr, tree);
// 	    for(int i=1; i<=n; i++){
// 	        cout<<tree[i]<<" ";
// 	    }
// 	    for(int i=0; i<q; i++){
// 	        int l,r;
// 	        cin>>l>>r;
// 	        cout<<(query(1,1,n,l,r,arr,tree)^tree[1])<<endl;
// 	    }
// 	}
// 	return 0;
// }

/////////////
/////////////////////
///////////////////

//// https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0/?category[]=Trie&page=1&query=category[]Triepage1

#include <bits/stdc++.h>
using namespace std;
struct trie{
    struct trie* children[26];
    bool isleaf;
};

struct trie* getnode(){
    struct trie *newtrie = new trie();
    newtrie->isleaf=false;
    for(int i=0;i<26;i++){
        newtrie->children[i]=NULL;
    }
    return newtrie;
}

void insert(struct trie* root,string s){
    struct trie* temp=root;
    for(int i=0;i<s.size();i++){
        int index=s[i]-'a';
        if(!temp->children[index])
            temp->children[index]=getnode();
        temp=temp->children[index];
    }
    temp->isleaf=true;
}
bool search (struct trie* root,string key){
    struct trie* temp=root;
    for(int i=0;i<key.size();i++){
        int index=key[i]-'a';
        if(!temp->children[index])
            return false;
        temp=temp->children[index];
    }
    return (temp!=NULL && temp->isleaf);
}

int main()
{
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    struct trie *root=getnode();
    for(int i=0;i<n;i++){
        string key;
        cin>>key;
        insert(root,key);
    }
    string a;
    cin>>a;
    cout<<search(root,a)<<"\n";
}
}

////////////////
/////////////////










