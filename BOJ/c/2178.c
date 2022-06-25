#include <stdio.h>
#include <stdlib.h>

int N, M;
int check[101][101] = { 0 };
int maze[101][101];
int rowdir[4] = { 1, -1, 0, 0 };
int coldir[4] = { 0, 0, 1, -1 };
int rowqu[10001], colqu[10001];
int front = 0, back = 0;

int main() {
	int i, j, result; scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	
	rowqu[back] = 0;
	colqu[back++] = 0;
	check[0][0] = 1;	
	while (front < back) {
		int row = rowqu[front];
		int col = colqu[front++];
		int k;
		
		if (row == N - 1 && col == M - 1) {
			result = check[row][col];
			break;
		}
		
		for (k = 0; k < 4; k++) {
			int trow = row + rowdir[k];
			int tcol = col + coldir[k];
			if (trow >= 0 && trow < N && tcol >= 0 && tcol < M) {
				if (maze[trow][tcol] == 1 && !check[trow][tcol]) {
					check[trow][tcol] = check[row][col] + 1;
					rowqu[back] = trow; colqu[back++] = tcol; 
				}
			}
		}
	}
	printf("%d\n", result);
}
