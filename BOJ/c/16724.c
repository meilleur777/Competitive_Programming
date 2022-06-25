#include <stdio.h>
#include <stdbool.h>

int N, M;
char map[1001][1001];
bool vis[1000001] = { false };
int parent[1000001];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", &map[i]);
	for (int i = 0; i < M * N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int row = i, col = j;
			switch(map[i][j]) {
				case 'D': row++; break;
				case 'U': row--; break;
				case 'L': col--; break;
				case 'R': col++; break;	
			}
			merge(i * M + j, row * M + col);
		}
	}
	
	int res = 0;
	for (int i = 0; i < M * N; i++) {
		if (!vis[find(i)]) {
			vis[find(i)] = true;
			res++;
		}
	}
	printf("%d\n", res);
}

