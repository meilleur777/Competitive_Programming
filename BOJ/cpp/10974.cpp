#include <stdio.h>

int N, arr[10];
bool visit[10] = { false };

void solve(int x) {
	if (x == N) {
		for (int i = 0; i < N - 1; i++) printf("%d ", arr[i]);
		printf("%d\n", arr[N - 1]);
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[x] = i;
			solve(x + 1);
			visit[i] = false;
		}
	}
}
	                 
int main() {     
	scanf("%d", &N);
	solve(0);	
}

