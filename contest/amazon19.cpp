////////////////////
///// amazon19
/////////////////////


/////////// Alien dictionary

vector<vector<int>> adj(26);
vector<bool> vis(26);
stack<int> st;

void dfs(int s){
	vis[s] = true;

	for(int i=0; i<adj[s].size(); i++){
		if(vis[adj[s][i]]==0){
			dfs(adj[s][i]);
		}		
	}
	st.push(s);
}

string findOrder(string dict[], int N, int K) {

    for(int i=0; i<26; i++){
    	adj[i].clear();
    	vis[i] = false;
    }
    // st.clear();

    for(int i=0; i<N-1; i++){
        string s1 = dict[i], s2 = dict[i+1];
        int len1 = dict[i].length(), len2 = dict[i+1].length();
        for(int j=0; j<min(len1,len2); j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        } 
    }

    for(int i=0; i<26; i++){
    	for(int j =0; j< adj[i].size(); j++){
    		if(vis[adj[i][j]]==false){
    			dfs(adj[i][j]);
    		}
    	}
    }
    
    string res;
    while(st.empty() == false){
        res += st.top() + 'a';
        st.pop();
    }
    if(res.length()>K){
        res = res.substr(0,K);
    }
    
    return res;
}

///////////// dice throw

#include <iostream> 
#include <string.h> 
using namespace std; 
  
//  sum 'x' with 'n' dice and with m faces. 
int findWays(int m, int n, int x) 
{ 
    int table[n + 1][x + 1]; 
    memset(table, 0, sizeof(table)); 
  
    // Table entries for only one dice 
    for (int j = 1; j <= m && j <= x; j++) 
        table[1][j] = 1; 
  
    for (int i = 2; i <= n; i++) 
        for (int j = 1; j <= x; j++) 
            for (int k = 1; k <= m && k < j; k++) 
                table[i][j] += table[i-1][j-k]; 

    return table[n][x]; 
} 
  
int main(){ 
    cout << findWays(4, 2, 1) << endl; 
    cout << findWays(2, 2, 3) << endl; 
    return 0; 
} 

//// optimized

#include<bits/stdc++.h> 
using namespace std; 
  
long findWays(int f, int d, int s) 
{ 
    long mem[d + 1][s + 1]; 
    memset(mem,0,sizeof mem); 
    
    mem[0][0] = 1;

    for (int i = 1; i <= d; i++) // Iterate over dices 
    { 
        for (int j = i; j <= s; j++) // Iterate over sum 
        { 
            mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1]; 
            if (j - f - 1 >= 0) 
                mem[i][j] -= mem[i - 1][j - f - 1]; 
        } 
    } 
    return mem[d][s]; 
} 
  
int main() 
{ 
    cout << findWays(4, 2, 1) << endl; 
    cout << findWays(2, 2, 3) << endl; 
    return 0; 
} 

/////////// postfix eval

int operation(int l, int r, string str, int i){
    if(str[i] =='*') return l*r;
    else if(str[i]=='/') return l/r;
    else if(str[i]=='+') return l+r;
    else if(str[i]=='-') return l-r;
    else return -1;
}

int evaluatePostfix(string &str)
{
    stack<int> st;
    int n = str.length();
    
    for(int i=0; i<n ;i++){
        if(str[i]<='9' and str[i]>='0'){
            st.push(str[i]-'0');
        }
        else{
            int r = st.top(); st.pop();
            int l = st.top(); st.pop();
            st.push(operation(l,r, str,i));
        }
    }
    return st.top();
}

///////////////////////////////
/////////////////////////////



/////////// infix to postfix

#include<bits/stdc++.h> 
using namespace std; 
  
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
  
void infixToPostfix(string s) 
{ 
    std::stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string ns; 
    for(int i = 0; i < l; i++) 
    { 
          
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) 
        	ns+=s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
        	st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               ns += c; 
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        }  
        //If an operator is scanned 
        else{ 
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
    } 
    // Pop all the remaining elements from the stack 
    while(st.top() != 'N'){ 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    } 
    cout << ns << endl; 
} 
  
int main(){ 
    string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp); 
    return 0; 
} 

//////////////////////////////
///////////////////////////////

/////////// string parsing

#include<stdio.h>
const int MAX = 1000;
 
nt replaceSpaces(char str[])
{
    // count spaces and find current length
    int space_count = 0, i;
    for (i = 0; str[i]; i++)
        if (str[i] == ' ')
            space_count++;
 
    // Remove trailing spaces
    while (str[i-1] == ' ')
    {
       space_count--;
       i--;
    }
 
    // Find new length.
    int new_length = i + space_count * 2 + 1;
 
    // New length must be smaller than length of string provided.
    if (new_length > MAX)
        return -1;
 
    // Start filling character from end
    int index = new_length - 1;
 
    // Fill string termination.
    str[index--] = '\0';
 
    // Fill rest of the string from end
    for (int j=i-1; j>=0; j--)
    {
        // inserts %20 in place of space
        if (str[j] == ' ')
        {
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index = index - 3;
        }
        else
        {
            str[index] = str[j];
            index--;
        }
    }
 
    return new_length;
}
 
int main()
{
    char str[MAX] = "Mr John Smith   ";
    int new_length = replaceSpaces(str);
    for (int i=0; i<new_length; i++)
        printf("%c", str[i]);
    return 0;
}

/////////////////// distinct char

#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX_CHARS = 256; 
  
string findSubString(string str) 
{ 
    int n = str.length(); 
  
    int dist_count = 0; 
    bool visited[MAX_CHARS] = { false }; 
    for (int i = 0; i < n; i++) { 
        if (visited[str[i]] == false) { 
            visited[str[i]] = true; 
            dist_count++; 
        } 
    } 
  
    int start = 0, start_index = -1, min_len = INT_MAX; 
    int count = 0; 
    int curr_count[MAX_CHARS] = { 0 }; 
    for (int j = 0; j < n; j++) { 
        
        curr_count[str[j]]++; // Count occurrence of characters of string 
        
        if (curr_count[str[j]] == 1) 
            count++; // If any distinct character matched, then increment count 

        if (count == dist_count) { // if all the characters are matched 
            while (curr_count[str[start]] > 1) { 
                if (curr_count[str[start]] > 1) 
                    curr_count[str[start]]--; 
                start++; 
            } 
  
            int len_window = j - start + 1; 
            if (min_len > len_window) { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
    return str.substr(start_index, min_len); 
} 
  
int main() 
{ 
    string str = "aabcbcdbca"; 
    cout << "Smallest window containing all distinct characters is: " << findSubString(str); 
    return 0; 
} 

////////// count possible decoding

#include <iostream> 
#include <cstring> 
using namespace std; 
  
int countDecodingDP(char *digits, int n) 
{ 
    int count[n+1];  
    count[0] = 1; count[1] = 1; 

    //for base condition "01123" should return 0  
    if(digits[0]=='0') return 0; 
    
    for (int i = 2; i <= n; i++){ 
        count[i] = 0; 
        
        if (digits[i-1] > '0'){  // If the last digit is not 0, 
            count[i] = count[i-1];  // then last digit must add to the number of words 
        }
        // If second last digit is smaller than 2 and last digit is smaller than 7, 
        // then last two digits form a valid character  
        if (digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7')) {
            count[i] += count[i-2]; 
        }
    } 
    return count[n]; 
} 
  
int main() 
{ 
    char digits[] = "1234"; 
    int n = strlen(digits); 
    cout << countDecodingDP(digits, n); 
    return 0; 
} 

//////////////

////// right view tree

map<int,int>m;

void helper(TreeNode *A, int d){
    if(A==NULL) return;
    if(m.find(d)==m.end()) 
        m[d]=A->val;
   	helper(A->right,d+1);
   	helper(A->left,d+1);
}

vector<int> Solution::solve(TreeNode* A) {
    m.clear();
    helper(A,0);
    vector<int>v;
    for(auto i=m.begin();i!=m.end();i++) 
        v.push_back(i->second);
    return v;
}

////////////// longest pal suseq

int Solution::solve(string A) {
    string B;
    int n=A.length();
    for(int i=A.length()-1;i>=0;i--) 
    	B.push_back(A[i]);

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1]) 
            	dp[i][j] = dp[i-1][j-1]+1;
            else 
            	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}

///////////////

///// count derrangement

#include <bits/stdc++.h>
using namespace std;
 
int countDer(int n)
{
  // Base cases
  if (n == 1) return 0;
  if (n == 2) return 1;
 
  // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
  return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}
 
// Driver Code
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}

///////////// internet address

#include <iostream>
using namespace std;
     
string ans, s;
int index;
     
int main()
{
	cin >> s;
	if (s[0] == 'h'){
		ans += "http://";
		index = 4;
	}
	else{
		ans += "ftp://";
		index = 3;
	}
	for (int i = (int)s.size()-3 ; i >= index ; i--)
		if (s[i] == 'r' && s[i+1] == 'u'){
			cout << ans + s.substr(index, i-index) + ".ru/" + s.substr(i+2) << endl;
			return 0;
		}
	cout << ans + s.substr(index, (int)s.size()-2-index) + ".ru" << endl;
	return 0;
}

/////////////
///////////////////

///////Euler's Totient

#include <iostream> 
using namespace std;  
  
// Function to return gcd of a and b  
int gcd(int a, int b)  {  
    if (a == 0)  
        return b;  
    return gcd(b % a, a);  
}  
  
// A simple method to evaluate Euler Totient Function  
int phi(unsigned int n)  
{  
    unsigned int result = 1;  
    for (int i = 2; i < n; i++)  
        if (gcd(i, n) == 1)  
            result++;  
    return result;  
}  
// Driver program to test above function  
int main()  
{  
    int n;  
    for (n = 1; n <= 10; n++)  
        cout << "phi("<<n<<") = " << phi(n) << endl;  
    return 0;  
}  

////////////
/////////////////














