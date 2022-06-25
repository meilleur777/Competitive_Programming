#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int m, n;
	cin >> m >> n;
	vector<vector<int>> a(m, vector<int>(n, -1)), q(m, vector<int>(n));
	rep(i, m) rep(j, n) cin >> q[i][j];
	a[m-1][n-1]=1;
	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	function<int(int, int)> dfs=[&](int y, int x) {
		if (a[y][x]!=-1) return a[y][x];
		int& ret=a[y][x];
		ret=0;
		rep(d, 4) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=m || ny<0 || nx>=n || nx<0) continue;
			if (q[y][x]>q[ny][nx]) ret+=dfs(ny, nx);
		}
		return ret;
	};
	cout << dfs(0, 0);

	return 0;
}
