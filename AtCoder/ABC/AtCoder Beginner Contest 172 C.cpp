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

	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n+1), b(m+1);
	rep(i, n) cin >> a[i+1];
	rep(i, m) cin >> b[i+1];
	for (int i=0; i<n; i++) {
		a[i+1]+=a[i];
	}
	for (int i=0; i<m; i++) {
		b[i+1]+=b[i];
	}
	ll ans=-1;
	for (int i=0; i<=n; i++) {
		// cout << a[i] << '\n';
		if (a[i]>k) continue;
		ll tmp=upper_bound(b.begin(), b.end(), k-a[i])-b.begin();
		if (tmp!=0) tmp--;
		// cout << tmp << '\n';
		ans=max(ans, i+tmp);
	}
	cout << ans;

	return 0;
}
