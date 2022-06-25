#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int vis[51][51][51][51];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> a[i][j];
	int dy[]={0, 0, -1, 1};
	int dx[]={1, -1, 0, 0};
	int mx=0;
	memset(vis, -1, sizeof(vis));
	rep(i, n) rep(j, m) {
		if (!a[i][j]) continue;
		queue<intp> q;
		vis[i][j][i][j]=0;
		q.push({i, j});
		while (!q.empty()) {
			int y=q.front().first, x=q.front().second;
			q.pop();
			rep(d, 4) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=m || nx<0) continue;
				if (vis[i][j][ny][nx]==-1 && a[ny][nx]) {
					vis[i][j][ny][nx]=vis[i][j][y][x]+1;
					q.push({ny, nx});
				}
			}
		}
		rep(k, n) rep(l, m) mx=max(mx, vis[i][j][k][l]);
	}
	int ans=0;
	rep(i, n) rep(j, m) rep(k, n) rep(l, m) {
		if (vis[i][j][k][l]==mx) {
			ans=max(ans, a[i][j]+a[k][l]);
		}
	}
	cout << ans;

	return 0;
}
