#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool rchk[10][10] = { false };
bool cchk[10][10] = { false };
bool bchk[4][4][10] = { false };
int map[10][10];

void DFS(int row, int col) {
	if (col == 9) {
		col = 0;
		row++;
	}
	if (row == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	
	if (!map[row][col]) {
		for (int i = 1; i <= 9; i++) {
			if (!rchk[row][i] && !cchk[col][i] && !bchk[row / 3][col / 3][i]) {
				rchk[row][i] = true;
				cchk[col][i] = true;
				bchk[row / 3][col / 3][i] = true;
				map[row][col] = i;
				DFS(row, col + 1);
				rchk[row][i] = false;
				cchk[col][i] = false;
				bchk[row / 3][col / 3][i] = false;
				map[row][col] = 0;
			}
		}		
	}
	else DFS(row, col + 1);
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j]) {
				rchk[i][map[i][j]] = true;
				cchk[j][map[i][j]] = true;
				bchk[i / 3][j / 3][map[i][j]] = true;
			}
		}
	}
	DFS(0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}

