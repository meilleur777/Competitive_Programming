#include <stdio.h>

int main() {
	int i, j, N, M, K; scanf("%d %d", &N, &M);
	int arr[301][301];
	
	int num;
	for (i = 0; i < N; i++) {
		arr[i][0] = 0;
		for (j = 1; j <= M; j++) {
			scanf("%d", &num);
			arr[i][j] = arr[i][j - 1] + num;
		}
	}
	
	scanf("%d", &K); 
	for (i = 0; i < K; i++) {
		int a, b, c, d, sum = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (j = a - 1; j < c; j++) 
			sum += arr[j][d] - arr[j][b - 1];
		printf("%d\n", sum);
	}
}
