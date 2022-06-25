#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 1000000000

typedef struct {
	int num;
	int kevin;
} result;

result res[102];
int queue[200];
int edgeNum[102] = { 0 };
int edge[102][102];

int cpr(const void *a, const void *b) {
	result *m = (result *)a, *n = (result *)b;
	return (m->kevin > n->kevin) ? 1 : (m->kevin < n->kevin) ? -1 : 
		   (m->num > n->num) ? 1 : (m->num < n->num) ? -1 : 0;
}

int solve(int s, int N) {
	int i, res = 0, check[102] = { 0 };
	int front = 0, back = 0, queue[200];
	queue[back++] = s;
	check[s] = 1;
	while (front < back) {
		int temp = queue[front++]; 
		for (i = 0; i < edgeNum[temp]; i++) {
			if (!check[edge[temp][i]]) {
				check[edge[temp][i]] = check[temp] + 1;
				queue[back++] = edge[temp][i];
			}
		}
	}
	for (i = 1; i <= N; i++) res += check[i];
	return res - N;
}

int main() {
	int i, N, M; scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		edge[a][edgeNum[a]++] = b;
		edge[b][edgeNum[b]++] = a;
	}
	for (i = 1; i <= N; i++) {
		res[i].num = i;
		res[i].kevin = solve(i, N);
	}
	qsort(res + 1, N, sizeof(result), cpr);
	printf("%d", res[1].num);
}
