#include <stdio.h>

int main() {
	int N; scanf("%d", &N);
	if (N == 1) {
		printf("*");
		return 0;
	}
	for (int j = 0; j < N - 1; j++) printf(" ");
	printf("*\n");
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) printf(" ");
		printf("*");
		for (int j = 0; j < 2 * i - 1; j++) printf(" ");
		printf("*\n");
	}
	for (int i = 0; i < 2 * (N - 1) + 1; i++) printf("*");
}

