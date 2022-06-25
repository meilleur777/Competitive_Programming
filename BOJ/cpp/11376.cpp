#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	rep(i, n) {
		int k;
		cin >> k;
		rep(j, k) {
			int a;
			cin >> a;
			edge[i].push_back(a-1);
		}
	}
	vector<bool> vis;
	vector<int> a(m, -1);
	function<bool(int)> dfs=[&](int from) {
		for (auto to:edge[from]) {
			if (vis[to]) continue;
			vis[to]=true;
			if (a[to]==-1 || dfs(a[to])) {
				a[to]=from;
				return true;
			}
		}
		return false;
	};	
	int ans=0;
	rep(i, n) rep(j, 2) {
		vis=vector<bool>(m, false);
		ans+=!!dfs(i);
	}
	cout << ans;

	return 0;
}
