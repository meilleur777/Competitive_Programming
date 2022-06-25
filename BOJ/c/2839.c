#include <stdio.h>

int main() {
	int N; scanf("%d", &N);
    if (N % 5 == 0) printf("%d", N / 5);
	else if (N % 5 == 1 || N % 5 == 3) printf("%d", N / 5 + 1);
	else if (N % 5 == 2 || N % 5 == 4) {
		if (N == 4 || N == 7) printf("-1");
		else printf("%d", N / 5 + 2);
	}
}
