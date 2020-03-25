https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    
    int s = A.size();
    while(A[0]==0 && s>1){
        A.erase(A.begin());
    }
    s = A.size();
    int carry =1;
    int i=s-1;
    
    Cp:if(A[i] < 9){
        A[i] += carry;
        return A;
    }
    else if(A[i]==9 && carry==0){
        return A;
    }
    else{
        A[i] = 0;
        carry = 1;
        
        while(carry && i>0){
            i = i-1;
            A[i] += carry;
            carry = 0;
        }
        if(i==0 && carry==1){
            // if(A[i]>8){
            //     A.insert(A.begin(),0);
            // }
            A.insert(A.begin(),0);
            A[i] += carry;
            carry = 0;
            if(A[i+1]==10){
                A[i+1] = 0;
                A[i] = 1;
            }
        }
        goto Cp;
    }
}
//////////////////////////////////

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            reverse(digits.begin(), digits.end());
            vector<int> ans;
            int carry = 1;
            for (int i = 0; i < digits.size(); i++) {
                int sum = digits[i] + carry;
                ans.push_back(sum%10);
                carry = sum / 10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry /= 10;
            }
            while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
                ans.pop_back();
            }
            reverse(ans.begin(), ans.end());
            reverse(digits.begin(), digits.end());
            return ans;
        }
};

