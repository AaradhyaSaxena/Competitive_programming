////////// greedy IB

///// https://www.interviewbit.com/problems/meeting-rooms/

///// Meeting Rooms

bool compare(vector<int> &a, vector<int> &b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int Solution::solve(vector<vector<int> > &A) {

    if(A.size() == 0) return 0;
    sort(A.begin(), A.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int l, r;
    pq.push(A[0][1]);
    
    for(int i=1;i<A.size();i++) {
        l = A[i][0];
        r = A[i][1];
        
        if(l >= pq.top()) {
            pq.pop();
        }
        pq.push(r);
    }
    return pq.size();
}

/////// incorrect my solution

// bool cmp(vector<int> A, vector<int> B){
//     if(A[1]==B[1]){
//         return A[0] < B[0];
//     }
//     return A[1] < B[1];
// }

// int Solution::solve(vector<vector<int> > &A) {
//     int n = A.size();
//     sort(A.begin(), A.end(), cmp);
//     int cnt = 1;
//     int ed = 0;
//     for(int i=1; i<n; i++){
//         if(A[i][0] < A[ed][1]){
//             cnt++;
//         }
//         else{
//             ed++;
//         }
//     }
//     return cnt;
// }

////////////////////

////// https://www.interviewbit.com/problems/distribute-candy/

///// Distribute Candy

int Solution::candy(vector<int> &A) {
    int n =A.size(), cnt =0;
    int right[n];
    int left[n];
    for(int i=0;i<n;i++){
        left[i] = 1;
        right[i] = 1;
    }
    
    for(int i=1; i<n; i++){
        if(A[i]>A[i-1]){
            right[i] = right[i-1]+1;
        }else{
            right[i] = 1;
        }
    }
    for(int i=n-2; i>=0; i--){
        if(A[i]>A[i+1]){
            left[i] = left[i+1]+1;
        }else{
            left[i] = 1;
        }
    }
    int total = 0;
    for(int i=0; i<n; i++){
        total = max(left[i], right[i]);
    }
    return total;
}

/////////////////

////////https://www.interviewbit.com/problems/seats/

//// seats in theatre

int Solution::seats(string A) {
    int n = A.length();
    vector<int> vec;
    for(int i=0; i<n; i++){
        if(A[i]=='x'){
            vec.push_back(i);
        }
    }
    int v = vec[vec.size()/2];
    int tot = 0;
    for(int i=0; i<vec.size(); i++){
        tot += (abs(v - A[vec[i]]) - abs( (int)vec.size()/2 - i))%10000003;
        cout<<tot<<" ";
        tot = tot%10000003;
    }
    return tot;
}

////////////////

///////https://www.interviewbit.com/problems/majority-element/

//// Majority element


int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        if(mp.find(A[i]) == mp.end()){
            mp[A[i]] = 1;
        }else{
            mp[A[i]]++;
        }
        if(mp[A[i]]>n/2){
            return A[i];
        }
    }
}

///////////////////////

int majorityElement(vector<int> &num) {
    int majorityIndex = 0;
    for (int count = 1, i = 1; i < num.size(); i++) {
        num[majorityIndex] == num[i] ? count++ : count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }

    return num[majorityIndex];
}

///////////////////////////

///////// https://www.interviewbit.com/problems/gas-station/

////// Gas station

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), sumA =0, sumB =0;
    for(int i=0; i<n; i++){
        sumA += A[i];
        sumB += B[i];
    }
    if(sumB>sumA) return -1;
    
    int fuel = 0;
    for(int i=0; i<n; i++){
        fuel = 0;
        for(int j=i; j<n; j++){
            if(fuel<0) break;
            fuel += (A[j]-B[j]);
        }
        if(fuel>=0){
            return i;
        }
    }
    return -1;
}


///////////////////////////////////

////////https://www.interviewbit.com/problems/disjoint-intervals/

//// DIsjoint intervals

int Solution::solve(vector<vector<int> > &a) {
    int m=a.size();
    if(m<=1)return m;
    int ans=1;
    sort(a.begin(),a.end());
    int maxi=a[0][1];
    
    for(int i=1;i<m;i++)
    {
        if(a[i][0]>maxi)
        {
            ans++;
            maxi=a[i][1];
        }
        else 
        {
            maxi=min(maxi,a[i][1]);
        }
    }
    return ans;
}

/////////////////

//////// https://www.interviewbit.com/problems/largest-permutation/

/// Largest permutation

vector<int> Solution::solve(vector<int> &A, int B) {
    int j=0;
    int n = A.size();
    vector<int> m(n+1, 0);
    for(int i=0;i<n;i++){ 
        m[A[i]] = i; 
    }
    
    for(int i=0; j<B && i<A.size(); i++){
        if( n-i == A[i] ){
            continue;
        }
        int idx = m[n-i];
        
        swap(A[i], A[idx]);
        m[n-i] = i;
        m[A[idx]] = idx;
        j++;
    }
    return A;
}

///////////////

///////////////////////

/*
If you make a choice that seems the best at the moment and solve the remaining sub-problems later, 
you still reach an optimal solution. You will never have to reconsider your earlier choices.

You implement sorting, see what are the different ways in which you could implement sorting.

think of mean, median ??? sum, diff??? normal patterns.


*/






