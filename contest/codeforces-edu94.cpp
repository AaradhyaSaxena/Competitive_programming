///////////////////////////////

// #include <stdio.h>
// #include <string.h>
     
// #define N 3000
// int main() {
//    	int t;
//    	scanf("%d", &t);
//    	while (t--) {
//    		static int aa[N], kk[N + 1], ll[N + 1];
//    		int n, i, j;
//     	long long ans;
//    		scanf("%d", &n);
//    		for (i = 0; i < n; i++)
//    			scanf("%d", &aa[i]);
   		
//    		ans = 0;
//    		for (i = 0; i < n; i++) {
//    			int cnt;
//     		memset(kk, 0, (n + 1) * sizeof *kk);
//     		memset(ll, 0, (n + 1) * sizeof *ll);
//     		for (j = i + 2; j < n; j++)
//     			ll[aa[j]]++;
//     		cnt = 0;
//     		for (j = i + 1; j < n; j++) {
//     			if (aa[j] == aa[i])
//     				ans += cnt;
//     			if (j + 1 < n)
//     				cnt -= kk[aa[j + 1]], ll[aa[j + 1]]--;
//     			cnt += ll[aa[j]], kk[aa[j]]++;
// 			}
// 		}
// 		printf("%lld\n", ans);
// 	}
// 	return 0;
// }

////////// p3

#include <stdio.h>
#include <string.h>
 
#define N 100000
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		static char cc[N + 1], cc_[N + 1];
		int n, x, i;
		scanf("%s%d", cc, &x), n = strlen(cc);
		for (i = 0; i < n; i++){
			if(i >= x && cc[i - x] == '0' || i + x < n && cc[i + x] == '0'){
				cc_[i] = '0';
			}else{
				cc_[i] = '1';
			}
		}
		cc_[n] = 0;
		for (i = 0; i < n; i++){
			if (cc[i] == '1' && (i < x || cc_[i - x] == '0') && (i + x >= n || cc_[i + x] == '0')) {
				cc_[0] = '-', cc_[1] = '1', cc_[2] = 0;
				break;
			}
		}
		printf("%s\n", cc_);
	}
	return 0;
}

/////// p2

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

////////////// p1

#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string ans = "";
		for(int i=0; i<s.length(); i+=2){
			ans += s[i];
		}
		cout<<ans<<endl;
	}
}

//////////////




