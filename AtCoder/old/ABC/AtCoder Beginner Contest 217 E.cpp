#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int q;
	cin >> q;
	priority_queue<int, vector<int>, greater<int> > pq;
	deque<int> dq;
	while (q--) {
		int x;
		cin >> x;
		if (x==1) {
			cin >> x;
			dq.push_back(x);
		}
		else if (x==2) {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else {
			while (!dq.empty()) {
				pq.push(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}
