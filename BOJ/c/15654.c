#include <stdio.h>

int arr[10], N, M;
int visit[10] = { 0 };

int cpr(const void *a, const void *b) {
	int *m = (int *)a, *n = (int *)b;
	return (*m > *n) ? 1 : (*m < *n) ? -1 : 0;
}

void rec(int *ans, int count) {
	int i;
	if (count == M) {
		for (i = 0; i < M; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	
	for (i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			ans[count] = arr[i];
			rec(ans, count + 1);
			visit[i] = 0;
		}	
	}	
}

int main() {
	int i, ans[10]; scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), cpr);
	rec(ans, 0);
}
