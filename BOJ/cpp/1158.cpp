#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	deque<int> dq;
	vector<int> result;	
	int N, K; cin >> N >> K;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	while (!dq.empty()) {
		for (int i = 0; i < K - 1; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		result.push_back(dq.front());
		dq.pop_front();
	}
	cout << '<';
	for (auto i : result) {
		cout << i;
		if (i != *result.rbegin()) cout << ", ";
	}
	cout << ">\n";
}

