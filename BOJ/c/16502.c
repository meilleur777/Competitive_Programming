#include <stdio.h>

int main() {
	int i, j, k, timeLimit, M;
	double paths[4][4] = { 0 }, dp[4][10];
	dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 25.f;
	scanf("%d %d", &timeLimit, &M);
	
	for (i = 0; i < M; i++) {
		char a, b; double p;
		scanf(" %c %c %lf", &a, &b, &p);
		paths[a - 'A'][b - 'A'] = p;
	}
	
	for (i = 1; i <= timeLimit; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++)	
				dp[k][i] += dp[j][i - 1] * paths[j][k];
		}
	}
	
	for (i = 0; i < 4; i++) printf("%.4lf\n", dp[i][timeLimit]);
}
