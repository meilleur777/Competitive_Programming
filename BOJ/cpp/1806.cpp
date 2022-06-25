#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define NUM 100001

/*Two Pointers*/

int main() {
	int arr[NUM] = { 0 }, N, S; scanf("%d %d", &N, &S);
	int result = NUM, start = 1, end = 1, sum = 0;
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	while (end <= N + 1) {
		if (sum < S) sum += arr[end++];
		else if (sum >= S) {
			result = MIN(result, end - start);
			sum -= arr[start++];				
		}
 	}
 	if (result == NUM) printf("0\n");
 	else printf("%d\n", result);
}

