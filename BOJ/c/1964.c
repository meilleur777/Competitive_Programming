#include <stdio.h>

/*5 + 2*3+1 + 3*3+1 ...*/

int main() {
	int N; scanf("%d", &N);
	printf("%d", (N + 4 + (N * (N + 1) / 2 - 1) * 3) % 45678);
}
