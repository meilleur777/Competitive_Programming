#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

int dp[2][100001];
int arr[2][100001];

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n; scanf("%d", &n);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &arr[j][k]);
			}
		}
		
		
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		
		for (int j = 2; j < n; j++) {
			dp[0][j] = arr[0][j] + MAX(dp[1][j - 1], dp[1][j - 2]);
			dp[1][j] = arr[1][j] + MAX(dp[0][j - 1], dp[0][j - 2]);
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				printf("%d ", dp[j][k]);
			}
			printf("\n");
		}
		printf("%d\n", MAX(dp[0][n - 1], dp[1][n - 1]));
	}
}
