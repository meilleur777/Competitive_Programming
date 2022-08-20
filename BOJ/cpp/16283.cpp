#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll a, b, n, w;
	cin >> a >> b >> n >> w;
	// x+y=n, ax+by=w
	set<intp> st;
	for (int x=1; x<n; x++) {
		if (a*x+b*(n-x)==w) {
			st.insert({x, n-x});
		}
	}
	if ((int)st.size()!=1) cout << -1;
	else cout << (*st.begin()).first << ' ' << (*st.begin()).second;

	return 0;
}
