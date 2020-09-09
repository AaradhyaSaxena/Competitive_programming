////https://www.interviewbit.com/problems/gray-code/

////// Gray code

vector<int> grayCode(int n) {

    vector<int> result(1, 0);        
    
    for (int i = 0; i < n; i++) {

        int curSize = result.size();

        // push back all element in result in reverse order
        for (int j = curSize - 1; j >= 0; j--) {
            result.push_back(result[j] + (1 << i));
        } 

    }
    
    return result;
}

///////