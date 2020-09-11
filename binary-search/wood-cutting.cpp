////// https://www.interviewbit.com/problems/woodcutting-made-easy/

//// Wood cutting

typedef long long int ll;

int Solution::solve(vector<int> &A, int B) {
    ll i = 0, len = A.size(), wood_collected = 0;
    ll max_height = *max_element(A.begin(), A.end());
    
    vector<ll> dp_heights(max_height + 2, 0);
    
    for (i=0; i<len; i++)
        dp_heights[A[i]]++;     // Saves total wood at a particular level
    
    for (i=max_height; i >= 0 && wood_collected < B; i--){
        dp_heights[i] += dp_heights[i+1];
        // Computes the total wood, from the trees above at this level.
        wood_collected += dp_heights[i];
        // Calculate suffix sum of wood, to get the answer of total woods collected if we cut at this level.
    }
    return i; 
    // Note: Since the forloop does a i--, so we can simply return i hera. 
}

//////////////////

//// slower

int totWood(vector<int> &A, int B){
    long long int cnt = 0;
    for(long long int i=0; i<A.size(); i++){
        if(A[i]>B){
            cnt += abs(A[i]-B);
        }
    }
    return cnt;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), maxx = INT_MIN;
    for(int i=0; i<n; i++){
        maxx = max(maxx, A[i]);
    }
    long long int start = 0, end = maxx, ans = 0;
    // cout<<end<<endl;
    while(start<=end){
        long long int mid = start + (end-start)/2;
        // cout<<"mid "<<mid<<endl;
        if(totWood(A,mid)>=B){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

/////