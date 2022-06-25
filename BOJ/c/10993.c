#include <math.h>
#include <stdio.h>
#include <string.h>

char arr[5000][5000];

void rec(int row, int col, int N) {
	if (N == 2) {
		for (int i = col; i < col + 5; i++) arr[row][i] = '*';
		for (int i = col + 1; i < col + 4; i++) arr[row + 1][i] = '*';
		arr[row + 2][col + 2] = '*';
		return;
	}
	else if (N % 2) {
		int k = 4 * (pow(2, N - 1) - 1) + 1;
		int c = (k + 1) / 2;
		
		arr[row][col + c - 1] = '*';
		for (int i = 1; i < c; i++) {
			arr[row + i][col + c - i - 1] = '*';
			arr[row + i][col + c + i - 1] = '*';
		}
		for (int i = 0; i < k; i++) {
			arr[row + c - 1][col + i] = '*';
		}
		
		rec(row + c / 2, col + c / 2 + 1, N - 1);
	}
	else {
		int k = 4 * (pow(2, N - 1) - 1) + 1;
		int c = (k + 1) / 2;
		
		for (int i = 0; i < k; i++) {
			arr[row][col + i] = '*';
		}
		for (int i = 1; i < c; i++) {
			arr[row + i][col + i] = '*';
			arr[row + i][col + 2 * c - i - 2] = '*';
		}
		arr[row + c][col + c - 1] = '*';
		
		rec(row + 1, col + c / 2 + 1, N - 1);
	}
}

int main() {
	int N; scanf("%d", &N);
	if (N == 1) { printf("*\n"); return 0; }
	memset(arr, ' ', sizeof(arr));
	rec(0, 0, N);
	
	int k = 4 * (pow(2, N - 1) - 1) + 1;
	int c = (k + 1) / 2;
	
	if (N % 2) {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c + i; j++) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < k - i; j++) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
}

