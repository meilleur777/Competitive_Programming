#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int dy[]={0, 0, 1, 1, 1, -1, -1, -1};
	int dx[]={1, -1, 1, 0, -1, 1, 0, -1};
	while (true) {
		int w, h;
		cin >> w >> h;
		if (!w && !h) break;
		vector<vector<int>> a(h, vector<int>(w));
		rep(i, h) rep(j, w) cin >> a[i][j];
		vector<vector<bool>> vis(h, vector<bool>(w, false));
		function<void(int, int)> dfs=[&](int y, int x) {
			vis[y][x]=true;
			rep(d, 8) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=h || ny<0 || nx>=w || nx<0) continue;
				if (!vis[ny][nx] && a[ny][nx]) dfs(ny, nx);
			}
		};
		int ans=0;
		rep(i, h) rep(j, w) if (!vis[i][j] && a[i][j]) {
			dfs(i, j);
			ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
