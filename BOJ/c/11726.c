#include <stdio.h>

int main() {
	int i, n; scanf("%d", &n);
	int dp[1001] = { 0, 1, 2 };
	for (i = 3; i <= n; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	printf("%d", dp[n] % 10007);
}
