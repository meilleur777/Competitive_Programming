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

	int n;
	cin >> n;
	vector<pair<pair<ll, ll>, pair<ll, ll>>> v(n);
	rep(i, n) {
		ll x, y;
		cin >> x >> y;
		v[i]={{x-1, y}, {x, y-1}};
	}
	sort(v.begin(), v.end(), [&](pair<intp, intp> a, pair<intp, intp> b) {
		ll a1=a.first.first, a2=a.first.second, a3=a.second.first, a4=a.second.second;
		ll b1=b.first.first, b2=b.first.second, b3=b.second.first, b4=b.second.second;
		if (a4*b3==a3*b4) {
			return a2*b1>a1*b2;
		}
		return a4*b3>a3*b4;
	});
	int ans=1;
	pair<ll, ll> now=v[0].second;
	for (int i=1; i<n; i++) {
		ll x=v[i].first.first, y=v[i].first.second;
 		if (now.second*x>=now.first*y) {
			now=v[i].second;
			ans++;
		}
	}
	cout << ans;

	return 0;
}
