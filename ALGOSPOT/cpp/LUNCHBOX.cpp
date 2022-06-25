#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, M[10001], E[10001];

int solve() {
	vector<p> order;
	for (int i = 0; i < N; i++) order.push_back({ E[i], i });
	sort(order.begin(), order.end(), greater<p>());
	
	int ret = 0, beginEat = 0;
	for (int i = 0; i < N; i++) {
		int box = order[i].second;
		beginEat += M[box];
		ret = max(ret, beginEat + E[box]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while (T--)	{
		cin >> N;
		for (int i = 0; i < N; i++) cin >> M[i];
		for (int i = 0; i < N; i++) cin >> E[i];
		cout << solve() << '\n';
	}
}

