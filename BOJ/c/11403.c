#include <stdio.h>
#include <string.h>

int N;
int path[101][101];
int pathNum[101] = { 0 };
int check[101];

int DFS(int V) {
	int i;
	for (i = 0; i < pathNum[V]; i++) {
		if (!check[path[V][i]]) {
			check[path[V][i]] = 1;
			DFS(path[V][i]);
		}
	}
}

int main() {
	int i, j; scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int x; scanf("%d", &x);
			if (x) path[i][pathNum[i]++] = j;
		}
	}
	
	for (i = 0; i < N; i++) {
		memset(check, 0, 101 * sizeof(int));
		for (j = 0; j < pathNum[i]; j++) {
			if (!check[path[i][j]]) {
				check[path[i][j]] = 1;
				DFS(path[i][j]);
			}
		}
		for (j = 0; j < N; j++) printf("%d ", check[j]);
		printf("\n");
	}
}

