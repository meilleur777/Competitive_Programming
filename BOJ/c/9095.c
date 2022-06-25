#include <stdio.h>

int main() {
	int i, n, T;
	int dp[10] = { 0, 1, 2, 4, };
	scanf("%d", &T);
	
	for (i = 4; i < 11; i++) 
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		
	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	
	return 0;
}
