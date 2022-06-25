#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool dp[2010][2010] = { false };

int main() {
	int N, arr[2010]; scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;
		int j = 1;
		while (i - j > 0 && i + j <= N) {
			dp[i - j][i + j] = dp[i - j + 1][i + j - 1] && (arr[i - j] == arr[i + j]);
			if (!dp[i - j][i + j]) break;
			j++;			
		}
	}
	
	for (int i = 1; i < N; i++) {
		dp[i][i + 1] = (arr[i] == arr[i + 1]);
	}
	
	for (int s = 1, e = 2; e <= N; s++, e++) {
		int j = 1;
		while (s - j > 0 && e + j <= N) {
			dp[s - j][e + j] = dp[s - j + 1][e + j - 1] && (arr[s - j] == arr[e + j]);
			if (!dp[s - j][e + j]) break;
			j++;
		}
	}
	
	int M; scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int S, E; scanf("%d %d", &S, &E);
		printf("%d\n", dp[S][E]);
	}
}

