#include <stdio.h>
#include <string.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 
 
/*건물 a를 짓기 위해 그 자식 건물들을 모두 지어야 한다.
즉 건물 a를 짓는 데 걸리는 최소 시간
= MAX(건물 a의 자식들을 짓는데 걸리는 최소 시간) + a를 짓는 시간*/

/*함수를 통해 Topdown 방식으로 구현해보았으나 호출이 너무 많이 일어나 메모리 초과 발생*/
/*약간의 최적화를 통해 통과되었다.*/

int minT[1001];
int time[1001]; /*건물을 짓는 데 소요되는 시간*/
int childNum[1001];
int child[1001][1001]; /*child[k] 건물 k를 짓는 데 필요한 건물들*/

int solve(int W) {
	if (minT[W] != -1) return minT[W];
	if (!childNum[W]) return minT[W] = time[W];
	int min = -1;
	for (int i = 0; i < childNum[W]; i++) {
		if (minT[child[W][i]] != -1) min = MAX(min, time[W] + minT[child[W][i]]);
		else min = MAX(min, time[W] + solve(child[W][i]));
	}
	return minT[W] = min;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N, K, W; scanf("%d %d", &N, &K);
		memset(minT, -1, sizeof(minT));
		memset(childNum, 0, sizeof(childNum));
		for (int j = 1; j <= N; j++) scanf("%d", &time[j]);
		for (int j = 0; j < K; j++) {
			int X, Y; scanf("%d %d", &X, &Y);
			child[Y][childNum[Y]++] = X;
		}
		scanf("%d", &W);
		printf("%d\n", solve(W));	
	}
}

