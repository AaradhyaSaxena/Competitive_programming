///// https://codeforces.com/contest/1400/problem/B

///  swords and axe


#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, y, ks, kw, s, w, tmp, a, b, c, d, ans;
		scanf("%d%d%d%d%d%d", &x, &y, &ks, &kw, &s, &w);
		if (s > w)
			tmp = ks, ks = kw, kw = tmp, tmp = s, s = w, w = tmp;
		// sword is lighter now
		ans = 0;
		for (a = 0; a <= ks && a * s <= x; a++) {
			/// right-side = if we keep increasing swords, then how many axe can x carry.
			/// min of B and total number of axe.
			b = min(kw, (x - a * s) / w);
			/// min of swords left and num that y can carry
			c = min(ks - a, y / s);
			/// right side = how may axe can y carry after taking the left swords.
			d = min(kw - b, (y - c * s) / w);
			/// add all objects
			ans = max(ans, a + b + c + d);
		}
		printf("%d\n", ans);
	}
	return 0;
}
