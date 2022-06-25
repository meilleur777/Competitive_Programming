#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int k;
	cin >> k;
	vector<int> c;
	function<void(int)> pre=[&](int now) {
		if (now>k) return;
		pre(now+1);
		c.push_back(now);
		pre(now+1);
	};
	pre(1);
	vector<vector<int>> lev(k);
	rep(i, (1<<k)-1) {
		int a;
		cin >> a;
		lev[c[i]-1].push_back(a);
	}
	rep(i, k) {
		for (auto j:lev[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}

	return 0;
}
