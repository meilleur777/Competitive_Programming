#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
	cin >> n >> m;
    vector<vector<int>> brd(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> brd[i][j];
	int ans=0;
	int dy[]={0, 0, -1, 1};
	int dx[]={1, -1, 0, 0};
	vector<vector<bool>> vis;
	while (true) {
		intp now={-1, -1};
		intp res={-1, -1};
		auto reset=[&]() {
			rep(i, n) rep(j, n) {
				if (vis[i][j]) vis[i][j]=(brd[i][j]!=0);
			}
		};
		function<intp(int, int, int)> dfs=[&](int y, int x, int col) {
			vis[y][x]=true;
			intp ret={1, -1};
			ret.second=brd[y][x]==0;
			for (int d=0; d<4; d++) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=n || nx<0) continue;
				if (!vis[ny][nx] && (brd[ny][nx]==0 || brd[ny][nx]==col)) {
					intp tmp=dfs(ny, nx, col);
					ret.first+=tmp.first;
					ret.second+=tmp.second;
				}
			}
			return ret;
		};
		vis=vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (!vis[i][j] && brd[i][j]>0) {
					intp tmp=dfs(i, j, brd[i][j]);
					if (tmp>=now) {
						res={i, j};
						now=tmp;
					}
					reset();
				}
			}
		}
		if (now.first<2) break;
		ans+=now.first*now.first;
		vis=vector<vector<bool>>(n, vector<bool>(n, false));
		function<void(int, int, int)> era=[&](int y, int x, int col) {
			vis[y][x]=true;
			brd[y][x]=-2;
			for (int d=0; d<4; d++) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=n || nx<0) continue;
				if (!vis[ny][nx] && (brd[ny][nx]==0 || brd[ny][nx]==col)) {
					era(ny, nx, col);
				}
			}
		};
		era(res.first, res.second, brd[res.first][res.second]);
		auto gra=[&]() {
			vector<vector<int>> tmp(n, vector<int>(n, -2));
			for (int i=n-1; i>=0; i--) rep(j, n) {
				if (brd[i][j]==-1) {
					tmp[i][j]=-1;
					continue;
				}
				if (brd[i][j]<0) {
					continue;
				}
				int y=i;
				while (y<n-1 && (tmp[y+1][j]<0 && tmp[y+1][j]!=-1)) {
					y++;
				}
				tmp[y][j]=brd[i][j];
			}
			brd=tmp;
		};
		auto rot=[&]() {
			vector<vector<int>> tmp(n, vector<int>(n));
			rep(i, n) rep(j, n) {
				tmp[n-1-j][i]=brd[i][j];
			}
			brd=tmp;
		};
		gra();
		rot();
		gra();
	}
	cout << ans;

	return 0;
}
