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

int ans=0;
vector<vector<int>> a(5, vector<int>(5));
vector<vector<bool>> sel(6, vector<bool>(6, false));
vector<vector<bool>> vis(6, vector<bool>(6, false));

int dy[4]={0, 0, -1, 1};
int dx[4]={1, -1, 0, 0};

void dfs(int y, int x, int col) {
	vis[y][x]=true;
	for (int d=0; d<4; d++) {
		int ny=y+dy[d], nx=x+dx[d];
		if (ny>=6 || ny<0 || nx>=6 || nx<0) continue;
		if (!vis[ny][nx] && col==sel[ny][nx]) dfs(ny, nx, col);
	}
}

bool chk() {
	for (int i=1; i<5; i++) {
		for (int j=1; j<5; j++) {
			if (a[i][j] && !sel[i][j]) return false;
		}
	}
	vis=vector<vector<bool>>(6, vector<bool>(6, false));
	bool polflag=false, cflag=false;
	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			if (!vis[i][j]) {
				if (sel[i][j]) {
					if (cflag) return false;
					dfs(i, j, 1);
					cflag=true;
				}
				else if (!sel[i][j]) {
					if (polflag) return false;
					dfs(i, j, 0);
					polflag=true;
				}
			}
		}
	}
	return true;
}

void sol(int y, int x) {
	if (y==4 && x==5) {
		ans+=chk();
		return;
	}
	if (x==5) {
		sol(y+1, 1);
		return;
	}
	sel[y][x]=true;
	sol(y, x+1);
	sel[y][x]=false;
	sol(y, x+1);
}

int main() {
	init_code();

	rep(i, 4) rep(j, 4) cin >> a[i+1][j+1];
	sol(1, 1);
	cout << ans;

	return 0;
}
