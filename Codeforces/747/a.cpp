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

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		n*=2;
		for (ll i=1; i*i<=n; i++) {
			if (n%i==0) {
				ll c=i+n/i;
				ll d=i-n/i;
				c-=1;
				if (c%2) continue;
				d++;
				if (d%2) continue;
				c/=2;
				d/=2;
				cout << min(c, d) << ' ' << max(c, d) << '\n';
				break;
			}
		}
	}

	return 0;
}
