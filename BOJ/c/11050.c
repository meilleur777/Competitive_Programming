#include <stdio.h>

/*이항 계수 
if 0 <= k <= n, n!/k!(n - k)!
if k < 0 or k > n, 0*/ 

int main() {
	int i, N, K;
	scanf("%d %d", N, K);
	int result = 1;
	for (i = 0; i < K; i++) result *= N - i;
	for (i = 1; i <= K; i++) result /= i;
	printf("%d", result);
	
	return 0;
}
