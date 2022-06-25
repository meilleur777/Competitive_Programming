#include <stdio.h>

int N, M;
int vis[501][501] = { 0 };
int arr[501][501];
int max = -1;
int rowdir[4] = { 1, -1, 0, 0 };
int coldir[4] = { 0, 0, 1, -1 };

void nav(int row, int col, int cnt, int sum) {
	if (cnt == 4) {
		max = max > sum ? max : sum;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int trow = row + rowdir[k];
		int tcol = col + coldir[k];
		if (trow >= 0 && trow < N && tcol >= 0 
		 && tcol < M && !vis[trow][tcol]) {
			vis[trow][tcol] = 1;
			nav(trow, tcol, cnt + 1, sum + arr[trow][tcol]);
			vis[trow][tcol] = 0;
		}
	}
}

void spe(int row, int col) {
	int sum[4] = { 0 };
	int dir[4][4][2] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
						{{0, 1}, {1, 0}, {1, 1}, {2, 1}},
						{{0, 1}, {1, 0}, {1, 1}, {1, 2}}, 
						{{0, 0}, {1, 0}, {1, 1}, {2, 1}}};
	int trow[4][4], tcol[4][4];
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 4; i++) {
			trow[k][i] = row + dir[k][i][0];
			tcol[k][i] = col + dir[k][i][1];
		}
	}
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 4; i++) {
			if (trow[k][i] >= 0 && trow[k][i] < N && tcol[k][i] >= 0 && tcol[k][i] < M) {
				sum[k] += arr[trow[k][i]][tcol[k][i]];
			}
		}
	}
	for (int k = 0; k < 4; k++) if (sum[k] > max) max = sum[k];
}

int main() {
	int temp; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vis[i][j] = 1;
			nav(i, j, 1, arr[i][j]);
			vis[i][j] = 0;
			spe(i, j);
		}
	}
	printf("%d\n", max);
}
