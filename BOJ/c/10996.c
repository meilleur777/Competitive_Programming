#include <stdio.h>

int main() {
	int N; scanf("%d", &N);
	if (N == 1) { printf("*\n"); return 0; }
	for (int i = 0; i < 2 * N; i++) {
		if (i % 2) {
			for (int j = 0; j < N / 2; j++) printf(" *");
			printf("\n");
		}	
		else {
			for (int j = 0; j < (N + 1) / 2 - 1; j++) printf("* ");
			printf("*\n");
		}
	}
}

