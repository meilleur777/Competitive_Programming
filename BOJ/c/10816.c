#include <stdio.h>

int arr[500001];

int compare(const void *a, const void *b) {
	int *m = (int *)a, *n = (int *)b;
	return (*m > *n) ? 1 : (*m < *n) ? -1 : 0;
}

int upperSearch(int start, int end, int key) {
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			if (arr[mid + 1] == key) start = mid + 1;
			else return mid;
		}
		else if (arr[mid] > key) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

int lowerSearch(int start, int end, int key) {
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			if (arr[mid - 1] == key) end = mid - 1;
			else return mid;
		}
		else if (arr[mid] > key) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

int main() {
	int i, N, M, key, answer;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &arr[i]);
	
	qsort(arr, N, sizeof(int), compare);
	
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &key);
		int upper = upperSearch(0, N - 1, key);
		int lower = lowerSearch(0, N - 1, key);
		if (upper < 0) answer = 0;
		else answer = upper - lower + 1;
		printf("%d ", answer);
	}
	
	return 0;
}
