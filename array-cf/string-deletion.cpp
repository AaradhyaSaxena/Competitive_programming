/////////https://codeforces.com/contest/1430/problem/E

///// string deletion

/// back in time (last>first)

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string str;
		cin>>str;

		int bank = 0;
		int idx = n-1;
		int turns = 0;

		while(idx>=0){
			int size = 0;
			int to_del = str[idx]-'0';

			while(idx>=0 and str[idx]-'0' == to_del){
				size++;
				idx--;
			}
			bank += size-1;
			
			turns++;
			if(bank==0 and idx==-1){
				break;
			}
			if(bank==0){
				idx--;
			}
			else{
				bank--;
			}
		}
		cout<<turns<<endl;
	}
}


///////// editorial
/*

Suppose the string consists of 𝑛 characters, and each character is different from the adjacent ones 
(so the string looks like 01010... or 10101...). 
It's easy to see that we can't make more than ⌈𝑛2⌉ operations 
(each operation deletes at least two characters, except for the case when the string consists of only one character). 

And there is an easy way to perform exactly ⌈𝑛2⌉
operations: always choose the last character and delete it.

Okay, what about the case when some adjacent characters in the string are equal? 
It's never optimal to delete a character that's different from both adjacent characters: 
since the second part of each operation always deletes the left block of equal characters, 
this action merges two blocks, so they will be deleted in one second part of the operation 
(which decreases the total number of operations).

So, we should always delete a character from a block with at least two equal characters. 
From which of the blocks, if there are more than one? 
It's easy to see that we should choose a character from the leftmost such block, 
since that block is the earliest to be deleted (and if we want to make the same action later, we might be unable to do it).

So, the solution is greedy: during each action, we have to find the leftmost block consisting of at least 2
equal characters, and delete a character from it (or the last character of the string, if there are no such blocks). 
Since the length of the string is up to 2^105 and the number of operations is up to 105, we should do it efficiently, 
for example, by storing the eligible blocks in some data structure.

*/

#include<bits/stdc++.h>

using namespace std;

char buf[200043];

int main()
{
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d", &n);
		scanf("%s", buf);
		string s = buf;

		queue<int> q;
		int cur = 0;
		
		for(int i = 0; i < n; i++)
		{
		 	if(i > 0 && s[i] != s[i - 1])
		 		cur++;
		 	
		 	if(i > 0 && s[i] == s[i - 1])
		 		q.push(cur);
		}

		int deleted = 0;       
		int score = 0;
		
		for(int i = 0; i < n; i++)
		{
			if(q.empty())
				break;
			
			q.pop();
			deleted++;
			score++;
			
			while(!q.empty() && q.front() == i)
			{
				q.pop();
				deleted++; 	
			}
			deleted++;
			//cerr << deleted << endl;
		}
		score += (n - deleted + 1) / 2;
		printf("%d\n", score);
	}
}









