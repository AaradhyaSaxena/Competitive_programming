//// https://codeforces.com/contest/1398/problem/D
////// p4 ed

#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int a[N], b[N], c[N];
int dp[N][N][N];
int n, m, k;
 
int main(){
 
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(b, b + m);
	for (int i = 0; i < k; i++)
		scanf("%d", &c[i]);
	sort(c, c + k);
 
	for (int i = n; i >= 0; i--)
		for (int j = m; j >= 0; j--)
			for (int h = k; h >= 0; h--) {
				if (i > 0 && j > 0)
					dp[i - 1][j - 1][h] = max(dp[i - 1][j - 1][h], dp[i][j][h] + a[i - 1] * b[j - 1]);
				if (i > 0 && h > 0)
					dp[i - 1][j][h - 1] = max(dp[i - 1][j][h - 1], dp[i][j][h] + a[i - 1] * c[h - 1]);
				if (j > 0 && h > 0)
					dp[i][j - 1][h - 1] = max(dp[i][j - 1][h - 1], dp[i][j][h] + b[j - 1] * c[h - 1]);
			}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int h = 0; h <= k; h++)
				ans = max(ans, dp[i][j][h]);
	printf("%d\n", ans);
 
	return 0;
}


/*Incorrect appoach to think it as a problem of 3 pointers, and greedy selection of
sticks.*/

/*
First of all, it is easier to think of greed, but this problem will be related to the number of sticks.
There are many problems with greed, and the patching method cannot be solved.

Considering the DP of O(n3)O(n3), since there are three elements in total, 
you might as well design the state directly according to the definition: Status: 𝑓[𝑖,𝑗,𝑘]

Indicates the maximum value of the sum of the rectangular areas 
obtained under the premise that red uses i, green uses j, and blue uses k.

Entrance: All 0 is enough, no additional processing is required.

Transfer: The three matching methods can be directly enumerated.

Outlet: the maximum value of all values.

If you pay attention, prevent int from exploding
*/
