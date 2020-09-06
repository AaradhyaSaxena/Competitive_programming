////// https://www.interviewbit.com/problems/stepping-numbers/

//// stepping number

/*
Given A and B you have to find all stepping numbers in range A to B.
The stepping number:
A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g. 123 is stepping number, but 358 is not a stepping number

*/
////////////////////////////////
////////////////////////////////
////////////////////////////////

void step(int A, int B, vector<int>& sol, long long int num){
    if(num > B){
        return;
    }
    
    int last = num%10;
    
    if(num >= A){
        sol.push_back(num);
    }
    
    if(last == 0){
        step(A, B, sol, num*10 + 1);
    }
    else if(last == 9){
        step(A, B, sol, num*10 + 8);
    }
    else{
        step(A, B, sol, num*10 + last - 1);
        step(A, B, sol, num*10 + last + 1);
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> sol;
    vector<int> a;
    vector<int> b;
    
    if(A > B){
        return sol;
    }
    
    if(A == 0){
        sol.push_back(0);
    }
    
    for(int i = 1; i < 10; i++){
        step(A, B, sol, (long long int)i);
    }
    
    if(sol.size() != 0){
        sort(sol.begin(), sol.end());
    }
    
    return sol;
}

////////////////////////////////
////////////////////////////////
////////////////////////////////


