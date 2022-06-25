#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

typedef pair<int, int> p;

int N;
vector<p> edges[100002];

void Dijkstra(int S, vector<int>& dist) {
	dist[S] = 0;
	priority_queue<p, vector<p>, greater<p> > pq;
	pq.push({ dist[S], S });
	
	while (!pq.empty()) {
		int U = pq.top().second, D = pq.top().first;
		pq.pop();
		
		for (auto i : edges[U]) {
			if (dist[i.first] > D + i.second) {
				dist[i.first] = D + i.second;
				pq.push({ dist[i.first], i.first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	int S[3], M; cin >> N;
	for (int i = 0; i < 3; i++) cin >> S[i];
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int D, E, L;
		cin >> D >> E >> L;
		edges[D].push_back({ E, L });
		edges[E].push_back({ D, L });
	}
	
	vector<int> dist[3];
	for (int i = 0; i < 3; i++) {
		dist[i].resize(N + 1);
		fill(dist[i].begin(), dist[i].end(), INF);
		Dijkstra(S[i], dist[i]);
	}
	
	int resultValue = -1, result;
	for (int i = 1; i <= N; i++) {
		if (resultValue < min({ dist[0][i], dist[1][i], dist[2][i] })) {
			resultValue = min({ dist[0][i], dist[1][i], dist[2][i] });
			result = i;
		}
	}
	cout << result << '\n';
}

