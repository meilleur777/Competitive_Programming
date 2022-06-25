#include <stdio.h>

int main() {
	int N, M; scanf("%d %d", &M, &N);
	bool arr[1000001] = { false, true, false };
	for (int i = 2; i <= N; i++) for (int j = i * 2; j <= N; j += i) arr[j] = true;
	for (int i = M; i <= N; i++) if (!arr[i]) printf("%d\n", i);
}

