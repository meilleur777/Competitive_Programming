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

int dy[4]={0, 0, -1, 1};
int dx[4]={1, -1, 0, 0};

int main() {
	init_code();

	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	queue<intp> q;
	vector<vector<int>> vis(h, vector<int>(w, INF));
	rep(i, h) rep(j, w) {
		if (a[i][j]=='#') {
			q.push({i, j});
			vis[i][j]=0;
		}
	}
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second;
		q.pop();
		for (int d=0; d<4; d++) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=h || ny<0 || nx>=w || nx<0) continue;
			if (a[ny][nx]=='#') continue;
			if (vis[ny][nx]>vis[y][x]+1) {
				vis[ny][nx]=vis[y][x]+1;
				q.push({ny, nx});
			}
		}
	}
	int ans=0;
	rep(i, h) rep(j, w) {
		ans=max(ans, vis[i][j]);
	}
	cout << ans;

	return 0;
}
