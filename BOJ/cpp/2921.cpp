#include <stdio.h>

typedef long long ll;

int main() {
	int N; ll sum = 0; scanf("%d", &N);
	for (ll i = 1; i <= N; i++) sum += 3 * i * (i + 1) / 2;
	printf("%lld\n", sum);
}

