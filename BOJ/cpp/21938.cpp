#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> mp(n, vector<int>(m, 0));
	rep(i, n) rep(j, m) {
		int r, g, b;
		cin >> r >> g >> b;
		mp[i][j]=r+g+b;
	}
	int t;
	cin >> t;
	rep(i, n) rep(j, m) mp[i][j]=mp[i][j]>=3*t;

	int ans=0;
	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	function<void(int, int)> dfs=[&](int y, int x) {
		vis[y][x]=true;
		rep(d, 4) {
			int ny=y+dy[d];
			int nx=x+dx[d];
			if (ny>=n || ny<0 || nx>=m || nx<0) continue;
			if (vis[ny][nx] || !mp[ny][nx]) continue;
			dfs(ny, nx);
		}
	};
	rep(i, n) rep(j, m) {
		if (!vis[i][j] && mp[i][j]) {
			ans++;
			dfs(i, j);
		}
	}
	cout << ans;

	return 0;
}
