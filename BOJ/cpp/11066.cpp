#include <stdio.h>
#define INF 0x3F3F3F3F
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int K; scanf("%d", &K);
		int dp[501][501] = { 0 }, sum[501] = { 0 }, cost[501];
		for (int i = 1; i <= K; i++) {
			scanf("%d", &cost[i]);
			sum[i] = sum[i - 1] + cost[i];
		}
		for (int page = 1; page < K; page++) {
			for (int start = 1; start + page <= K; start++) {
				int end = start + page;
				dp[start][end] = INF;
				for (int mid = start; mid < end; mid++) {
					dp[start][end] = MIN(dp[start][end],
					dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
				}
			}			
		}
		printf("%d\n", dp[1][K]);
	}
}

