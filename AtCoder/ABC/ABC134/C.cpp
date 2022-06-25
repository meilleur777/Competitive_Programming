#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

	priority_queue<int> pq;
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) {
		cin >> A[i];
		pq.push(A[i]);
	}
	rep(i, N) {
		if (pq.top()==A[i]) {
			int memo=pq.top();
			pq.pop();
			cout << pq.top() << '\n';
			pq.push(memo);
		}
		else {
			cout << pq.top() << '\n';
		}
	}

	return 0;
}
