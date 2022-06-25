#include <stdio.h>

int N, M, H, front = 0, back = 0;
int axiDirection[6] = { 1, -1, 0, 0, 0, 0 };
int rowDirection[6] = { 0, 0, 1, -1, 0, 0 };
int colDirection[6] = { 0, 0, 0, 0, 1, -1 };
int axiStore[1000001], rowStore[1000001], colStore[1000001];
int box[101][101][101];

int checkClear() {
	int i, j, k;
	for (i = 0; i < H; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				if (!box[i][j][k]) return 0;
			}
		}
	}
	return 1;
}

int main() {
	int i, j, k; scanf("%d %d %d", &M, &N, &H);
	for (i = 0; i < H; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == 1) {
					axiStore[back] = i;
					rowStore[back] = j;
					colStore[back++] = k;
				}
			}
		}
	}
	
	while (front < back) {
		int axi = axiStore[front];
		int row = rowStore[front];
		int col = colStore[front++];
		
		for (k = 0; k < 6; k++) {
			int axiTemp = axi + axiDirection[k];
			int rowTemp = row + rowDirection[k];
			int colTemp = col + colDirection[k];
			if (axiTemp >= 0 && axiTemp < H && rowTemp >= 0 && rowTemp < N
			 && colTemp >= 0 && colTemp < M && !box[axiTemp][rowTemp][colTemp]) {
				box[axiTemp][rowTemp][colTemp] = box[axi][row][col] + 1;
				axiStore[back] = axiTemp;
				rowStore[back] = rowTemp;
				colStore[back++] = colTemp;
			}
		}
	}		
	
	if (checkClear()) {
		int max = box[0][0][0];
		for (i = 0; i < H; i++) {
			for (j = 0; j < N; j++) {
				for (k = 0; k < M; k++) {
					max = max > box[i][j][k] ? max : box[i][j][k];			
				}
			}
		}	
		printf("%d\n", max - 1);
	}
	else printf("-1\n");	
}
