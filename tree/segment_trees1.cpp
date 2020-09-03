/////////// SEGMENT TREES

#include <bits/stdc++.h>
using namespace std;

int tree[100001];
int A[100001];

void build(int node, int start, int end){
    if(start == end){
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else{
        int mid = (start + end) / 2;
        
        build(2*node, start, mid);   // Recurse on the left child
        build(2*node+1, mid+1, end);  // Recurse on the right child

        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end){
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid){

            update(2*node, start, mid, idx, val);  // If idx is in the left child, recurse on the left child
        }
        else{
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){

    if(r < start or end < l){
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r){
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1,p2);
}

int main(){
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++){
		cin>>A[i];
	}

	build(1, 1, n);

	char t; int l,r;
	for(int i=0; i<q; i++){
		cin>>t>>l>>r;
		if(t=='q'){
			cout<<query(1,1,n,l,r)<<endl;
		}
		if(t=='u'){
			update(1,1,n,l,r);
		}
	}
	return 0;
}


//////////////////////////////////

//// https://practice.geeksforgeeks.org/problems/xor-of-a-given-range/1

///// find xor in a given range

#include <bits/stdc++.h> 
   
// A utility function to get the middle index from corner indexes. 
int getMid(int s, int e) 
{
	return s + (e - s)/2;  
} 
/*  
    st    --> Pointer to segment tree 
    si    --> Index of current node in the segment tree. Initially 0 is passed as root is always at index 0 
    ss & se  --> Starting and ending indexes of the segment represented by current node, i.e., st[si] 
    qs & qe  --> Starting and ending indexes of query range 
*/
int getXorUtil(int *st, int ss, int se, int qs, int qe, int si) 
{ 
    // If segment of this node is a part of given range, then return the xor of the segment 
    if (qs <= ss && qe >= se) 
        return st[si]; 
   
    // If segment of this node is outside the given range 
    if (se < qs || ss > qe) 
        return 0; 
   
    // If a part of this segment overlaps with the given range 
    int mid = getMid(ss, se); 
    return getXorUtil(st, ss, mid, qs, qe, 2*si+1) ^ getXorUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 
   
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) 
{ 
    // Base Case: If the input index lies outside the range of this segment 
    if (i < ss || i > se) 
        return; 
   
    // If the input index is in range of this node, then update the value of the node and its children 
    st[si] = st[si] + diff; 
    if (se != ss) 
    { 
        int mid = getMid(ss, se); 
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
    } 
} 
   
// To update a value in input array and segment tree. It uses updateValueUtil(). 
void updateValue(int arr[], int *st, int n, int i, int new_val) 
{ 
    // Check for erroneous input index 
    if (i < 0 || i > n-1) 
    { 
        printf("Invalid Input"); 
        return; 
    } 
   
    // Get the difference between new value and old value 
    int diff = new_val - arr[i]; 
   
    // Update the value in array 
    arr[i] = new_val; 
   
    // Update the values of nodes in segment tree 
    updateValueUtil(st, 0, n-1, i, diff, 0); 
} 
   
// Return xor of elements in range from index qs (quey start) to qe (query end), uses getXorUtil() 
int getXor(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
   
    return getXorUtil(st, 0, n-1, qs, qe, 0); 
} 
   
// A recursive function that constructs Segment Tree for array[ss..se]. si is index of current node in segment tree st 
int constructSTUtil(int arr[], int ss, int se, int *st, int si) 
{ 
    // If there is one element in array, store it in current node of segment tree and return 
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
   
    // If there are more than one elements, then recur for left and 
    // right subtrees and store the xor of values in this node 
    int mid = getMid(ss, se); 
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) ^ 
              constructSTUtil(arr, mid+1, se, st, si*2+2); 
    return st[si]; 
} 
   
/* Function to construct segment tree from given array. This function 
   allocates memory for segment tree and calls constructSTUtil() to 
   fill the allocated memory */
int *constructST(int arr[], int n) 
{ 
    //Height of segment tree 
    int x = (int)(ceil(log2(n)));  
   
    //Maximum size of segment tree 
    int max_size = 2*(int)pow(2, x) - 1;  
   
    // Allocate memory 
    int *st =  (int *)malloc(sizeof(int)*max_size); 
   
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, st, 0); 
   
    // Return the constructed segment tree 
    return st; 
} 
   
// Driver program to test above functions 
int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		int n,a,b;
		cin>>n>>a>>b;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int *st = constructST(arr, n); 
		cout<<getXor(st, n, a,b)<<endl;
		// updateValue(arr, st, n, 1, 10);
	}
    return 0; 
} 


////////////////////////////////////////
////////////////////////////////////////
/// https://www.interviewbit.com/problems/order-of-people-heights/

////// order of people heights

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) 
{
    vector<int> v(heights.size(), -1);
    map<int, int> mp;
    
    for(auto i=0; i<heights.size(); i++){
        mp[heights[i]] = infronts[i];
    }
    for(auto it : mp){
        int i = 0, j = 0;
        while(i != it.second){
            if(v[j] == -1)
                i++;
            j++;
        }
        while(v[j] != -1){
            j++;
        }
        v[j] = it.first;
    }
    
    return v;
}

//// aliter

int empty_pos(vector<int> &tree, int pos) {
    int n = tree.size()/2, i = 0;
    while (i < n-1) {
        --tree[i];
        if (tree[2*i+1] > pos) i = 2*i+1;
        else {
            pos -= tree[2*i+1];
            i = 2*i+2;
        }
    }
    --tree[i];
    return i-(n-1);
}

vector<int> build_segment_tree(int len) {
    int n = pow(2, ceil(log2(len)));
    vector<int> tree(2*n);
    for (int i = 0; i <= len-1; ++i) 
    	tree[n-1+i] = 1;
    for (int i = n-2; i >= 0; --i) 
    	tree[i] = tree[2*i+1] + tree[2*i+2];
    return tree;
}

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) 
    	cout << v[i] << " ";
    cout << endl;
}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    vector<int> perm(heights.size());
    for (int i = 0; i < perm.size(); ++i)
    	perm[i] = i;

    sort(perm.begin(), perm.end(), [&](const int& a, const int& b) { return (heights[a] < heights[b]); });

    vector<int> tree = build_segment_tree(heights.size());

    vector<int> res(heights.size(), -1);
    for (int i = 0; i < perm.size(); ++i) 
    	res[empty_pos(tree, infronts[perm[i]])] = heights[perm[i]];

    return res;
}







