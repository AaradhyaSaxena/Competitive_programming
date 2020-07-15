https://www.interviewbit.com/problems/maximum-consecutive-gap/

// int Solution::maximumGap(const vector<int> &A) {
    
//     vector<int> B;
//     B = A;
//     sort(B.begin(), B.end());
    
//     for(int i=(B.size()-1); i>0; i--){
//         B[i] = B[i] - B[i-1];
//     }
//     B[0] = 0;
    
//     return *max_element(B.begin(), B.end());
// }

///////////////////////////////////////////

int Solution::maximumGap(const vector<int> &num) {
    if(num.empty() || num.size() < 2)
        return 0;
    int maxNum = *max_element(num.begin(), num.end());
    int minNum = *min_element(num.begin(), num.end());
    //average gap from minNum to maxNum.
    int gap = (maxNum - minNum - 1) / (num.size() - 1) + 1;

    //number of buckets = num.size() - 1
    vector<int> bucketsMin(num.size() - 1, INT_MAX);
    vector<int> bucketsMax(num.size() - 1, INT_MIN);
    //put into buckets
    for (int i = 0; i < num.size(); i++) {
        if (num[i] != maxNum && num[i] != minNum)
        {
            int buckInd = (num[i] - minNum) / gap;
            bucketsMin[buckInd] = min(bucketsMin[buckInd], num[i]);
            bucketsMax[buckInd] = max(bucketsMax[buckInd], num[i]);
        }
    }
    int maxGap = INT_MIN;
    int previous = minNum;
    for (int i = 0; i < num.size() - 1; i++) {
        if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN)
            continue;   //empty
        //i_th gap is minvalue in i+1_th bucket minus maxvalue in i_th bucket 
        maxGap = max(maxGap, bucketsMin[i] - previous);
        previous = bucketsMax[i];
    }
    maxGap = max(maxGap, maxNum - previous);
    return maxGap;
}    
////////////////////////////////////////////////////////////////////////