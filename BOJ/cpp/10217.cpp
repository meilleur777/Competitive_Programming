#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define INF 0x3F3F3F3F
using namespace std;

/*정해진 티켓비용 내에서 가장 빠른 경로를 찾아야 한다.
가장 단순한 방법으로는 모든 지원비용(0~10000)에 대해서 다익스트라 알고리즘을
사용해보는 것이다. 이때 memoization을 이용해 시간을 줄일 수 있지 않을까?
dp[a][b] = a까지 b원 사용하여 걸리는 최소 시간
		 = a까지 1~b-1원 사용하여 걸리는 최소 시간 중 최소 or
		   a 직전 도시까지 b-k원 사용하여 걸리는 최소 시간 + 전도시->a 시간
어차피 가능한 경로들을 모두 탐색해야 하기 때문에 우선순위 큐를 사용하지 않아도 될 것같다.

50%에서 시간 초과 -> q에 너무 많은 것을 큐에 담고 있는가?
만일 현재 시행보다 더 좋은 시행이 있었을 경우(dp를 통해 확인)
이번 시행을 즉시 중단한다는 조건을 통해 통과되었다.
*/

typedef struct {
	int end, price, time;
} edge;

typedef struct {
	int now, nowtime, nowcost;
} city;

int dp[101][10001];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		vector<edge> edges[101];
		int N, M, K; scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; i++) {
			int u, v, c, d; scanf("%d %d %d %d", &u, &v, &c, &d);
			edges[u].push_back({ v, c, d });
		}

		memset(dp, 0x3F, sizeof(dp));
		dp[1][0] = 0;
		queue<city> q;
		q.push({ 1, 0, 0 });
		while (!q.empty()) {
			city node = q.front(); q.pop();
			if (dp[node.now][node.nowcost] < node.nowtime) continue;

			for (auto i : edges[node.now]) {
				int nextcost = node.nowcost + i.price; 
				if (nextcost > M) continue;
				if (dp[i.end][nextcost] > dp[node.now][node.nowcost] + i.time) {
					dp[i.end][nextcost] = dp[node.now][node.nowcost] + i.time;
					q.push({ i.end, dp[i.end][nextcost], node.nowcost + i.price });

					for (int j = nextcost + 1; j <= M; j++) {
						if (dp[i.end][nextcost] < dp[i.end][j]) 
							dp[i.end][j] = dp[i.end][nextcost];
					}
				}
			}
		}

		if (dp[N][M] == INF) printf("Poor KCM\n");
		else printf("%d\n", dp[N][M]);
	}
}

