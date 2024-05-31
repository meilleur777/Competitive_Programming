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
	deque<pair<ll, int> > dq;
	vector<ll> a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
		dq.push_back({a[i]+b[i], i});
	}
	sort(dq.begin(), dq.end());
	int cnt=0;
	ll ans=0;
	while (!dq.empty()) {
		int now=dq.back().second;
		if (cnt%2) {
			ans-=b[now];
			dq.pop_back();
		}
		else {
			ans+=a[now];
			dq.pop_back();
		}
		cnt++;
	}
	cout << ans;

	return 0;
}
