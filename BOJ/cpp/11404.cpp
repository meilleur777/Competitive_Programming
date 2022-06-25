#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int dp[101][101];
	memset(dp, 0x3F, sizeof(dp));
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	
	for (int i = 0; i < m ; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (c < dp[a][b]) dp[a][b] = c;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][k] > dp[j][i] + dp[i][k]) {
					dp[j][k] = dp[j][i] + dp[i][k];
				}
			}
		}
	}
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INF) printf("0 ");
			else printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

