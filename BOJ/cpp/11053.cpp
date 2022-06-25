#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int N, A[1001]; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	int dp[1001], max; dp[0] = 1;
	for (int i = 1; i < N; i++) {
		max = 0;
		for (int j = i - 1; j >= 0; j--)
			if (A[j] < A[i]) max = max > dp[j] ? max : dp[j];
		dp[i] = max + 1;
	}
	sort(dp, dp + N);
	printf("%d\n", dp[N - 1]);
}

