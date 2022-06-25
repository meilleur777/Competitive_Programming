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

int main() {
	init_code();

	ll l, q;
	cin >> l >> q;
	set<ll> m;
	m.insert(0);
	m.insert(l);
	while (q--) {
		ll c, x;
		cin >> c >> x;
		if (c==1) {
			m.insert(x);
		}
		else {
			auto tmp=m.upper_bound(x);
			auto t=tmp;
			t--;
			cout << *tmp-*t << '\n';
		}
	}

	return 0;
}
