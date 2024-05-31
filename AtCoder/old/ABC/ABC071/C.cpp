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

	map<ll, ll> m;
	ll N;
	cin >> N;
	rep(i, N) {
		ll a;
		cin >> a;
		m[a]++;
	}
	vector<ll> can;
	for (auto [a, b] : m) {
		if (b>0) {
			ll tmp=b/2;
			while (tmp--) {
				can.push_back(a);
			}
		}
	}
	if (can.size()<=1) {
		cout << 0;
	}
	else {
		sort(can.begin(), can.end(), greater<ll>());
		cout << can[0]*can[1];
	}

	return 0;
}
