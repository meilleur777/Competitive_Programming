#include <stdio.h>

int GCD(int a, int b) {
	if (!(a % b)) return b;
	else return (GCD(b, a % b));
}

int main() {
	int N, fring; scanf("%d %d", &N, &fring);	
	for (int i = 1; i < N; i++) {
		int nring, g; scanf("%d", &nring);
		g = GCD(fring, nring);
		printf("%d/%d\n", fring / g, nring / g);
	}
}

