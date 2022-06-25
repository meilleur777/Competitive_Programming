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

int main() {
	init_code();

	int m, n;
	cin >> m >> n;
	queue<intp> q;
	vector<vector<int> > brd(n, vector<int>(m));
	vector<vector<int> > vis(n, vector<int>(m, -1));
	rep(i, n) rep(j, m) {
		cin >> brd[i][j];
		if (brd[i][j]==1) {
			q.push({i, j});
			vis[i][j]=0;
		}
	}
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int ny=y+dy[i], nx=x+dx[i];
			if (ny>=n || ny<0 || nx>=m || nx<0) continue;
			if (vis[ny][nx]==-1 && brd[ny][nx]==0) {
				vis[ny][nx]=vis[y][x]+1;
				q.push({ny, nx});
			}
		}
	}
	int res=0;
	bool flag=true;
	rep(i, n) rep(j, m) {
		if (brd[i][j]==0) {
			if (vis[i][j]==-1) flag=false;
			res=max(res, vis[i][j]);
		}
	}
	if (flag) cout << res;
	else cout << -1;

	return 0;
}
