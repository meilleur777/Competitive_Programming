#include <stdio.h>

/*Disjoint Set*/

int parent[202];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a; scanf("%d", &a);
			if (a) merge(i, j);
		}
	}
	
	int plan[1001];
	for (int i = 0; i < M; i++) scanf("%d", &plan[i]);
	int temp = find(plan[0]);
	for (int i = 1; i < M; i++) {
		if (temp != find(plan[i])) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}

