#include <stdio.h>

int count = 0;
int input[10010];
int parent[10010];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

int merge(int a, int b) {
	a = find(a), b = find(b);
	parent[b] = a;
}

int main() {
	int G, P; scanf("%d %d", &G, &P);
	for (int i = 0; i <= G; i++) parent[i] = i;
	for (int i = 0; i < P; i++) scanf("%d", &input[i]);
	for (int i = 0; i < P; i++) {
		int g = input[i], p = find(g);
		if (!p) break;
		merge(p - 1, p); 
		count++;
	}
	printf("%d\n", count);
}

