https://www.interviewbit.com/problems/painters-partition-problem/

bool isPossible(int max, int A, vector<int> &C){
    int sum =0, cnt =1;
    int _max = *max_element(C.begin(),C.end());
    if(max< _max){
        return false;
    }
    for(int i=0; i<C.size(); ){
        if(sum + C[i]> max){
            sum=0;
            cnt++;
        }
        else{
            sum += C[i];
            i++;
        }
    }
    if(cnt<=A){
        return true;
    }
    else{
        return false;
    }
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long int start =0, end =0;
    long long int ans = INT_MAX;
    // for(int i = 0; i < C.size(); ++i) {
    //     end += C[i];
    // }
    // ans *= INT_MAX;
    end = accumulate(C.begin(), C.end(),0);
    while(start<=end){
        long long int mid = (start+end)/2;
        if(isPossible(mid, A, C)){
            ans = min(mid,ans);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return (ans*B)%10000003;
}
