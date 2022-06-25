#include <stdio.h>
#include <iostream>
using namespace std;

int M, N, board[1001][1001];
bool visit[1001][1001] = { false };

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void DFS(int y, int x) {
	visit[y][x] = true; board[y][x] = 2;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d], nx = x + dx[d];
		if (ny >= M || ny < 0 || nx >= N || nx < 0 || visit[ny][nx]) continue;
		if (!board[ny][nx]) DFS(ny, nx);
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) scanf("%1d", &board[i][j]);
	for (int i = 0; i < N; i++) if (!board[0][i]) DFS(0, i);
	for (int i = 0; i < N; i++) if (board[M - 1][i] == 2) { cout << "YES\n"; return 0; }
	cout << "NO\n";
}

