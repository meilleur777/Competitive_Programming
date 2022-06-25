#include <stdio.h>
#define NUM 10000000000000000 /*10^16*/

long long dp1[101][101];
long long dp2[101][101] = { 0 };

int main() {
	int n, m; scanf("%d %d", &n, &m);
	
	dp1[1][0] = 1; dp1[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp1[i][0] = 1;
		dp1[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp2[i][j] = dp2[i - 1][j - 1] + dp2[i - 1][j];
			dp1[i][j] = dp1[i - 1][j - 1] + dp1[i - 1][j];
			if (dp1[i][j] >= NUM) {
				dp2[i][j] += dp1[i][j] / NUM;
				dp1[i][j] %= NUM;
			}
		}
	}
	
	if (!dp2[n][m]) printf("%lld", dp1[n][m]);
	else printf("%lld%016lld", dp2[n][m], dp1[n][m]);
}

