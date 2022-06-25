#include <stdio.h>

/*피사노 주기*/
/*m > 2인 경우에 k(m)은 짝수이다.
임의의 짝수 정수 n > 2에 대해서, k(m) = n인 m이 항상 존재한다.
k(m) <= m^2 - 1
k(2^n) = 3*2^(n-1)
k(5^n) = 4*5^n
k(2*5^n) = 6*n
n > 2일때, k(10^n) = 15*10^(n-1)*/

int main() {
	int P; scanf("%d", &P);
	while (P--) {
		int N, M; scanf("%d %d", &N, &M);
		int A = 1, B = 1, C, count = 0;
		do {
			C = ((A % M) + (B % M)) % M;
			A = B;
			B = C;
			count++;
		} while (A != 1 || B != 1);
		printf("%d\n", count);
	} 
}

