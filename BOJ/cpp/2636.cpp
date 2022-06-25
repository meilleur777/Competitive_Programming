#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
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

vector<intp> che;
vector<intp> nxt;
int A[101][101];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
vector<vector<bool> > vis;
int N, M;

int exist() {
	int cnt = 0;
	for (intp i : che) {
		if (A[i.first][i.second]) {
			cnt++;
		}
	}
	return cnt;
}


void DFS(int y, int x) {
	vis[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y+dy[i], nx = x+dx[i];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
		if (vis[ny][nx]) continue;
		if (A[ny][nx] == 1) nxt.push_back({ny, nx});
		else DFS(ny, nx);
	}
}

int main() {
	init_code();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			if (A[i][j]) {
				che.push_back({i, j});
			}
		}
	}
	int memo = 0, time = 0;
	while (true) {
		int t = exist();
		if (!t) {
			cout << time << '\n' << memo << '\n';
			return 0;
		}
		memo = t;
		nxt.clear();
		vis = vector<vector<bool> >(N, vector<bool>(M, false));
		for (int i = 0; i < M; i++) {
			if (!vis[0][i]) DFS(0, i);
			if (!vis[N-1][i]) DFS(N-1, i);
		}
		for (int i = 0; i < N; i++) {
			if (!vis[i][0]) DFS(i, 0);
			if (!vis[i][M-1]) DFS(i, M-1);
		}
		for (auto i : nxt) {
			A[i.first][i.second] = 0;
		}
		time++;
	}

	return 0;
}
