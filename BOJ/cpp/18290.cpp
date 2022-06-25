#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> a[i][j];
	int mx=-1e8;
	vector<vector<bool>> sel(n, vector<bool>(m, false));
	vector<int> dy({0, 0, -1, 1}), dx({1, -1, 0, 0});
	function<void(int, int, int, int)> sol=[&](int y, int x, int cnt, int now) {
		if (y>=n) {
			if (cnt==k) {
				mx=max(mx, now);
			}
			return;
		}
		if (x>=m) {
			sol(y+1, 0, cnt, now);
			return;
		}
		sol(y, x+1, cnt, now);
		if (cnt<k) {
			bool flag=false;
			rep(d, 4) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=m || nx<0) continue;
				if (sel[ny][nx]) flag=true;
			}
			if (!flag) {
				sel[y][x]=true;
				sol(y, x+1, cnt+1, now+a[y][x]);
				sel[y][x]=false;
			}
		}
	};
	sol(0, 0, 0, 0);
	cout << mx;

	return 0;
}
