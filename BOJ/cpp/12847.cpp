#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long long ull;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	ull arr[100002] = { 0 }, max = 0;
	for (int i = 1; i <= n; i++) {
		ull a; scanf("%lld", &a);
		arr[i] = arr[i - 1] + a;
	}
	for (int i = m; i <= n; i++) max = MAX(max, arr[i] - arr[i - m]);
	printf("%lld\n", max);
}

