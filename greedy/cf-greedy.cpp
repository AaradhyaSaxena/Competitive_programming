///// cf-greedy

///// palindrome of length less than 2

// https://codeforces.com/contest/1466/problem/C
#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 7;
int n;
char in[N];
bool used[N];

void solve(){
	scanf("%s", in + 1);
	n = strlen(in + 1);

	for(int i = 1; i <= n; ++i){
		used[i] = false;
	}

	int ans = 0;
	for(int i = 2; i <= n; ++i){
		bool use_need = false;
		if(in[i] == in[i - 1] && !used[i - 1]){
			use_need = true;
		}
		if(i > 2 && in[i] == in[i - 2] && !used[i - 2]){
			use_need = true;
		}
		used[i] = use_need;
		ans += used[i];
	}
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	while(cases--){
		solve();
	}
	return 0;
}
/*
The main observation is that if there exists a palindrome of length larger than 3,then there exists a pal of length 2 or 3. 
This observation allows us to simplify the task to erasing all palindromes of length 2 or 3. 
We can also notice that each character will be replaced at most once.
From now on, there are a few possible solutions. 
The easiest one is to iterate over a word from left to right. When we encounter a palindrome 
(of length 2or 3) ending on the current position, consisting of unmarked elements,
we greedily mark this character as the one we want to replace. The number of marked characters is the answer, 
as it turns out that we can obtain a valid palindrome-less sequence by replacing only the letters on the marked positions. 
The complexity is O(𝑛).
*/
//////////////////////////
///////////////////////

























