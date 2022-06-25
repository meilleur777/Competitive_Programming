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
	vector<vector<int>> a(4, vector<int>(n));
	rep(i, n) rep(j, 4) cin >> a[j][i];
	vector<vector<int>> b(2);
	for (int k=0; k<2; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				b[k].push_back({a[k*2][i]+a[k*2+1][j]});
			}
		}
	}
	rep(i, 2) sort(b[i].begin(), b[i].end());
	ll ans=0;
	for (auto i:b[0]) {
		auto hi=upper_bound(b[1].begin(), b[1].end(), -i);
		auto lo=lower_bound(b[1].begin(), b[1].end(), -i);
		ans+=hi-lo;
	}
	cout << ans;

	return 0;
}
