#include <stdio.h>

int main() {
	int i, N, M, x, start, end;
	scanf("%d %d", &N, &M);
	int number[100001] = { 0 };
	
	for (i = 1; i <= N; i++) {
		scanf("%d", &x);
		number[i] = number[i - 1] + x;
	}
	
	for (i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		printf("%d\n", number[end] - number[start - 1]);
	}
	
	return 0;
}
