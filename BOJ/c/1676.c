#include <stdio.h>
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

int main() {
	int i;
	int N, min, temp, count2 = 0, count5 = 0, dp[501] = { 0 };
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++) {
		temp = i;
		while (!(temp % 10)) { temp /= 10; dp[i]++; }
		while (!(temp % 2)) { temp /= 2; count2++; }
		while (!(temp % 5)) { temp /= 5; count5++; }
		min = MIN(count2, count5);
		dp[i] += dp[i - 1] + min; 
		count2 -= min; count5 -= min;
	}
	
	printf("%d", dp[N]);
	
	return 0;
}
