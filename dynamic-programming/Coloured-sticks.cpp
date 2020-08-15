//// https://codeforces.com/contest/1398/problem/D
////// p4 ed

#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int a[N], b[N], c[N];
int dp[N][N][N];
int n, m, k;
 
int main()
{
	startTime = clock();
 
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