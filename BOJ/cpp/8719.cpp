#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x, w, cnt=0;
		cin >> x >> w;
		while (x<w) {
			cnt++;
			x*=2;
		}
		cout << cnt << '\n';
	}

	return 0;
}
