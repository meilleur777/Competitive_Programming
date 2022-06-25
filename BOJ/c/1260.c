#include <stdio.h>
#include <stdlib.h>

int check[1001] = { 0 };
int arrNum[1001] = { 0 };
int arr[1001][10001];

int compare(const void *a, const void *b) {
	int *m = (int *)a, *n = (int *)b;
	return (*m > *n) ? 1 : (*m < *n) ? -1 : 0;
}

void dfs(int V) {
	int i;
	printf("%d ", V);
	check[V] = 1;
	
	for (i = 0; i < arrNum[V]; i++) 
		if (!check[arr[V][i]]) dfs(arr[V][i]);
}

int main() {
	int i, j;
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	
	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][arrNum[a]++] = b;
		arr[b][arrNum[b]++] = a;
	}
	
	for (i = 1; i <= N; i++) 
		qsort(arr[i], arrNum[i], sizeof(int), compare);
	
	dfs(V);
	printf("\n");
	
	int queue[1001], sptr = 0, eptr = 0;
	check[V] = 2;
	queue[eptr++] = V;
	while (sptr < eptr) {
		V = queue[sptr++];
		printf("%d ", V);
		for (j = 0; j < arrNum[V]; j++) {
			if (check[arr[V][j]] == 1) {
				queue[eptr++] = arr[V][j];
				check[arr[V][j]] = 2;
			}
		}
	}
	
	return 0;
}
