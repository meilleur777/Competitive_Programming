#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int *m = (int *)a, *n = (int *)b;
	return (*m > *n) ? 1 : (*m < *n) ? -1 : 0;
}

int main() {
	int i, L, S[51], n;
	scanf("%d", &L);
	for (i = 0; i < L; i++) scanf("%d", &S[i]);
	scanf("%d", &n);
	qsort(S, L, sizeof(int), compare);
	
	int min = 0;
	for (i = 1; i < L; i++) {
		if (S[i] <= n) min = S[i];
		else break;
	}
	
	int max = S[L - 1];
	for (i = L - 2; i >= 0; i--) {
		if (S[i] >= n) max = S[i];
		else break;
	}
	
	int j, count = 0;
	for (i = min + 1; i <= n; i++) {
		for (j = max - 1; j >= n; j--) {
			if (i < j) count++;
		}
	}
	
	printf("%d", count);
}
