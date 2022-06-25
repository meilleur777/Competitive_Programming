#include <stdio.h>
#include <stdbool.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int N, res1 = 0, res2 = 0;
int map[11][11];
bool ld[30] = { false }, rd[30] = { false };

void DFS(int row, int col, int count, bool color) {
	if (col >= N) {
		if (col % 2) col = 0;
		else col = 1;
		row++;
	}
	if (row >= N) {
		if (color) res1 = MAX(res1, count);
		else res2 = MAX(res2, count);
		return;
	}
	
	if (map[row][col] && !ld[col - row + N - 1] && !rd[row + col]) {
		ld[col - row + N - 1] = true;
		rd[row + col] = true; 
		DFS(row, col + 2, count + 1, color);
		ld[col - row + N - 1] = false;
		rd[row + col] = false; 
	}
	DFS(row, col + 2, count, color);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	DFS(0, 0, 0, true);
	DFS(0, 1, 0, false);	
	printf("%d\n", res1 + res2); 
}

