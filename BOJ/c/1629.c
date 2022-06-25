#include <stdio.h>

int C;

unsigned long long power(int x, int y) {
	if (!y) return 1;
    unsigned long long temp = power(x, y / 2) % C;
    temp = temp * temp % C;
	if ((y % 2) == 0) return temp;
	else return x * temp % C;
}

int main() {
	int A, B;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", power(A % C, B) % C);
}

