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

	ll T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	ll a = (A1-B1)*T1, b = (A2-B2)*T2;
	if (a+b == 0) {
		cout << "infinity";
		return 0;
	}
	if (a < 0) {
		a = -a, b = -b;
	}
	if (a+b > 0) {
		cout << 0;
	}
	else if (a+b < 0) {
		ll t = -(a+b);
		ll res = (a/t)*2+1;
		if (a%t == 0) {
			res--;
		}
		cout << res;
	}

	return 0;
}
