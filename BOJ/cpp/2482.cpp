#include <stdio.h>
#define NUM 1000000003

/*Dynamic Programming
dp[a][b] -> a가지 색 중 b개를 선택한 경우의 수

dp[N][K] => 첫 번째 색을 칠했는지 아닌지에 대한 고려가 필요하다.
우선 마지막 색을 칠하지 않을 경우 첫번째 색의 칠 여부는 상관없다. 즉 +dp[N - 1][K]
마지막 색을 칠할 경우, 2~N-2번째 색 중 K - 1개를 고른 경우의 수를 더해주어야 한다.
이 때의 경우의 수는 N-3가지 색 중 K - 1개를 고른 경우의 수와 같을 것이다.
즉 dp[N - 3][K - 1]을 더해준다.  
*/

int dp[1001][1001] = { 0 };

int main() {
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	} 
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = dp[i - 1][j] % NUM + dp[i - 2][j - 1] % NUM;
			dp[i][j] %= NUM;
		}
	}
	printf("%d\n", (dp[N - 3][K - 1] + dp[N - 1][K]) % NUM);
}

