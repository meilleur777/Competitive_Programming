#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	rep(i, n) {
		int a;
		cin >> a;
		pq.push(a);
	}
	while (m--) {
		ll a=pq.top();
		pq.pop();
		ll b=pq.top();
		pq.pop();
		rep(i, 2) pq.push(a+b);
	}
	ll ans=0;
	while (!pq.empty()) {
		ans+=pq.top();
		pq.pop();
	}
	cout << ans;

	return 0;
}
