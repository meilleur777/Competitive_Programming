#include <stdio.h>
typedef long long ll;

int main() {
	ll sum = 0, X[10001], Y[10001];
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld %lld", &X[i], &Y[i]);
	for (int i = 0; i < N - 1; i++) sum += X[i]*Y[i + 1] - X[i + 1]*Y[i];
	sum += X[N - 1]*Y[0] - X[0]*Y[N - 1];
	sum = sum < 0 ? sum * -1 : sum;
	printf("%.1lf", sum / 2.0);
}

