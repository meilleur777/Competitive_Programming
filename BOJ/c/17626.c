/*Four Squares*/

#include <stdio.h>
#include <math.h>
#define min(a, b) (a < b) ? a : b

int main() {
	int i, k;
	int n, dp[50001] = { 0 };
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (k = 2; pow(k, 2) <= i; k++) {
			int r = pow(k, 2);
			dp[i] = min(dp[i], dp[i - r] + 1);
		}
	}
	
	printf("%d", dp[n]);
	
	return 0;
}
