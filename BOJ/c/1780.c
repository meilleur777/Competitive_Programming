#include <stdio.h>

int count[3] = { 0 };
int paper[2200][2200];

void cut(int srow, int scol, int N) {
	int i, j, tcount[3] = { 0 };

	for (i = srow; i < srow + N; i++) {
		for (j = scol; j < scol + N; j++) {
			tcount[paper[i][j] + 1]++;
		}
	}

	if (!tcount[0] && !tcount[1]) {
		count[2]++; return;
	}
	else if (!tcount[1] && !tcount[2]) {
		count[0]++; return;
	}
	else if (!tcount[2] && !tcount[0]) {
		count[1]++; return;
	}
	else {
		N /= 3;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				cut(srow + i * N, scol + j * N, N);
			}
		}
	}
}

int main() {
	int i, j, N; scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	cut(0, 0, N);
	for (i = 0; i < 3; i++) printf("%d\n", count[i]);
}
