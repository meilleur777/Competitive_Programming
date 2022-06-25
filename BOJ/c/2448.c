#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*k == 3일때 주의*/
bool arr[3300][3300] = { false }; 

void rec(int srow, int scol, int N) {
	if (N == 3) {
		arr[srow][scol + 2] = true;
		arr[srow + 1][scol + 1] = true;
		arr[srow + 1][scol + 3] = true;
		for (int i = 0; i < 5; i++) arr[srow + 2][scol + i] = true;
		return;
	}
	N /= 2;	
	rec(srow, scol + N, N);
	rec(srow + N, scol, N);
	rec(srow + N, scol + N * 2, N);
}


int main() {
	int N; scanf("%d", &N);
	rec(0, 0, N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			if (arr[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

