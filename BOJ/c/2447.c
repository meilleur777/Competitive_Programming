#include <math.h>
#include <stdio.h>
#include <string.h>

char arr[6600][6600];

void fractal(int x, int y, int k) {
	if (!k) { arr[x][y] = '*'; return; }
	int n = pow(3, k - 1);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			fractal(n * i + x, n * j + y, k - 1); 
		}
	}
}

int main() {
    memset(arr, ' ', sizeof(arr));
	int n, k = 0; scanf("%d", &n);
	int m = n;
    for (k = 0; m != 0; m /= 3, k++);
	fractal(0, 0, k);
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
