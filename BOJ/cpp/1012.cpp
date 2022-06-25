#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	int dy[]={0, 0, 1, -1};
	int dx[]={1, -1, 0, 0};
	while (t--) {
		int n, m, k;
		cin >> m >> n >> k;
		vector<vector<bool>> a(n, vector<bool>(m, false)), vis;
		vis=a;
		rep(i, k) {
			int x, y;
			cin >> x >> y;
			a[y][x]=true;
		}
		int ans=0;
		function<void(int, int)> dfs=[&](int y, int x) {
			vis[y][x]=true;
			rep(d, 4) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=m || nx<0) continue;
				if (a[ny][nx] && !vis[ny][nx]) dfs(ny, nx);
			}	
		};
		rep(i, n) rep(j, m) {
			if (a[i][j] && !vis[i][j]) {
				ans++;
				dfs(i, j);
			}
		}
		cout << ans << '\n';	
	}

	return 0;
}
