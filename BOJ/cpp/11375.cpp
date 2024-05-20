#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
        while (k--) {
			int a;
			cin >> a;
            edge[i].push_back(a-1);
		}
	}

	vector<bool> vis;
	vector<int> par(m, -1);
	function<bool(int)> dfs=[&](int now) {
		for (auto nxt:edge[now]) {
			if (vis[nxt]) continue;
			vis[nxt]=true;

			if (par[nxt]==-1 || dfs(par[nxt])) {
				par[nxt]=now;
				return true;
			}
		}

		return false;
	};

	int ans=0;
	for (int i=0; i<n; i++) {
		vis=vector<bool>(m, false);
		ans+=dfs(i);
	}
	cout << ans;

	return 0;
}
