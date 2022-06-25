#include <stdio.h>
#include <string.h>

int main() {
	int n, m, r, item[31], dp[101][101]; 
	scanf("%d %d %d", &n, &m, &r);
	memset(dp, 0x3F, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &item[i]);
		dp[i][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (c < dp[a][b]) dp[a][b] = c;
		if (c < dp[b][a]) dp[b][a] = c;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][k] > dp[j][i] + dp[i][k]) dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}
	
	int result = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) if (dp[i][j] <= m) sum += item[j];
		result = result > sum ? result : sum;
	}
	printf("%d\n", result);
}

