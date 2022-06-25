#include <math.h>
#include <stdio.h>

int count[2] = { 0 }, paper[129][129];

void cut(int srow, int scol, int N) {
	int i, j, tcount[2] = { 0 };

	for (i = srow; i < srow + N; i++) {
        for (j = scol; j < scol + N; j++) {
            tcount[paper[i][j]]++;
        }
    }

	if (!tcount[0]) count[1]++; 
	else if (!tcount[1]) count[0]++; 
	else {
        N /= 2;
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
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
    for (i = 0; i < 2; i++) printf("%d\n", count[i]);
}
