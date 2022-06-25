#include <stdio.h>

int parent[500001];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);	
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool check(int n) {
	int temp = find(0);
	for (int i = 1; i < n; i++) if (temp != find(i)) return false;
	return true;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) parent[i] = i; 
	
	int result;
	bool flag = false;
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		int ap = find(a), bp = find(b);
		if (flag) continue;
		if (ap == bp) {
			flag = true; 
			result = i;
		}
		else merge(a, b);
	}
	
	if (flag) printf("%d\n", result);
	else printf("0\n");
}

