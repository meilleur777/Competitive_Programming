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

	ll n;
	cin >> n;
	ll ans=0;
	for (ll i=1; i<=16; i++) {
		ll now=0;
		rep(j, i) now=now*10+1;
		ll tmp=now;
		for (int j=i; j<=16; j++) {
			if (now<=n) {
				ans+=min(n, tmp)-now+1;
			}
			// cout << now << ' ' << tmp << '\n';
			now*=10;
			tmp=tmp*10+9;
		}
	}
	cout << ans;

	return 0;
}
