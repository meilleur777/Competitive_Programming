#include <stdio.h>

int N, count = 0; 
int map[17][17];

/*파이프가 항상 오른쪽 아래로만 이동할 수 있기 때문에 파이프의 회전은 일어나지 않는다.
파이프가 이동한 후 원래 파이프의 자리와 이동한 파이프의 자리는 무조건 한 자리 겹친다.
따라서 파이프 앞부분의 좌표만 조사하면 된다.*/

void DFS(int row1, int col1, int row2, int col2) {
	if (row2 == N - 1 && col2 == N - 1) { count++; return; }
	if (row1 == row2 && col2 == col1 + 1) {		/*가로*/
		if (col2 + 1 < N && !map[row2][col2 + 1]) DFS(row2, col2, row2, col2 + 1);
		if (col2 + 1 < N && row2 + 1 < N 
		&& !map[row2][col2 + 1] && !map[row2 + 1][col2] && !map[row2 + 1][col2 + 1]) {
			DFS(row2, col2, row2 + 1, col2 + 1);
		}
	}
	else if (row1 + 1 == row2 && col1 == col2) {		/*세로*/
		if (row2 + 1 < N && !map[row2 + 1][col2]) DFS(row2, col2, row2 + 1, col2);
		if (row2 + 1 < N && col2 + 1 < N 
		&& !map[row2][col2 + 1] && !map[row2 + 1][col2] && !map[row2 + 1][col2 + 1]) {
			DFS(row2, col2, row2 + 1, col2 + 1);
		}
	}
	else { /*대각선*/
		if (col2 + 1 < N && !map[row2][col2 + 1]) DFS(row2, col2, row2, col2 + 1);
		if (row2 + 1 < N && col2 + 1 < N 
		&& !map[row2][col2 + 1] && !map[row2 + 1][col2] && !map[row2 + 1][col2 + 1]) {
			DFS(row2, col2, row2 + 1, col2 + 1);
		}
		if (row2 + 1 < N && !map[row2 + 1][col2]) DFS(row2, col2, row2 + 1, col2);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	DFS(0, 0, 0, 1);
	printf("%d\n", count);
}

