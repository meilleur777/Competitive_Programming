#include <stdio.h>

int solve(int M, int N, int x, int y) {
	int ans = x;
    if (y == N) y = 0;
	for ( ; ans <= M * N; ans += M) if (ans % N == y) return ans;
	return -1;
}

int main() {
	int i, T; scanf("%d", &T);
	for (i = 0; i < T; i++) {
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);
        printf("%d\n", solve(M, N, x, y));
	}
}
