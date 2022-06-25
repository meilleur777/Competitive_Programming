#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, M, S, U;
vector<p> edges[10001];
vector<int> costs;

bool possible(int cost) {
	queue<int> q;
	bool visit[10002] = { false };
	q.push(S); visit[S] = true;
	
	while (!q.empty()) {
		int temp = q.front(); q.pop();
		if (temp == U) return true;
		for (auto i : edges[temp]) {
			if (!visit[i.first] && i.second >= cost) {
				visit[i.first] = true;
				q.push(i.first);
			}
		}
	}
	return false;
}

int solve() {
	int start = 0, end = M - 1;
	int result;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (possible(costs[mid])) {
			result = costs[mid];
			start = mid + 1;
		}		
		else end = mid - 1;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C; cin >> A >> B >> C;
		edges[A].push_back({ B, C });
		edges[B].push_back({ A, C });
		costs.push_back(C);
	}
	cin >> S >> U;
	sort(costs.begin(), costs.end());
	cout << solve() << '\n';
}

