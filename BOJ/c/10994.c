#include <stdio.h>
#include <string.h>

char arr[500][500];

void rec(int row, int col, int N) {
	if (N == 1) { arr[row][col] = '*'; return; }
	
	int k = 1 + 4 * (N - 1);
	for (int i = 0; i < k; i++) arr[row][col + i] = '*';
	for (int i = 1; i < k - 1; i++) {
		arr[row + i][col] = '*';
		arr[row + i][col + k - 1] = '*';
	}
	for (int i = 0; i < k; i++) arr[row + k - 1][col + i] = '*';
    
	rec(row + 2, col + 2, N - 1);
}

int main() {
	memset(arr, ' ', sizeof(arr));
	int N; scanf("%d", &N);
	int k = 1 + 4 * (N - 1);
    
	rec(0, 0, N);	
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

