#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int gcd(int a, int b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> ans;
	ans.push_back(2*3);
	ans.push_back(3*5);
	ans.push_back(5*2);
	int fbd[3]={5, 2, 3};
	set<int> st;
	for (int i=0; i<3; i++) {
		for (int j=2; j*ans[i]<=10000; j++) {
			if (st.find(ans[i]*j)!=st.end()) {
				// cout << ans[i]*j << '\n';
				continue;
			}
			ans.push_back(ans[i]*j);
			st.insert(ans.back());
		}
	}
	// for (int i=0; i<=n; i++) {
	// 	for (int j=i+1; j<=n; j++) {
	// 		if (gcd(ans[i], ans[j])<=1) {
	// 			cout << ans[i] << ' ' << ans[j] << '\n';
	// 		}
	// 	}
	// }
	// int g=ans[0];
	// rep(i, n) g=gcd(ans[i], g);
	// cout << g << '\n';
	// cout << ans.size() << '\n';
	rep(i, n) cout << ans[i] << ' ';

	return 0;
}
