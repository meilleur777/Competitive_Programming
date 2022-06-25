#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> a[i][j];
	int ans=0;
	int dy[4]={0, 0, 1, -1};
	int dx[4]={1, -1, 0, 0};
	while (true) {
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		function<void(int, int)> dfs=[&](int y, int x) {
			vis[y][x]=true;
			rep(d, 4) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=m || nx<0) continue;
				if (!vis[ny][nx] && a[ny][nx]>0) dfs(ny, nx);
			}
		};
		int cnt=0;
		rep(i, n) rep(j, m) {
			if (!vis[i][j] && a[i][j]>0) {
				dfs(i, j);
				cnt++;
			}
		}
		if (cnt>1) {
			cout << ans;
			return 0;
		}
		ans++;
		bool flag=false;
		vector<vector<int>> b=a;
		rep(i, n) rep(j, m) {
			if (!a[i][j]) continue;
			int tmp=0;
			flag=true;
			rep(d, 4) {
				int ny=i+dy[d], nx=j+dx[d];
				if (ny>=n || ny<0 || nx>=m || nx<0) continue;
				tmp+=!a[ny][nx];
			}
			b[i][j]=max(0, a[i][j]-tmp);
		}
		a=b;
		if (!flag) {
			cout << 0;
			return 0;
		}
	}

	return 0;
}
