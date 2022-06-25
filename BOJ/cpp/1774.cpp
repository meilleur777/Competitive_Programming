#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

/*Minimum Spanning Tree Using Kruskal Algorithm*/

typedef pair<int ,int> p;

typedef struct {
	int num, x, y;
} node;

typedef struct {
	int s, u;
	double w;
} edge;

vector<int> parent;
vector<node> nodes;
vector<edge> edges;

bool compare(edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	parent[a] = b;
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		int X, Y; scanf("%d %d", &X, &Y);
		nodes.push_back({ i, X, Y });
		parent.push_back(i);
	}
	
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		merge(a - 1, b - 1);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			double cost = sqrt((pow(nodes[i].x - nodes[j].x, 2)
			 + pow(nodes[i].y - nodes[j].y, 2)));
			edges.push_back({ i, j, cost });
		}
	}
	
	sort(edges.begin(), edges.end(), compare);
	
	double answer = 0;
	for (auto i : edges) {
		if (find(i.s) != find(i.u)) {
			merge(i.s, i.u);
			answer += i.w;
		}
	}
	printf("%.2lf", answer);
}

