#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool vis[100001] = { false };
int dis[100001] = { 0 };
vector<pair<int, int> > edge[100001];
/*v[i] = (k, w) -> i번째 정점의 간선정보,  k로 향하고 가중치는 w이다.*/

void DFS(int V) {
	vis[V] = true;
	for (auto i : edge[V]) {
		int k = i.first;
		int w = i.second;
		if (!vis[k]) {
			dis[k] += dis[V] + w;
			DFS(k);
		}
	}
}

int main() {
	int V; scanf("%d", &V);
	for (int i = 0; i < V; i++) {
		int K; scanf("%d", &K); 
		while (1) {
			int a, b; scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			edge[K].push_back(make_pair(a, b));
		}
	}
	
	int max = 1; dis[1] = 0; DFS(1);
	for (int i = 2; i <= V; i++) max = dis[max] > dis[i] ? max : i;
	memset(dis, 0, sizeof(int) * 100001);
	memset(vis, false, sizeof(bool) * 100001);
	DFS(max);
	sort(dis + 1, dis + V + 1);
	printf("%d\n", dis[V]);
}

