//////https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

//// Max Rectangle in Binary matrix

int histogram(vector<int> &nums){
    stack<int> s;
    int res = 0, i = 0, n = nums.size();
    
    while(i < n){
        if(s.empty() || nums[s.top()] <= nums[i])
            s.push(i++);
        else{
            int top = s.top();
            s.pop();
            int d = s.empty() ? i : i - s.top() - 1;
            res = max(res, nums[top] * d);
        }
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        int d = s.empty() ? i : i - s.top() - 1;
        res = max(res, nums[top] * d);
    }
    return res;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int res = 0;
    
    res = histogram(A[0]);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++)
            A[i][j] = A[i][j] == 0 ? 0 : 1 + A[i - 1][j];
        res = max(res, histogram(A[i]));
    }
    return res;
}

/*

We begin by creating histogram >>> add sum vertically, to store vertical pattern

Once the histogram is formed, solve for max area under histogram.

Approach for solving max area under histogram >>

	Assume every element to be the smallest, and calculate the area of larger neighbors.
	try using stack;

*/