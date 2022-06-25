#include <stdio.h>

int main() {
	int i, n, dp[1001] = { 0, 1 }; scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		if (i % 2) dp[i] = (dp[i - 1] * 2 - 1) % 10007;
		else dp[i] = (dp[i - 1] * 2 + 1) % 10007;
	}
	printf("%d\n", dp[n]);
}
