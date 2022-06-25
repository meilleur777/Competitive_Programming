#include <stdio.h>

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		if (i % 2) {
			for (int j = 0; j < N; j++) printf(" *");
			printf("\n");
		}
		else {
			for (int j = 0; j < N - 1; j++) printf("* ");
			printf("*\n");			
		}
	}
}

