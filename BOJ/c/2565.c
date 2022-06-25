#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int A;
    int B;
} map;

int compare(const void *a, const void *b) {
    map *m = (map *)a, *n = (map *)b;
    return (m->A > n->A) ? 1 : (m->A < n->A) ? -1 : 0; 
}

int compareint(const void *a, const void *b) {
    int *m = (int *)a, *n = (int * )b;
    return (*m > *n) ? -1 : (*m < *n) ? 1 : 0;
}

int main() {
    map arr[101];
	int dp[101] = { 1 };
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b; scanf("%d %d", &a, &b);
        arr[i].A = a; arr[i].B = b;
	}
    qsort(arr, N, sizeof(map), compare);
	for (int i = 1; i < N; i++) {
		int max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j].B < arr[i].B) {
				max = max > dp[j] ? max : dp[j];
			}
		}
		dp[i] = max + 1;
	}
    qsort(dp, N, sizeof(int), compareint);
    printf("%d\n", N - dp[0]);
}

