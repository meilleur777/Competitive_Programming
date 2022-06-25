#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[10001] = { 0 }; 

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
	
	for (int i = 1; i < 10001; i++) {
		if (arr[i] && res[count - 1] <= i) {
			res[count] = i;
			solve(res, count + 1);
		}
	}
}

int main() {
	int res[10] = { 0 }; 
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		arr[x] = 1;
	}
	
	for (int i = 1; i < 10001; i++) {
		if (arr[i]) {
			res[0] = i;
			solve(res, 1);
		}
	}
}

