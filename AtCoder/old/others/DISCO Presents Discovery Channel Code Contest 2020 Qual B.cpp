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
	rep(i, n) cin >> a[i];
	ll sum=0;
	rep(i, n) sum+=a[i];
	ll tmp=0;
	ll ans=LLONG_MAX;
	for (int i=0; i<n; i++) {
		tmp+=a[i];
		ll lef=sum-tmp;
		ans=min(ans, abs(lef-tmp));
	}
	cout << ans;

	return 0;
}
