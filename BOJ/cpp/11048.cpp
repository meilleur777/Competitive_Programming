#include <string.h>
#include <iostream>
using namespace std;

int N, M;
int map[1001][1001];
int cache[1001][1001];
bool visit[1001][1001];

int dy[3] = { 1, 0, 1 };
int dx[3] = { 0, 1, 1 };

int solve(int y, int x) {
	if (y == N - 1 && x == M - 1) return map[y][x];
	
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	
	for (int d = 0; d < 3; d++) {
		int ny = y + dy[d], nx = x + dx[d];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
		if (!visit[ny][nx]) {
			visit[ny][nx] = true;
			ret = max(ret, map[y][x] + solve(ny, nx));
			visit[ny][nx] = false;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];
	visit[0][0] = true;
	cout << solve(0, 0) << '\n';	
}

