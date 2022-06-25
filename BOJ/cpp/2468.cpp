#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int N, hi;
bool vis[101][101];
int board[101][101];
int dy[]={0, 0, -1, 1};
int dx[]={1, -1, 0, 0};

void DFS(int y, int x) {
	vis[y][x]=true;
	for (int i=0; i<4; i++) {
		int ny=y+dy[i], nx=x+dx[i];
		if (ny>=N || ny<0 || nx>=N || nx<0) continue;
		if (!vis[ny][nx] && board[ny][nx]>hi) {
			DFS(ny, nx);
		}
	}
}

int main() {
	init_code();

	cin >> N;
	rep(i, N) rep(j, N) cin >> board[i][j];
	int ans=-1;
	for (int i=0; i<=101; i++) {
		hi=i;
		int cnt=0;
		memset(vis, false, sizeof(vis));
		for (int j=0; j<N; j++) {
			for (int k=0; k<N; k++) {
				if (!vis[j][k] && board[j][k]>hi) {
					DFS(j, k);
					cnt++;
				}
			}
		}
		ans=max(ans, cnt);
	}
	cout << ans;

	return 0;
}
