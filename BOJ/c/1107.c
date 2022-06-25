#include <stdio.h>
#include <string.h>
#include <math.h>

int num[10];

int pos(int T) {
	int len = 0;
	if (!T) return num[0] ? 0 : 1;
	for (; T > 0; T /= 10, len++) if (num[T % 10]) return 0;
	return len;
}

int solve(int N) {
	int i, dig, res = 1000001;
	for (i = 0; i < 1000001; i++) 
		if (dig = pos(i)) res = res < dig + abs(N - i) ? res : dig + abs(N - i);
	return res < abs(N - 100) ? res : abs(N - 100);
}

int main() {	
	memset(num, 0, sizeof(int) * 10);
	int i, N, M; scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		int x; scanf("%d", &x);
		num[x] = 1;
	}
	printf("%d\n", solve(N));
}
