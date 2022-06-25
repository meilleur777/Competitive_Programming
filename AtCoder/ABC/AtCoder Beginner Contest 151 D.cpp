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
	vector<string> brd(h);
	rep(i, h) cin >> brd[i];
	int ans=-1;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (brd[i][j]!='.') continue;
			queue<intp> q;
			q.push({i, j});
			vector<vector<int> > vis(h, vector<int>(w, -1));
			vis[i][j]=0;
			while (!q.empty()) {
				int y=q.front().first;
				int x=q.front().second;
				q.pop();
				for (int d=0; d<4; d++) {
					int ny=y+dy[d], nx=x+dx[d];
					if (ny>=h || ny<0 || nx>=w || nx<0) continue;
					if (vis[ny][nx]==-1 && brd[ny][nx]=='.') {
						vis[ny][nx]=vis[y][x]+1;
						q.push({ny, nx});
					}
				}
			}
			for (int k=0; k<h; k++) {
				for (int l=0; l<w; l++) {
					if (vis[k][l]==-1) continue;
					ans=max(ans, vis[k][l]);
				}
			}
		}
	}
	cout << ans;

	return 0;
}
