#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

pair<int, int> stuff[101];	
int dp[101][100001] = { 0 };

int main() {
	int N, K, max = - 1; scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		int W, V; scanf("%d %d", &W, &V);
		stuff[i] = make_pair(W, V);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= stuff[i].first) {
				dp[i][j] = MAX(dp[i - 1][j], dp[i][j - stuff[i].first] + stuff[i].second);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	sort(dp[N], dp[N] + K + 1);
	printf("%d\n", dp[N][K]);
}
