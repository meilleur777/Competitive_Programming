#include <stdio.h>

/*LCM(a, b) = a * b / GCD(a, b)*/

int GCD(int a, int b) {
	if (!b) return a;
	else return GCD(b, a % b);	
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int A, B; scanf("%d %d", &A, &B);
		printf("%d\n", A * B / GCD(A, B));
	}
}

