#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> pre(n);
	vector<int> dp(n, -1), cost(n);
	rep(i, n) {
		cin >> cost[i];
		int a;
		while (true) {
			cin >> a;
			if (a==-1) break;
			pre[i].push_back(a-1);
		}
	}
	function<int(int)> sol=[&](int now) {
		int& ret=dp[now];
		if (ret!=-1) return ret;
		if (pre[now].empty()) return ret=cost[now];
		for (auto nxt:pre[now]) {
			ret=max(ret, sol(nxt)+cost[now]);
		}
		return ret;
	};
	rep(i, n) cout << sol(i) << '\n';

	return 0;
}
