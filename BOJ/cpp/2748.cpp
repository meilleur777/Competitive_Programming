#include <stdio.h>

int main() {
	int N; scanf("%d", &N);
	unsigned long long dp[91] = { 0, 1, 1 };
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld\n", dp[N]);
}

