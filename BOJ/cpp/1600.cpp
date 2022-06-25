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

int dy[4]={0, 0, -1, 1} ;
int dx[4]={1, -1, 0, 0};
int hy[]={-2, -1, 1, 2, 2, 1, -1, -2};
int hx[]={1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	init_code();

	int k, w, h;
	cin >> k >> w >> h;
	vector<vector<int> > brd(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> brd[i][j];
	vector<vector<vector<int> > > vis(k+1, vector<vector<int> >(h, vector<int>(w, -1)));
	queue<pair<int, intp> > q;
	q.push({0, {0, 0}});
	vis[0][0][0]=0;
	while (!q.empty()) {
		int c=q.front().first;
		int y=q.front().second.first, x=q.front().second.second;
		q.pop();
		if (y==h-1 && x==w-1) break;
		for (int d=0; d<4; d++) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=h || ny<0 || nx>=w || nx<0) continue;
			if (vis[c][ny][nx]==-1 && brd[ny][nx]==0) {
				vis[c][ny][nx]=vis[c][y][x]+1;
				q.push({c, {ny, nx}});
			}
		}
		if (c<k) {
			for (int d=0; d<8; d++) {
				int ny=y+hy[d], nx=x+hx[d];
				if (ny>=h || ny<0 || nx>=w || nx<0) continue;
				if (vis[c+1][ny][nx]==-1 && brd[ny][nx]==0) {
					vis[c+1][ny][nx]=vis[c][y][x]+1;
					q.push({c+1, {ny, nx}});
				}	
			}
		}
	}
	int ans=INF;
	for (int i=0; i<=k; i++) {
		if (vis[i][h-1][w-1]!=-1) {
			ans=min(ans, vis[i][h-1][w-1]);
		}
	}
	if (ans==INF) cout << -1;
	else cout << ans;

	return 0;
}
