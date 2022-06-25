#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int number;
	short count;
} result;

char check[10001] = { 0 };
short pathNum[10001];
short paths[10001][10001];

int compare(const void *a, const void *b) {
	result *m = (result *)a, *n = (result *)b;
	return (m->count > n->count) ? -1 : (m->count < n->count) ? 1 : 0;
}

int dfs(int V) {
	int i, count = 1;
	check[V] = 1;
	for (i = 0; i < pathNum[V]; i++)
		if (!check[paths[V][i]]) count += dfs(paths[V][i]);
	return count;
}

int main() {
	int i, N, M;
	result results[10001];
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		paths[b][pathNum[b]++] = a;
	}
	
	int j;
	for (i = 1; i <= N; i++) {
		results[i].number = i;
		results[i].count = 1; 
		check[i] = 1;
		for (j = 0; j < pathNum[i]; j++)
			if (!check[paths[i][j]]) results[i].count += dfs(paths[i][j]);
		memset(check, 0, sizeof(char) * 10001);
	}
	
	qsort(results + 1, N, sizeof(result), compare);
		
	short max = results[1].count;	
	for (i = 1; i <= N; i++) {
		if (results[i].count < max) break;
		printf("%d ", results[i].number);
	}
}
