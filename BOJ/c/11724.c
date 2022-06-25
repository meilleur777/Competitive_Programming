#include <stdio.h>

int check[1001] = { 0 };
int pathNum[1001] = { 0 };
int paths[1001][1001];

void traverse(int V) {
	int i;
	check[V] = 1;
	for (i = 0; i < pathNum[V]; i++)
        if (!check[paths[V][i]]) traverse(paths[V][i]);
}

int main() {
	int i, j, N, M, count = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		paths[start][pathNum[start]++] = end;
		paths[end][pathNum[end]++] = start;
	}
	
	for (i = 1; i <= N; i++) {
		if (!check[i]) {
			traverse(i);
			count++;
		}
	}
	
	printf("%d", count);
	
	return 0;
}

