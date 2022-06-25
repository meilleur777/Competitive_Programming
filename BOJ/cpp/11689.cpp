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

/*Euler Totient Function*/

int main() {
	init_code();

	ll n;
	cin >> n;
	ll ans = n;
	for (ll i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			ans -= ans/i;
		}
		while (n%i == 0) {
			n /= i;
		}
	}
	if (n != 1) {
		ans -= ans/n;
	}
	cout << ans;

	return 0;
}
