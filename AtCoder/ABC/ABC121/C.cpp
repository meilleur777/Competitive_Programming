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

	ll N, M;
	cin >> N >> M;
	vector<pair<ll, ll> > store(N);
	for (int i=0; i<N; i++) {
		int a, b;
		cin >> a >> b;
		store[i]={a, b};
	}
	sort(store.begin(), store.end());
	ll ans=0;
	for (int i=0; i<N; i++) {
		ll buy=min(M, store[i].second);
		ans+=buy*store[i].first;
		M-=buy;
	}
	cout << ans;

	return 0;
}
