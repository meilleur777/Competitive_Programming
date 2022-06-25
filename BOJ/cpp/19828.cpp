#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll t, n, a, b, k;
	cin >> t >> n >> a >> b >> k;
	ll left=0, right=t;
	ll ans=0;
	auto pos=[&](ll mid) {
		ll aa=min(a, mid);
		ll bb=min(b, mid);
		return (n+1)/2*aa+n/2*bb>=k*mid;
	};
	while (left<=right) {
		ll mid=(left+right)/2;
		if (pos(mid)) {
			ans=mid;
			left=mid+1;
		}
		else right=mid-1;
	}
	cout << ans;

	return 0;
}
