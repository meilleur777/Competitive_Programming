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

	int cntv, cnto;
	vector<int> dy({0, 0, -1, 1}), dx({1, -1, 0, 0});
	vector<vector<bool>> vis(r, vector<bool>(c, false));
	function<void(int, int)> dfs=[&](int y, int x) {
		vis[y][x]=true;
		if (a[y][x]=='#') return;
		if (a[y][x]=='v') cntv++;
		if (a[y][x]=='o') cnto++;

		rep(d, 4) {
			int ny=y+dy[d];
			int nx=x+dx[d];
			if (ny>=r || ny<0 || nx>=c || nx<0) continue;
			if (vis[ny][nx]) continue;
			dfs(ny, nx);
		}
	};

	int ansv=0, anso=0;
	rep(i, r) rep(j, c) {
		if (!vis[i][j]) {
			cntv=0, cnto=0;
			dfs(i, j);
			if (cntv>=cnto) {
				ansv+=cntv;
			}
			else {
				anso+=cnto;
			}
		}
	}
	cout << anso << ' ' << ansv;

	return 0;
}
