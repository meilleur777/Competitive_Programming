#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

#define INF 10000000
#define MAX 20001

using namespace std;

int d[MAX];
vector<pair<int, int> > edge[MAX];

int main() {
	int V, E, K; scanf("%d %d %d", &V, &E, &K);
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++) d[i] = INF;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	
	d[K] = 0;
	q.push(make_pair(d[K], K));
	while (!q.empty()) {
		int node = q.top().second;
		int dist = q.top().first;
		q.pop();
		
		for (auto i : edge[node]) {
			if (d[i.first] > d[node] + i.second) {
				d[i.first] = d[node] + i.second;
				q.push(make_pair(d[i.first], i.first));
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		if (d[i] < INF) printf("%d\n", d[i]);
		else printf("INF\n");
	}
}

