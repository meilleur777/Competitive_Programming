#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> m >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	ll wans=0, bans=0;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<int> dy({0, 0, -1, 1});
	vector<int> dx({1, -1, 0, 0});
	function<ll(int, int)> dfs=[&](int y, int x) {
		vis[y][x]=true;
		ll ret=1;
		rep(d, 4) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=n || ny<0 || nx>=m || nx<0) continue;
			if (!vis[ny][nx] && a[ny][nx]==a[y][x]) {
				ret+=dfs(ny, nx);
			}
		}
		return ret;
	};
	rep(i, n) rep(j, m) {
		if (vis[i][j]) continue;
		ll tmp=dfs(i, j);
		if (a[i][j]=='W') wans+=tmp*tmp;
		else bans+=tmp*tmp;
	}
	cout << wans << ' ' << bans;

	return 0;
}
