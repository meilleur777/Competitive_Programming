#include <stdio.h>

/*Two Pointers*/

int main() {
	int N, M; scanf("%d %d", &N, &M);
	int arr[10001], count = 0, start = 0, end = 0, sum = 0;
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	while (end <= N) {
		if (sum < M) sum += arr[end++];
		else if (sum == M) {
			count++;
			sum -= arr[start++];
		}
		else sum -= arr[start++];
	}
	printf("%d\n", count);
}

