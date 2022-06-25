#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

const int dy[4]={0, 0, -1, 1};
const int dx[4]={1, -1, 0, 0};

int n, m;
vector<vector<int>> a;
vector<vector<bool>> vis;

int dfs(int y, int x) {
	vis[y][x]=true;
	int ret=1;
	for (int d=0; d<4; d++) {
		int ny=y+dy[d], nx=x+dx[d];
		if (ny>=n || ny<0 || nx>=m || nx<0) continue;
		if (!vis[ny][nx] && a[ny][nx]) {
			ret+=dfs(ny, nx);
		}
	}
	return ret;
}

int main() {
	init_code();

	cin >> n >> m;
	a=vector<vector<int>>(n, vector<int>(m));
	vis=vector<vector<bool>>(n, vector<bool>(m, false));
	rep(i, n) rep(j, m) cin >> a[i][j];
	int ans=0, cnt=0;
	rep(i, n) rep(j, m) {
		if (!vis[i][j] && a[i][j]) {
			cnt++;
			ans=max(ans, dfs(i, j));
		}
	}
	cout << cnt << '\n' << ans;

	return 0;
}
