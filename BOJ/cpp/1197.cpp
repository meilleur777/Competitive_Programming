#include <stdio.h>
#include <algorithm>
using namespace std;

/*MST (Minimum Spanning Tree)
Kruskal Algorithm*/

typedef struct {
	int a, b;
	int cost;
} edge;

int nodes[10001];
edge edges[100001];

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

int findParent(int x) {
	if (x == nodes[x]) return x;
	else return nodes[x] = findParent(nodes[x]);	
}

bool sameParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return true;	
	else return false;
}

void merge(int a, int b) {
	a = findParent(a), b = findParent(b);
	if (a < b) nodes[b] = a;
	else nodes[a] = b;
}

int main() {
	int V, E, sum = 0; scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; i++) nodes[i] = i;
	for (int i = 0; i < E; i++) {
		int A, B, C; scanf("%d %d %d", &A, &B, &C);
		edges[i].a = A, edges[i].b = B, edges[i].cost = C;
	} 
	sort(edges, edges + E, compare); 
	for (int i = 0; i < E; i++) {
		if (!sameParent(edges[i].a, edges[i].b)) {
			merge(edges[i].a, edges[i].b);
			sum += edges[i].cost;
		} 
	}
	printf("%d\n", sum);
}

