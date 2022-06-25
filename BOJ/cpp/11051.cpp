#include <stdio.h>
#define NUM 10007

int dp[1001][1001] = { 0 };

int main() {
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1, dp[i][i] = 1;
		for (int j = 1; j < i; j++) 
			dp[i][j] = (dp[i - 1][j - 1] % NUM + dp[i - 1][j] % NUM) % NUM;
	}
	printf("%d\n", dp[N][K]);
}

