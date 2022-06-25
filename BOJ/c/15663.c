#include <stdio.h>
#include <stdlib.h>

int N, M;
int vis[10] = { 0 };
int arr[10];

int cpr(const void *a, const void *b) {
	int *m = (int *)a, *n = (int *)b;
	return (*m > *n) ? 1 : (*m < *n) ? -1 : 0;
}

void solve(int *res, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) printf("%d ", res[i]);
		printf("\n");
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (!vis[i] && res[count] != arr[i]) {
			vis[i] = 1;
			res[count] = arr[i];
			solve(res, count + 1);
			vis[i] = 0;
		}
	}
    res[count] = 0;
}

int main() {
	int res[10] = { 0 }; 
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), cpr);
	solve(res, 0);
}

