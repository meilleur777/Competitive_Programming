#include <stdio.h>

char string[1000002];

int main() {
	int i, N, M; scanf("%d\n%d", &N, &M);
	scanf("%s", string);
	int temp = 0, count = 0;
		
	for (i = 0; i < M - 2; i++) {
		temp = 0;
		if (string[i] == 'I') {
			while (string[i + 1] == 'O' && string[i + 2] == 'I') {
				temp++;
				i += 2;
				if (temp == N) {
					count++;
					temp--;
				}
			}
		}
	}
	printf("%d\n", count);
}
