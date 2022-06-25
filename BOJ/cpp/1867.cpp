#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> edge(n);
	rep(i, k) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
	}
	vector<bool> vis;
	vector<int> a(n, -1);
	int ans=0;
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
	rep(i, n) {
		vis=vector<bool>(n, false);
		ans+=dfs(i);
	}
	cout << ans;

	return 0;
}
