#include <stdio.h>

int main() {
	int n, k; scanf("%d %d", &n, &k);
	int coin[101] = { 0 }, dp[10001] = { 1 };
	for (int i = 0; i < n; i++) scanf("%d", &coin[i + 1]);
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}		
	}
	printf("%d\n", dp[k]);
}

