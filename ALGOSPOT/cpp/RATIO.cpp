#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int MAX = 2*1e9;

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll N, M;
		cin >> N >> M;
		ll R = 100LL*M/N + 1;
		if (R >= 100) {
			cout << -1 << '\n';
			continue;
		}
		ll temp = (R*N-100*M+99-R)/(100-R);
		if (temp > MAX) {
			cout << -1 << '\n';
		}
		else {
			cout << temp << '\n';
		}
	}

	return 0;
}
