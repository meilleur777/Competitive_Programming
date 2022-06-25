#include <stdio.h>
#include <string.h>

int N, M, time = 0;
int map[101][101], vis[101][101];
int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };

int exist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) return 1;
		}
	}
	return 0;
}

int DFS(int row, int col) {
	vis[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int trow = row + rdi[i];
		int tcol = col + cdi[i];
		if (trow >= 0 && trow < N && tcol >= 0 && tcol < M) {
			if (map[trow][tcol]) vis[trow][tcol]++;
			else if (!map[trow][tcol] && !vis[trow][tcol]) DFS(trow, tcol);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	while (exist()) {
		memset(vis, 0, sizeof(int) * 101 * 101);
		for (int i = 0; i < N; i++) {
			if (!map[i][0] && !vis[i][0]) DFS(i, 0);
			if (!map[i][M - 1] && !vis[i][M - 1]) DFS(i, 0);
		}
		for (int j = 0; j < M; j++) {
			if (!map[0][j] && !vis[0][j]) DFS(0, j);
			if (!map[N - 1][j] && !vis[N - 1][j]) DFS(N - 1, j);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && vis[i][j] >= 2) map[i][j] = 0; 
			}
		}
		time++;
	}
	printf("%d\n", time);
}

