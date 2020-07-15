https://www.interviewbit.com/problems/fizzbuzz/

vector<string> Solution::fizzBuzz(int A) {
    vector<string> ans;
    
    for(int i=1; i<=A; i++){
        string str = "";
        if(i%3 != 0 and i%5 != 0){
            str += i;
        }
        else if(i%3 == 0 and i%5 != 0){
            str += "Fizz";
        }
        else if(i%5 == 0 and i%3 != 0){
            str += "Buzz";
        }
        else{
            str += "FizzBuzz";
        }
        ans.push_back(str);
    }
    return ans;
}
