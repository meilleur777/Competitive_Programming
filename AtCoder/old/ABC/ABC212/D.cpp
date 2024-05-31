#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	priority_queue<ll, vector<ll>, greater<ll> > pq;
	
	int Q;
	cin >> Q;
	ll sum = 0;

	while (Q--) {
		ll q, x;
		cin >> q;

		switch (q) {
			case 1:
				cin >> x;
				pq.push(x - sum);
				break;
			case 2:
				cin >> x;
				sum += x;
				break;
			case 3:
				cout << pq.top() + sum << '\n';
				pq.pop();
		}
	}
}
