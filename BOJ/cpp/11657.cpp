#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3F3F3F3F3F3F3F3F
using namespace std;

/*edge의 최소 가중치 -10000 * 500 * 6000번 반복 -> int형 underflow 발생
즉 음수 사이클을 판정할 수 없다. 따라서 long long으로 선언*/

long long cost[501]; 
vector<pair<int, int> > edges[501];

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int A, B, C; scanf("%d %d %d", &A, &B, &C);
		edges[A].push_back({B, C});
	}
	
	memset(cost, 0x3F, sizeof(cost));
	cost[1] = 0;
	
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto k : edges[j]) {
				int nextnode = k.first, weight = k.second;
				if (cost[j] != INF && cost[nextnode] > cost[j] + weight) 
					cost[nextnode] = cost[j] + weight;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (auto j : edges[i]) {
			int nextnode = j.first, weight = j.second;
			if (cost[i] != INF && cost[nextnode] > cost[i] + weight) {
				printf("-1\n");
				return 0;
			}
		}
	}
	
	for (int i = 2; i <= N; i++) {
		if (cost[i] == INF) printf("-1\n");
		else printf("%lld\n", cost[i]);
	}	
}

