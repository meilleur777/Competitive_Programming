#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int A[5000002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	deque<p> dq;
	int N, L; cin >> N >> L;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		while (!dq.empty() && dq.front().second < i - L + 1) dq.pop_front();
		while (!dq.empty() && dq.back().first >= A[i]) dq.pop_back();
		dq.push_back({ A[i], i });
		cout << dq.front().first << ' ';
	}
	cout << '\n';
}

