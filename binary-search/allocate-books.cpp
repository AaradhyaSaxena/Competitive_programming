/////// https://www.interviewbit.com/problems/allocate-books/

//// Allocate books

bool isPossible(vector<int> &A, int pages, int B){
    int cnt = 1, sum = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i]>pages) return false;
        if(sum + A[i] > pages){
            cnt++;
            sum =0;
        }
        sum += A[i];
    }
    // return cnt;
    if(cnt<=B){
        return true;
    }
    return false;
}

int Solution::books(vector<int> &A, int B){
    if(B>A.size()) return -1;
    int sum = 0, temp =0;
    for(int i=0; i<A.size(); i++){
        sum += A[i];
    }
    int start = 0, end = sum, ans = 0;
    
    while(start<=end){
        int mid = start + (end - start)/2;
        if(isPossible(A,mid,B)){
            ans = mid;
            // cout<<ans<<endl;
            end = mid-1;
        }
        else{
            start = mid +1;
        }
    }
    return ans;
}



///////