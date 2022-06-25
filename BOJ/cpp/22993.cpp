#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

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

	ll N, A;
	cin >> N >> A;
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	for (int i = 1; i <= N; i++) {
		ll x;
		cin >> x;
		pq.push(x);	
	}
	while (!pq.empty() && pq.top() < A) {
		A += pq.top();
		pq.pop();
	}
	if (!pq.empty()) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}

	return 0;
}
