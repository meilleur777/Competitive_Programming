#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF 0x3F3F3F3F

/*Traveling Salesman Problem with Backtracking*/

int S, N, answer = INF;
int weight[11][11];
bool visit[11] = { false };

void tsp(int node, int cost, int count) {
	if (count == N - 1 && weight[node][S] != INF) {
		answer = MIN(answer, cost + weight[node][S]);
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		if (weight[node][i] != INF && !visit[i]) {
			visit[i] = true;
			tsp(i, cost + weight[node][i], count + 1);
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &weight[i][j]);
			if (!weight[i][j] && i != j) weight[i][j] = INF;
		}
	}
	for (int i = 1; i <= N; i++) {
		S = i;
		visit[i] = true;
		tsp(i, 0, 0);
		visit[i] = false;
	}
	printf("%d\n", answer);
}

