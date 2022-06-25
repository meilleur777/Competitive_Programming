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
	vector<int> a(n+1), b(n), c(n);
	rep(i, n) cin >> a[i+1];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];
	a[0]=0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	ll ans=0;
	for (int i=0; i<n; i++) {
		ll fora=lower_bound(a.begin(), a.end(), b[i])-a.begin();
		if (fora!=0) fora--;
		ll forc=c.end()-upper_bound(c.begin(), c.end(), b[i]);
		// cout << fora << ' ' << forc << '\n';
		ans+=fora*forc;
	}
	cout << ans;

	return 0;
}
