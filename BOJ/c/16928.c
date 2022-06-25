#include <stdio.h>

int check[102] = { 0, 1 };
int queue[500000], front = 0, back = 0;
int ladder[101] = { 0 }, snake[101] = { 0 };

int main() {
	int i, N, M; scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		ladder[x] = y;
	}
	for (i = 0; i < M; i++) {
		int u, v; scanf("%d %d", &u, &v);
		snake[u] = v;
	}
	
	queue[back++] = 1;
	while (front < back) {
		int temp = queue[front++];
		if (temp == 100) break;
		
		for (i = 1; i <= 6; i++) {
			int k = temp + i;
			if (k <= 100 && !check[k]) {
				check[k] = check[temp] + 1;
				if (snake[k]) {
					k = snake[k];
					if (!check[k]) {
						check[k] = check[temp] + 1;
						queue[back++] = k;
					}
				}
				else if (ladder[k]) {
					k = ladder[k];
					if (!check[k]) {
						check[k] = check[temp] + 1;
						queue[back++] = k;
					}
				}
				else {
					check[k] = check[temp] + 1;
					queue[back++] = k;
				}
			}
		}
	}
	printf("%d\n", check[100] - 1);
}
