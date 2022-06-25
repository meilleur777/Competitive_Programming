#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	while (true) {
		int k;
		cin >> k;
		if (!k) break;
		vector<int> v(k), a(6);
		rep(i, k) cin >> v[i];
		function<void(int, int)> sol=[&](int now, int las) {
			if (now==6) {
				for (auto i:a) cout << v[i] << ' ';
				cout << '\n';
				return;
			}
			if (las==k) return;
			for (int i=las; i<k; i++) {
				a[now]=i;
				sol(now+1, i+1);
			}
		};
		sol(0, 0);
		cout << '\n';
	}

	return 0;
}
