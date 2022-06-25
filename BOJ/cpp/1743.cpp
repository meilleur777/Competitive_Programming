#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> mp(n, vector<bool>(m, false)), vis=mp;
	int c;
	cin >> c;
	rep(i, c) {
		int y, x;
		cin >> y >> x;
		y--, x--;
		mp[y][x]=true;
	}
	int ans=0;
	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	function<int(int, int)> sol=[&](int y, int x) {
		int ret=1;
		vis[y][x]=true;
		rep(d, 4) {
			int ny=y+dy[d];
			int nx=x+dx[d];
			if (ny>=n || ny<0 || nx>=m || nx<0) continue;
			if (!vis[ny][nx] && mp[ny][nx]) {
				ret+=sol(ny, nx);
			}
		}
		return ret;
	};
	rep(i, n) rep(j, m) {
		if (!vis[i][j] && mp[i][j]) {
			ans=max(ans, sol(i, j));
		}
	}
	cout << ans;

	return 0;
}
