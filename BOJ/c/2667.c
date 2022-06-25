#include <stdio.h>
#include <stdlib.h>

int N, count = 0, result[700] = { 0 };	
int map[26][26], check[26][26] = { 0 };
int rowdir[4] = { 1, -1, 0, 0 };
int coldir[4] = { 0, 0, 1, -1 };

int compare(const void *a, const void *b) {
	int *m= (int *)a, *n = (int *)b;
	return (*m > *n) ? 1 : (*m < *n) ? -1 : 0;
}

void DFS(int row, int col) {
	int k;
	for (k = 0; k < 4; k++) {
		int trow = row + rowdir[k];
		int tcol = col + coldir[k];
		if (trow >= 0 && trow < N && tcol >= 0 && trow < N) {
			if (map[trow][tcol] && !check[trow][tcol]) {
				check[trow][tcol] = 1;
				result[count]++;
				DFS(trow, tcol);
			}
		}
	}	
}

int main() {
	int i, j; scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] && !check[i][j]) {
				check[i][j] = 1;
				result[count]++;
				DFS(i, j);
				count++;
			}
		}
	}
	printf("%d\n", count);
	qsort(result, count, sizeof(int), compare);
	for (i = 0; i < count; i++) printf("%d\n", result[i]);
}
