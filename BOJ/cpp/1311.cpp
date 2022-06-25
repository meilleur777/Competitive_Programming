#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/*Dynamic Programming Using Bitfield*/

int N, cost[21][21];
int dp[21][1050000]; 

int DFS(int now, int visit) {
	if (visit == ((1 << N) - 1)) return 0;
	else if (dp[now][visit] != -1) return dp[now][visit];
	
	dp[now][visit] = INF;
	for (int i = 0; i < N; i++) {
		if (!(visit & (1 << i))) {
			dp[now][visit] = MIN(dp[now][visit], 
			DFS(now + 1, visit | (1 << i)) + cost[now][i]);
		}
	}
	return dp[now][visit];
}

int main() {
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &cost[i][j]);
	printf("%d", DFS(0, 0));
}

