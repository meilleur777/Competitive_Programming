#include <queue>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		int n, x, result = 0; cin >> n;
		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i = 0; i < n; i++) { cin >> x; pq.push(x); }
		while (pq.size() > 1) {
			int min1 = pq.top(); pq.pop();
			int min2 = pq.top(); pq.pop();
			pq.push(min1 + min2);
			result += min1 + min2;
		}
		cout << result << '\n';
	}		
}

