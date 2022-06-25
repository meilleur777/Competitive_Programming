#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(3));
	rep(i, n) rep(j, 3) cin >> v[i][j];
	vector<vector<int>> edge(n);
	rep(i, n) rep(j, n) {
		if (v[i]==v[j]) {
			if (i<j) edge[i].push_back(j);
		}
		else if (v[i][0]>=v[j][0] && v[i][1]>=v[j][1] && v[i][2]>=v[j][2]) {
			edge[i].push_back(j);
		}
	}	
	vector<bool> vis;
	vector<int> a(n, -1);
	function<bool(int)> dfs=[&](int now) {
		for (auto nxt:edge[now]) {
			if (vis[nxt]) continue;
			vis[nxt]=true;
			if (a[nxt]==-1 || dfs(a[nxt])) {
				a[nxt]=now;
				return true;
			}
		}
		return false;
	};
	int ans=0;
	rep(i, n) rep(j, 2) {
		vis=vector<bool>(n, false);
		ans+=dfs(i);
	}
	cout << n-ans;

	return 0;
}
