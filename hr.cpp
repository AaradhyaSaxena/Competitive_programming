/////// hackerrank

// Good binary strings

/*
Special binary strings are binary strings with the following two properties:
The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.

Given a special string S, a move consists of choosing two consecutive, non-empty, 
special substrings of S, and swapping them. 
(Two strings are consecutive if the last character of the first string
is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible? 
*/

string largestMagical(string S) {
    int count = 0, i = 0;
    vector<string> res;
    for (int j = 0; j < S.size(); ++j) {
    	if (S[j] == '1') count++;
      	else count--;
      	if (count == 0) {
        	res.push_back('1' + largestMagical(S.substr(i + 1, j - i - 1)) + '0');
        	i = j + 1;
      	}
    }
    sort(res.begin(), res.end(), greater<string>());
    string res2 = "";
    for (int i = 0; i < res.size(); ++i) res2 += res[i];
    return res2;
}

//////////
///////////////////
/////////////////

///// Equal circle segments

/*
Given the radii of a number of circles and a number of segments to cut, 
determine the largest area of segments of equal area that can be cut. 
Return the value, rounded to 4 decimals and cast as a string.
*/

bool check(double &x ,vector<double> &A, int &K){
    int k = 0;
       for(auto a : A){
        k += a/x;
         if(k >= K) return true;
       }
       return false;
}

double maximum_serving_area(vector<int> v,int k){
    double l=0, m=0, x;
      vector<double> A;
      for(int i=0; i<v.size(); i++)  {
        x = (double)v[i]*3.14159265359*v[i];
        m = max(m,x);
        A.push_back(x);
      }
      while(m-l >= 1e-5){
        x = (l+m)/2;
        if(check(x,A,k)) l=x;
        else m=x;
      }
      return x;
}

string largestSegment(vector<int> radius, int segments) {
    double res = maximum_serving_area(radius, segments);
    string ans ="";
    stringstream stream;
    stream<<fixed<<setprecision(4)<<res;
    if(stream>>ans){
        return ans;
    }
    return " ";
}

///////////////////////