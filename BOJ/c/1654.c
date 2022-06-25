#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y) {
	int a = *(int *)x; int b = *(int *)y;
	return (a > b) ? 1 : (a < b) ? -1 : 0;
}

int main() {
	int i, K, N, length[10001];
	scanf("%d %d", &K, &N);
	for (i = 0; i < K; i++) scanf("%d", &length[i]);
	
	qsort(length, K, sizeof(int), compare);
	
	unsigned number, mid, result;
	unsigned left = 1, right = length[K - 1];
	
	while (left <= right) {
		number = 0;
		mid = (left + right) / 2;
        
		for (i = 0; i < K; i++) 
			number += length[i] / mid;
		
		if (number >= N) {
			result = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
		
	printf("%d", result);
	return 0;
}
