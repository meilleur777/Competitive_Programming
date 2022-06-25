#include <stdio.h>
#include <stdlib.h>

int compare(const int *a, const int *b) {
	return (*a > *b) ? 1 : (*a < *b) ? -1 : 0;
}

int main() {
	int i, N, M, arr[100001], keys[100001];
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", arr + i);
	scanf("%d", &M);
	for (i = 0; i < M; i++) scanf("%d", keys + i);

	qsort(arr, N, sizeof(int), compare);

	for (i = 0; i < M; i++) {
		if (bsearch(keys + i, arr, N, sizeof(int), compare)) printf("1\n");
		else printf("0\n");
	}

	return 0;
}
