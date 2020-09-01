//////////////////////////////

/// valid BST

int check(TreeNode* A, int minn, int maxx){
    if(A==NULL) return 1;
    if(A->val < minn or A->val > maxx) return 0;
    return check(A->left, minn, A->val-1) and check(A->right, A->val+1, maxx);
} 
 
int Solution::isValidBST(TreeNode* A) {
    if(A==NULL) return 1;
    int minn = INT_MIN, maxx = INT_MAX;
    return check(A, minn, maxx);
}

/////////////////////////////

/// Next greater number BST

TreeNode* find(TreeNode *A, int B){
    while(A!=NULL and A->val != B){
        if(A->val<B){
            A = A->right;
        }else{
            A = A->left;
        }
    }
    if(A!=NULL and A->val==B) return A;
    return NULL;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode *node = find(A,B);
    if(node==NULL) return NULL;
    if(node->right != NULL){
        node = node->right;
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }else{
        TreeNode *prev = A, *next = NULL;
        while(prev != node){
            if(prev->val>B){
                next = prev;
                prev = prev->left;
            }else{
                prev = prev->right;
            }
        }
        return next;
    }
    return NULL;
}

//////////////////////////

/// kth smallest element in tree

int helper(TreeNode *node, int k, int &level){
    if (!node) return -1;
    if(node->left != NULL){
        int res = helper(node->left,k,level);
        if(k==level){
            return res;
        }
    }
    level++;
    if(k==level){
        return node->val;
    }
    if(node->right != NULL){
        int res = helper(node->right,k,level);
        if(k==level){
            return res;
        }
    }
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int level = 0;
    return helper(A,B,level);
}

/////////////////////////////

/// 2-Sum Binary Tree

void recurse(TreeNode* cur, vector<int>& num) {
    if(cur == NULL) {
        return;
    }
    recurse(cur->left, num);
    num.push_back(cur->val);
    recurse(cur->right, num);
    delete cur;
}
 
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> num;
    recurse(A, num);
    int low=0, high=num.size()-1;
    while(low < high) {
        if(num[low]+num[high] > B) {
            high--;
        } else if(num[low] + num[high] < B) {
            low++;
        } else {
            return 1;
        }
    }
    return 0;
}

///

bool Twosum( TreeNode* A,int B,unordered_map<int,int> &ump ){
    if(A==NULL) return false;
    if(ump.find(B-A->val)!=ump.end() ) {return true; }
    else { 
        ump[A->val]++;
        return (Twosum(A->left,B,ump) ||Twosum(A->right,B,ump) );  
    }
    
}
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_map<int,int> ump;
    bool ans = Twosum(A,B,ump);
    
    if(ans) return 1;
    return 0;
    
}

///////////////////////

/// BST Iterator 

stack<TreeNode *> mystack;

void addNode(TreeNode *root){
    while(root!=NULL){
        mystack.push(root);
        root = root->left;
    }
}

BSTIterator::BSTIterator(TreeNode *root) {
    addNode(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(!mystack.empty()) return 1;
    return 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *tempNode = mystack.top();
    mystack.pop();
    addNode(tempNode->right);
    return tempNode->val;
}

//////////////////////

////// Morris Traversal (when limited space is provided)

struct tNode { 
    int data; 
    struct tNode* left; 
    struct tNode* right; 
}; 
  
/* Function to traverse the binary tree without recursion and without stack */
void MorrisTraversal(struct tNode* root) { 
    struct tNode *current, *pre; 
  
    if (root == NULL) 
        return; 
  
    current = root; 
    while (current != NULL) { 
  
        if (current->left == NULL) { 
            printf("%d ", current->data); 
            current = current->right; 
        } 
        else { 
  
            /* Find the inorder predecessor of current */
            pre = current->left; 
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            /* Make current as the right child of its inorder predecessor */
            if (pre->right == NULL) { 
                pre->right = current; 
                current = current->left; 
            } 
  
            // Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor 
            else { 
                pre->right = NULL; 
                printf("%d ", current->data); 
                current = current->right; 
            } // End of if condition pre->right == NULL 
        }  // End of if condition current->left == NULL
    }  // End of while 
} 
  
/* Helper function that allocates a new tNode with the given data and NULL left and right pointers. */
struct tNode* newtNode(int data) 
{ 
    struct tNode* node = new tNode; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
int main(){ 
  
    /* Constructed binary tree is 
            1 
          /   \ 
         2     3 
       /   \ 
      4     5 
  */
    struct tNode* root = newtNode(1); 
    root->left = newtNode(2); 
    root->right = newtNode(3); 
    root->left->left = newtNode(4); 
    root->left->right = newtNode(5); 
  
    MorrisTraversal(root); 
  
    return 0; 
} 
//////////////////////////////
/// recover binary search tree

void helper(TreeNode *root, TreeNode* &prev, TreeNode* &first, TreeNode* &second){
    if(root==NULL) return;
    
    helper(root->left, prev, first, second);
    
    if(prev != NULL and prev->val > root->val){
        if(first==NULL){
            first = prev;
        }second = root;
    }
    prev = root;
    
    helper(root->right, prev,first,second);
} 

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> vec;
    
    TreeNode *prev =NULL, *first = NULL, *second = NULL;
    helper(A, prev, first, second);
    
    vec.push_back(second->val);
    vec.push_back(first->val);
    return vec;
}

/////////////////////////////////////

//// Tree Traversal Recursive

void preorder_traversal(TreeNode *node){
    if(node==NULL) return;
    vec.push_back(node->val);
    helper(node->left);
    helper(node->right);
}

void inorder_traversal(TreeNode *node){
    if(node==NULL) return;
    helper(node->left);
    vec.push_back(node->val);
    helper(node->right);
}

void postorder_traversal(TreeNode *node){
    if(node==NULL) return;
    helper(node->left);
    helper(node->right);
    vec.push_back(node->val);
}

vector<int> Tree_Traversal(TreeNode* A) {
    vec.clear();
    XXX_traversal(A);
    return vec;
}

/////////////////////////

vector<int> inorder_traversal(TreeNode* A) {
    vector<vector<int>> ans;
    vector<int> vec;
    queue<TreeNode *> qt;
    qt.push(A);
    qt.push(NULL);
    while(!qt.empty()){
        TreeNode *curr = qt.front();
        qt.pop();
        if(curr) vec.push_back(curr->val);
        
        if(curr==NULL){
            ans.push_back(vec);
            vec.clear();
            if(!qt.empty()){
                qt.push(NULL);
            }
        }
        else{
            if(curr->left) qt.push(curr->left);
            if(curr->right) qt.push(curr->right);
        }
    }
    // for(int i=1; i<ans.size(); i=i+2){
    //     reverse(ans[i].begin(),ans[i].end());
    // }
    return ans;
}

/////////////////////////































































////////////////////////

/*
If you are allowed extra memory the cheap way to deal with trees is to store it in vector and then operate.

Traversal -- Mostly about stacking all left children and when encounetered NULL, move to the right.


*/



































































































































