#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/*Floyd-Warshall Algorithm*/

int main() {
	int cost[401][401];
	int V, E; scanf("%d %d", &V, &E);
	memset(cost, 0x3F, sizeof(cost));	
	for (int i = 0; i < E; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = c;
	}
	for (int i = 1; i <= V; i++) cost[i][i] = 0;
	
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (cost[j][k] > cost[j][i] + cost[i][k]) 
					cost[j][k] = cost[j][i] + cost[i][k];
			}
		}
	}	
	
	int answer = INF;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) continue;
			answer = MIN(answer, cost[i][j] + cost[j][i]);
		}
	}
	
	if (answer == INF) printf("-1\n");	
	else printf("%d\n", answer);
}

