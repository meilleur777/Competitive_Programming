#include <stdio.h>
#define NUM 1000000007

/*use exponentiation by squaring*/

typedef unsigned long long ull;

int main() {
	while (1) {
	ull N; scanf("%lld", &N);
	ull A = 1, B = 1, C;
	for (ull i = 2; i < N; i++) {
		C = (A % NUM + B % NUM) % NUM;
		A = B % NUM;
		B = C;
	}
	printf("%d\n", C);
	}
}

