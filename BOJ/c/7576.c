#include <stdio.h>
#include <stdlib.h>

int N, M, front = 0, back = 0;
int rowDirection[4] = { 1, -1, 0, 0 };
int colDirection[4] = { 0, 0, 1, -1 };
int rowStore[1000001], colStore[1000001] = { 0 };
int box[1001][1001];

int compare(const void *a, const void *b) {
	int *m = (int *)a, *n = (int *)b;
	return (*m > *n) ? -1 : (*m < *n) ? 1 : 0;
}

int checkClear() {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) if (!box[i][j]) return 0;
	return 1;
}

int main() {
	int i, j, k; scanf("%d %d", &M, &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				rowStore[back] = i;
				colStore[back++] = j;
			}
		}
	}
	
	while (front < back) {
		int row = rowStore[front];
		int col = colStore[front++];
		
		for (k = 0; k < 4; k++) {
			int rowTemp = row + rowDirection[k];
			int colTemp = col + colDirection[k];
			if (!box[rowTemp][colTemp] && rowTemp >= 0 && rowTemp < N
							  		   && colTemp >= 0 && colTemp < M) {
				box[rowTemp][colTemp] = box[row][col] + 1;
				rowStore[back] = rowTemp;
				colStore[back++] = colTemp;
			}
		}
	}		
	
	if (checkClear()) {
		for (i = 0; i < N; i++)
			qsort(box[i], M, sizeof(int), compare);
			
		int max = box[0][0];
		for (i = 1; i < N; i++)
			max = (max > box[i][0]) ? max : box[i][0];
			
		printf("%d\n", max - 1);
	}
	else printf("-1\n");
}
