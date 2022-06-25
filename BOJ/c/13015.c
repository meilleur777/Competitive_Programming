#include <stdio.h>
#include <stdbool.h>

bool arr[500][500] = { false };

int main() {
	int N; scanf("%d", &N);
	int depth = 2 * N - 1;
	int width = 4 * N - 3;
	for (int i = 0; i < N; i++) {
		arr[0][i] = true; 
		arr[0][width - 1 - i] = true;	
		arr[depth - 1][i] = true;
		arr[depth - 1][width - 1 - i] = true;
	}
	for (int i = 1; i < N - 1; i++) {
		arr[i][i] = true;
		arr[i][i + N - 1] = true;
		arr[i][width - 1 - i] = true;
		arr[i][width - i - N] = true;
	}
	for (int i = 1; i < N; i++) {
		arr[depth - i][i - 1] = true;
		arr[depth - i][i + N - 2] = true;
		arr[depth - i][width - i] = true;
		arr[depth - i][width - i - N + 1] = true;
	}
	arr[N - 1][N - 1] = true;
	arr[N - 1][2 * N - 2] = true;
	arr[N - 1][3 * N - 3] = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < width - i; j++) {
			if (arr[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for (int i = N; i < depth; i++) {
		for (int j = 0; j < width - depth + i + 1; j++) {
			if (arr[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

