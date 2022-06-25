#include <math.h>
#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int song[100001];
int dp[5][5][100001];

/*Dynamic Programming
dp[a][b][c] -> c번째 시행을 마쳤고, 왼쪽 발은 a에, 오른쪽 발은 b에 있을 때의 cost 최소값 
dp[a][b][c] = 만일 두 발 중 하나가 다음 시행과 겹친다면, cost = 1
			  그 이외의 경우에는 두 발을 모두 위치로 옮겨보고 그 중 최소값을 고른다.
초기값을 매우 큰 값으로 설정하여(개념적으로는 무한), 가능하지 않은 경우는 제외되도록 한다. 
c가 전체 시행횟수일 때, 20가지 경우가 있을 것인데, 그 중 최소값을 고르면 된다.*/

int main() {
	int a, N = 1;
	while (1) {
		scanf("%d", &a);
		if (!a) break;
		song[N++] = a;
	}
	
	memset(dp, 0x3F, sizeof(dp));
	dp[0][0][0] = 0;
	dp[song[1]][0][1] = 2;
	dp[0][song[1]][1] = 2;
	
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (j == song[i] || k == song[i]) dp[j][k][i] = MIN(dp[j][k][i], dp[j][k][i - 1] + 1);
				else {
					if (!j) dp[song[i]][k][i] = MIN(dp[song[i]][k][i], dp[j][k][i - 1] + 2);
					else if (abs(j - song[i]) == 1 || abs(j - song[i]) == 3) 
						dp[song[i]][k][i] = MIN(dp[song[i]][k][i], dp[j][k][i - 1] + 3);
					else if (abs(j - song[i]) == 2) 
						dp[song[i]][k][i] = MIN(dp[song[i]][k][i], dp[j][k][i - 1] + 4);

					if (!k) dp[j][song[i]][i] = MIN(dp[j][song[i]][i], dp[j][k][i - 1] + 2);
					else if (abs(k - song[i]) == 1 || abs(k - song[i]) == 3) 
						dp[j][song[i]][i] = MIN(dp[j][song[i]][i], dp[j][k][i - 1] + 3);
					else if (abs(k - song[i]) == 2) 
						dp[j][song[i]][i] = MIN(dp[j][song[i]][i], dp[j][k][i - 1] + 4);
				}
			}
		}
	}
	
	int min = INF;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j || (i != song[N - 1] && j != song[N - 1])) continue;
			min = MIN(min, dp[i][j][N - 1]);
		}
	} 
	printf("%d\n", min);
}

