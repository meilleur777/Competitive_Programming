#include <stdio.h>

/*Matrix Multiplication*/

int main() {
	int N, M, K, A[101][101], B[101][101], C[101][101];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);	
		}	
	}
	
	scanf("%d %d", &M, &K);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	for (int l = 0; l < N; l++) {
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < M; j++) {
				C[l][i] += A[l][j] * B[j][i];
			}
			printf("%d ", C[l][i]);
		}
		printf("\n");
	}	
}

