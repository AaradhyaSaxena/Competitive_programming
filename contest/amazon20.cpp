//// Amazon 2020

///// merge two sorted lists

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    Node *head = new Node(0);
    Node *ans = head;
    while(head_A != NULL and head_B != NULL){
        if(head_A->data < head_B->data){
            head->next = head_A;
            head = head->next;
            head_A = head_A->next;
        }
        else{
            head->next = head_B;
            head = head->next;
            head_B = head_B->next;
        }
    }
    if(head_A==NULL){
        head->next = head_B;
    }
    else{
        head->next = head_A;
    }
    return ans->next;
}  

////////////////////

////// Favorite Genre

unordered_map<string,vector<string>> songsAndGenre(unordered_map<string,vector<string>>& users, 
													unordered_map<string,vector<string>>& genres){
    unordered_map<string,string> songToGenre;
    unordered_map<string,unordered_map<string,int>> userToGenre;
    unordered_map<string,vector<string>> result;
    unordered_map<string,int> max;
    for(auto genre:genres)
    {
        for(auto song: genre.second)
        {
            songToGenre[song] = genre.first;
        }
    }
    
    for(auto user:users)
    {
        for(auto item:user.second)
        {
            userToGenre[user.first][songToGenre[item]]++;
            auto tempMax = userToGenre.at(user.first).at(songToGenre[item]);
            max[user.first] = std::max(tempMax,max[user.first]);
        }
    }
    
    for(auto user:userToGenre)
    {
        for(auto genre:user.second)
        {
            if(genre.second==max.at(user.first))
            {
                result[user.first].push_back(genre.first);
            }
        }
    }
    
    return result;
}

int main() {
    unordered_map<string,vector<string>> users;
    users["David"] = {"song1", "song2", "song3", "song4", "song8"};
    users["Emma"] = {"song5", "song6", "song7"};
    
    unordered_map<string,vector<string>> songs;
    songs["Rock"] = {"song1", "song3"};
    songs["Dubstep"] = {"song7"};
    songs["Techno"] = {"song2", "song4"};
    songs["Pop"] = {"song5", "song6"};
    songs["Jazz"] = {"song8", "song9"};

    auto result = songsAndGenre(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }
    
    users.clear();
    songs.clear();
    
    users["David"] = {"song1", "song2"};
    users["Emma"] = {"song3", "song4"};
    
    result = songsAndGenre(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }
}

///////////
//////////////////

//// Clone pointer

unordered_map<RandomListNode*, RandomListNode*> hmap;

RandomListNode *copyRandomList(RandomListNode *head) {
	if (!head) return NULL;

	if (hmap.find(head) != hmap.end())
		return hmap.find(head)->second;

	RandomListNode* node = new RandomListNode(head->label);
	hmap[head] = node;
	node->next = copyRandomList(head->next);
	node->random = copyRandomList(head->random);
	return node;
}

/////////////////////////////
/////////////////////////////////////
////// check if A is subtree of B

#include<bits/stdc++.h> 
using namespace std; 
  
class node {  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  
bool areIdentical(node * root1, node *root2)  
{  
    if (root1 == NULL && root2 == NULL)  
        return true;  
  
    if (root1 == NULL || root2 == NULL)  
        return false;  
  
    return (root1->data == root2->data &&  
            areIdentical(root1->left, root2->left) &&  
            areIdentical(root1->right, root2->right) );  
}  
  
  
/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(node *T, node *S){  
    if (S == NULL) return true;  
    if (T == NULL) return false;  
  
    if (areIdentical(T, S)) return true;  
    return isSubtree(T->left, S) || isSubtree(T->right, S);  
}  
  
  
// Helper function that allocates a new node with the given data  
// and NULL left and right pointers. 
node* newNode(int data){  
    node* Node = new node();  
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
    return(Node);  
}  
  
int main()  
{  
    // TREE 1  
    /* Construct the following tree  
            26  
            / \  
           10 3  
    	    / \ \  
    		4 6 3  
   			 \  
    	    30  
    */
    node *T = newNode(26);  
    T->right         = newNode(3);  
    T->right->right = newNode(3);  
    T->left         = newNode(10);  
    T->left->left     = newNode(4);  
    T->left->left->right = newNode(30);  
    T->left->right     = newNode(6);  
  
    // TREE 2  
    /* Construct the following tree  
        10  
        / \  
    	4 6  
    	\  
        30  
    */
    node *S = newNode(10);  
    S->right     = newNode(6);  
    S->left     = newNode(4);  
    S->left->right = newNode(30);  
  
  
    if (isSubtree(T, S))  
        cout << "Tree 2 is subtree of Tree 1";  
    else
        cout << "Tree 2 is not a subtree of Tree 1";  
  
    return 0;  
}  
///////
//////////////







