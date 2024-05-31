#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll k;
	cin >> k;
	ll ans=0;
	for (ll i=1; i<=k; i++) {
		for (ll j=1; j<=k ;j++) {
			if (i*j>k) break;
			ans+=k/(i*j);
		}
	}
	cout << ans;

	return 0;
}
