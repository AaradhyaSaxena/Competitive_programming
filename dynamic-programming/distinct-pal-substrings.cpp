///////https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings/0

/// distinct palindrome substrings

#include<bits/stdc++.h>
using namespace std;


void findPallinUptoI(int i, int j, unordered_set<string> &st, string str, int n)
{
    while(i>=0 && j<n && str[i]==str[j])
    {
        st.insert(str.substr(i,j-i+1));
        i--;
        j++;
    }
    
}

int solution(string str)
{
    unordered_set<string> st;
    int n=str.length();
    
    for(int i=0;i<n;i++)
    {
        findPallinUptoI(i,i,st,str,n);
        findPallinUptoI(i,i+1,st,str,n);
    }
    
    return st.size();
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        
        cout<<solution(str)<<endl;
    }
    return 0;
}

////////////




