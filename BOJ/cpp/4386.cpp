#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

/*Minimum Spanning Tree - Kruskal Algorithm*/

typedef struct {
	int s, u;
	double cost;
} edge;

int parent[101];
int edgeNum = 0;
vector<edge> edges;
vector<pair<int, int> > stars;

bool compare(edge a, edge b) {
	return a.cost < b.cost;
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
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double a, b; scanf("%lf %lf", &a, &b);
		stars.push_back(make_pair(a, b));
		parent[i + 1] = i + 1;
 	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			double temp = sqrt(pow(stars[i - 1].first - stars[j - 1].first, 2) 
						  + pow(stars[i - 1].second - stars[j - 1].second, 2));
			edges.push_back({ i, j, temp });
		}
	}
	
	sort(edges.begin(), edges.end(), compare);
	
	double sum = 0;
	for (auto i : edges) {
		if (find(i.s) != find(i.u)) {
			merge(i.s, i.u);
			sum += i.cost;
		}
	}
	printf("%.2lf\n", sum);
}

