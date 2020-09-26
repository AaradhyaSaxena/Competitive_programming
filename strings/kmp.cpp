///////// KMP

vector<int> prefix_function (string s) {

    int n = (int) s.length();
    vector<int> pi(n);
    pi[0]=0;

    for (int i=1; i<n; ++i){
        int l = pi[i-1];

        // if s[i] != s[l] then, reduce l one at a time.
        while (l > 0 && s[i] != s[l])
            l = pi[l-1];

        // if ith character matches, character at s[l]
        if (s[i] == s[l])  ++l; // (biggest suffix possible)   
        pi[i] = l;
    }
    return pi;
}


/////////////
/// https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/tutorial/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string pat, text;
    cin>>pat>>text;
    string s = pat + "#" + text;
    int n = s.length(), m = pat.length();
    int cnt =0;
    int arr[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = 0;
    }
    int l = 0;
    for(int i=1; i<n; i++){
        l = arr[i-1];
        while(l>0 and s[i] != s[l]){
            l = arr[l-1];
        }
        if(s[i]==s[l]){
            ++l;
        }
        arr[i] = l;
    }
    for(int i=0; i<n; i++){
        if(arr[i]==m) cnt++;
    }
    cout<<cnt<<endl;
}

///////////////////////

/*

/// Compressing a string

Given a string s of length n. We want to find the shortest "compressed" representation of the string, 
i.e. we want to find a string t of smallest length such that s can be represented as a concatenation of one or more copies of t.

It is clear, that we only need to find the length of t. 
Knowing the length, the answer to the problem will be the prefix of s with this length.

Let us compute the prefix function for s. 
Using the last value of it we define the value

 k=n−π[n−1]. 

We will show, that if k divides n, then k will be the answer, 
otherwise there doesn't exists an effective compression and the answer is n.

*/

///////////////////////

/*

///// The number of different substring in a string

Given a string s of length n. We want to compute the number of different substrings appearing in it.

We will solve this problem iteratively. 
Namely we will learn, knowing the current number of different substrings, 
how to recompute this count by adding a character to the end.

So let k be the current number of different substrings in s, 
and we add the character c to the end of s. Obviously some new substrings ending in c will appear. 
We want to count these new substrings that didn't appear before.

We take the string t=s+c and reverse it. 
Now the task is transformed into computing how many prefixes there are that don't appear anywhere else. 
If we compute the maximal value of the prefix function πmax of the reversed string t, 
then the longest prefix that appears in s is π(max) long. 
Clearly also all prefixes of smaller length appear in it.

Therefore the number of new substrings appearing when we add a new character c
is |s|+1−π(max).

*/


//////////////////////





/////////////////////

/////////////////////