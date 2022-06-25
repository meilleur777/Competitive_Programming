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
		int t = n, d = 0, a = 0;
		while (t) {
			t /= 10;
			a += (int)pow(10, d);
			d++;
		}
		int ans = (d-1)*9 +n/a;
		cout << ans << '\n';
	}

	return 0;
}
