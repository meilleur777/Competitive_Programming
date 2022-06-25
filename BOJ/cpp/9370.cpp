#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

typedef pair<int, int> p;

/*Dijkstra Algorithm*/

/*오답 이유 - pie를 통해 가장 최근에 지나온 노드를 저장한 후 그것을 이용해
g, h가 경로에 포함되는지 확인하는 방식으로 하였으나, 만일 최단 경로가 여러 개일 경우
가장 최근에 확인한 경로가 확인되므로, 만일 다른 최단 경로에 g, h가 포함될 경우
불가능한 case로 판단한다. 따라서, s->g->h->t, s->h->g->t의 방식으로 
최단 경로의 길이를 확인하여 판단한다. 이를 위해 s, h, g에서 각각 다익스트라 알고리즘을
사용한다.*/

void Dijkstra(vector<p> *edges, int *dis, int start) {
	dis[start] = 0;
	priority_queue<p, vector<p>, greater<p> > pq;
	pq.push({dis[start], start});
	
	while (!pq.empty()) {
		int node = pq.top().second, cost = pq.top().first;
		pq.pop();
		
		for (auto j : edges[node]) {
			int nextnode = j.first, weight = j.second;
			if (dis[nextnode] > cost + weight) {
				dis[nextnode] = cost + weight;
				pq.push({dis[nextnode], nextnode});
			}
		}
	}
} 

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		vector<p> edges[2001];
		int candidates[101];
		int Sdis[2001], Hdis[2001], Gdis[2001];
		
		int n, m, t; scanf("%d %d %d", &n, &m, &t);
		int s, g, h; scanf("%d %d %d", &s, &g, &h);
		for (int i = 0; i < m; i++) {
			int a, b, d; scanf("%d %d %d", &a, &b, &d);
			edges[a].push_back({b, d});
			edges[b].push_back({a, d});
		}
		for (int i = 0; i < t; i++) {
			int x; scanf("%d", &x);
			candidates[i] = x;
		}
		sort(candidates, candidates + t);
		
		memset(Sdis, 0x3F, sizeof(Sdis)); Dijkstra(edges, Sdis, s);
		memset(Gdis, 0x3F, sizeof(Gdis)); Dijkstra(edges, Gdis, g);
		memset(Hdis, 0x3F, sizeof(Hdis)); Dijkstra(edges, Hdis, h);		
				
		int num = 0, result[101];
		for (int i = 0; i < t; i++) {
			int x = candidates[i];
			if (Sdis[x] == INF) continue;
			if (Sdis[x] == Sdis[g] + Gdis[h] + Hdis[x] 
			 || Sdis[x] == Sdis[h] + Hdis[g] + Gdis[x]) {
				result[num++] = x;		
			}
		}
		
		for (int i = 0; i < num - 1; i++) printf("%d ", result[i]);
		printf("%d\n", result[num - 1]);
	}
}

