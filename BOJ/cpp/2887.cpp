#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
	
typedef long long ll;	
typedef pair<int, int> p;	
	
typedef struct {
	int s, u, w;
} edge;

bool compare(edge a, edge b) { return a.w < b.w; }
bool compare2(p a, p b) { return a.first < b.first; }

vector<int> parent;
vector<edge> edges;	
vector<p> X, Y, Z;	

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	parent[b] = a;
}

int main() {
	int N; scanf("%d" ,&N);
	
	for (int i = 0; i < N; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		X.push_back({x, i});
		Y.push_back({y, i});
		Z.push_back({z, i});
		parent.push_back(i);
	} 
	
	sort(X.begin(), X.end(), compare2);
	sort(Y.begin(), Y.end(), compare2);
	sort(Z.begin(), Z.end(), compare2);
	
	for (int i = 0; i < N - 1; i++) {
		edges.push_back({X[i].second, X[i + 1].second, X[i + 1].first - X[i].first});
		edges.push_back({Y[i].second, Y[i + 1].second, Y[i + 1].first - Y[i].first});
		edges.push_back({Z[i].second, Z[i + 1].second, Z[i + 1].first - Z[i].first});
	}
	
	sort(edges.begin(), edges.end(), compare);
	
	ll answer = 0;
	for (auto i : edges) {
		if (find(i.s) != find(i.u)) {
			answer += (ll)i.w;
			merge(i.s, i.u);
		}
	}
	
	printf("%lld\n", answer);	
}

