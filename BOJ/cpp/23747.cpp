#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int r, c;
	cin >> r >> c;
	vector<string> a(r);
	rep(i, r) cin >> a[i];
	int sy, sx;
	cin >> sy >> sx;
	sy--, sx--;
	string s;
	cin >> s;
	vector<vector<bool>> wrd(r, vector<bool>(c, false)), vis;
	vis=wrd;
	for (auto i:s) {
		if (i=='W') wrd[sy][sx]=true;
		if (i=='L') sx--;
		if (i=='U') sy--;
		if (i=='R') sx++;
		if (i=='D') sy++;
	}
	int dy[]={0, 0, -1 ,1};
	int dx[]={1, -1, 0, 0};
	function<void(int, int)> dfs=[&](int y, int x) {
		vis[y][x]=true;
		rep(d, 4) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=r || ny<0 || nx>=c || nx<0) continue;
			if (a[y][x]==a[ny][nx] && !vis[ny][nx]) dfs(ny, nx);
		}
	};
	rep(i, r) rep(j, c) {
		if (!vis[i][j] && wrd[i][j]) {
			dfs(i, j);
		}
	}
	rep(d, 4) {
		int ny=sy+dy[d], nx=sx+dx[d];
		if (ny>=r || ny<0 || nx>=c || nx<0) continue;
		vis[ny][nx]=true;
	}
	vis[sy][sx]=true;
	rep(i, r) {
		rep(j, c) {
			if (vis[i][j]) cout << '.';
			else cout << '#';
		}
		cout << '\n';
	}

	return 0;
}
