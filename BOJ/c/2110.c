#include <stdio.h>
#include <stdlib.h>

int house[200001];

int compare(const void *a, const void *b) {
	int *m = (int *)a, *n = (int *)b;
	return (*m > *n) ? 1 : (*m < *n) ? -1 : 0;
}

int main() {
	int i, N, C; scanf("%d %d", &N, &C);
	for (i = 0; i < N; i++) scanf("%d", &house[i]);
	qsort(house, N, sizeof(int), compare);
	
	int distance, result;
	int start = 1, end = house[N - 1] - house[0];
	while (start <= end) {
		int temp = C - 1, recent = house[0];
		distance = (start + end) / 2;
		for (i = 1; i < N; i++) {
			if (house[i] - recent >= distance) {
                temp--;
                recent = house[i];
            }
        }
		if (temp <= 0) {
			result = distance;
			start = distance + 1;
		}
		else end = distance - 1;
	}
	printf("%d\n", result);
}
