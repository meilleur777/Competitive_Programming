#include <stdio.h>
#include <stdbool.h>
bool arr[400][400] = { false };

int solve(int row, int col, int N) {
	int depth = 3 + (N - 1) * 4;
	int width = 1 + (N - 1) * 4;
	if (N == 2) {
		for (int j = 0; j < width; j++) {
			arr[row][col + j] = true;
			arr[row + depth - 1][col + j] = true;
		}
		for (int j = 1; j < depth - 1; j++) {
			arr[row + j][col] = true;
			arr[row + j][col + width - 1] = true;
		}
		for (int j = 2; j < 5; j++) 
			arr[row + j][col + 2] = true;
		arr[row + 1][col + width - 1] = false;
		arr[row + 2][col + 3] = true;
	}
	else {
		for (int i = 0; i < width; i++) {
			arr[row][col + i] = true;
			arr[row + depth - 1][col + i] = true;
		}
		for (int i = 1; i < depth - 1; i++) {
			arr[row + i][col] = true;
			arr[row + i][col + width - 1] = true;
		}
		arr[row + 1][col + width - 1] = false;
		arr[row + 2][col + width - 2] = true;
		solve(row + 2, col + 2, N - 1);
	}
}

int main() {
	int N; scanf("%d", &N);
	if (N == 1) { printf("*\n"); return 0; }
	solve(0, 0, N);
	int depth = 3 + (N - 1) * 4;
	int width = 1 + (N - 1) * 4;
	for (int i = 0; i < depth; i++) {
		if (i == 1) printf("*\n"); continue;
		for (int j = 0; j < width; j++) {
			if (arr[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

