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

	int n;
	cin >> n;
	vector<ll> a(n);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	rep(i, n) {
		cin >> a[i];
		pq.push(a[i]);
	}
	ll ans=0;
	while (pq.size()>1) {
		ll a=pq.top();
		pq.pop();
		ll b=pq.top();
		pq.pop();
		ans+=a+b;
		pq.push(a+b);
	}
	cout << ans;

	return 0;
}
