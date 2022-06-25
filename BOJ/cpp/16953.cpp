#include <stdio.h>

long long B;
int min = 100000;

void dfs(int A, int count) {
	if (A > B) return;
	else if (A == B) min = min < count ? min : count;
	else {
		dfs(A * 10 + 1, count + 1);
		dfs(A * 2, count + 1);
	}
}

int main() {
	long long A;
	scanf("%ld %ld", &A, &B);
	dfs(A, 0);
	if (min == 100000) printf("-1\n");
	else printf("%d", min + 1);
}

