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

	ll n, C;
	cin >> n >> C;
	vector<ll> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	map<int, ll> mp;
	rep(i, n) {
		mp[a[i]]+=c[i];
		mp[b[i]+1]-=c[i];
	}
	int las=0;
	ll now=0;
	ll ans=0;
	for (auto [p, q]:mp) {
		ans+=(p-las)*min(now, C);
		now+=q;
		las=p;
	}
	cout << ans;

	return 0;
}
