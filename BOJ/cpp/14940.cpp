#include <string.h>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
int map[1001][1001];
int visit[1001][1001];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int sy, sx;	
	cin >> n >> m;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) sy = i, sx = j;
		}
	}
	
	visit[sy][sx] = 1;
	DFS(sy, sx);
	
	queue<pair<int, int> > q;
	q.push({ sy, sx });
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d], nx = x + dx[d];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || visit[ny][nx] != -1) continue;
			if (!map[ny][nx]) continue;
			visit[ny][nx] = visit[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) cout << 0 << ' ';
			else if (visit[i][j] != -1) cout << visit[i][j] - 1 << ' ';
			else cout << -1 << ' ';
		}
		cout << '\n';
	}
}

