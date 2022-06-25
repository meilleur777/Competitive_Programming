#include <queue>
#include <vector>
#include <string.h>
#include <iostream>
#define INF 987654321
using namespace std;

typedef pair<int, pair<int, int> > p;

int N, M, K, S, D;
int dist[1002][1002];
vector<pair<int, int> > edges[1002];

void Dijkstra() {
	fill_n(&dist[0][0], 1002 * 1002, INF);
	
	priority_queue<p, vector<p>, greater<p> > pq;
	pq.push({ 0, { S, 0 }});
	dist[S][0] = 0;
	
	while (!pq.empty()) {
		int used = pq.top().first;
		int node = pq.top().second.first;
		int been = pq.top().second.second;
		pq.pop();
		
		if (used > dist[node][been] || been == N) continue;
		
		for (auto i : edges[node]) {
			int next = i.first, cost = i.second;
			
			if (dist[next][been + 1] > used + cost) {
				dist[next][been + 1] = used + cost;
				pq.push({ dist[next][been + 1], { next, been + 1 }});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> K >> S >> D;	
	
	for (int i = 0; i < M; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[a].push_back({ b, w });
		edges[b].push_back({ a, w });
	}
	
	Dijkstra();
	
	int result = INF;
	for (int i = 1; i < N; i++) {
		result = min(result, dist[D][i]);
	}
	cout << result << '\n';
	
	for (int i = 0; i < K; i++) {
		int p;
		cin >> p;
		
		result = INF;
		for (int i = 1; i < N; i++) {
			dist[D][i] += i * p;
			result = min(result, dist[D][i]);
		}
		cout << result << '\n';
	}
}

