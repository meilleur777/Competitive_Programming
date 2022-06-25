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
		int n;
		cin >> n;
		vector<ll> a(n);
		rep(i, n) cin >> a[i];
		ll sum=0;
		rep(i, n) sum+=a[i];
		sum*=2;
		if (sum%n) {
			cout << "0\n";
			continue;
		}
		sum/=n;
		sort(a.begin(), a.end());
		ll ans=0;
		for (int i=0; i<n; i++) {
			auto hi=upper_bound(a.begin()+i+1, a.end(), sum-a[i]);
			auto lo=lower_bound(a.begin()+i+1, a.end(), sum-a[i]);
			ans+=hi-lo;
		}
		cout << ans << '\n';
	}

	return 0;
}
