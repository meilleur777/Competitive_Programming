#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		ll ans = 0;
		map<ll, ll> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			ans += m[x-i];
			m[x-i]++;
		}
		cout << ans << '\n';
	}

	return 0;
}
