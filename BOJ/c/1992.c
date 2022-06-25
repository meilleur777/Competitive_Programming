#include <stdio.h>

int video[65][65];

void compress(int srow, int scol, int N) {
	int i, j, tcount[2] = { 0 };
	
	for (i = srow; i < srow + N; i++) {
		for (j = scol; j < scol + N; j++) {
			tcount[video[i][j]]++;
		}
	}
	
	if (!tcount[0]) printf("1");
	else if (!tcount[1]) printf("0");
	else {
		N /= 2;
		printf("(");
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				compress(srow + i * N, scol + j * N, N);
			}
		}
		printf(")");
	}
}

int main() {
	int i, j, N; scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%1d", &video[i][j]);
		}
	}
	compress(0, 0, N);	
}
