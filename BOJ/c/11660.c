#include <stdio.h>

int main() {
	int N, M; scanf("%d %d", &N, &M);
	
	int arr[1025][1025] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			int x; scanf("%d", &x);
			arr[i][j] = arr[i][j - 1] + x;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2, sum = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1 - 1; j < x2; j++) sum += arr[j][y2] - arr[j][y1 - 1];
		printf("%d\n", sum);
	}
}

