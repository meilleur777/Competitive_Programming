#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, r, c, d;
	cin >> n >> m >> r >> c >> d;
	vector<vector<int>> mp(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> mp[i][j];
	vector<int> dy({-1, 0, 1, 0}), dx({0, 1, 0, -1});
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	function<void(int, int, int)> sol=[&](int y, int x, int dir) {
		vis[y][x]=true;
		rep(i, 4) {
			dir=(dir+3)%4;
			int ny=y+dy[dir];
			int nx=x+dx[dir];
			if (mp[ny][nx]==1) continue;
			if (vis[ny][nx]) continue;
			sol(ny, nx, dir);
			return;
		}
		int ny=y-dy[dir];
		int nx=x-dx[dir];
		if (mp[ny][nx]==1) return;
		sol(ny, nx, dir);
	};
	sol(r, c, d);
	int ans=0;
	rep(i, n) rep(j, m) ans+=vis[i][j];
	cout << ans;

	return 0;
}
