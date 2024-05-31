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
const ll INF=1e16;

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(3));
	rep(i, n) rep(j, 3) cin >> a[i][j];
	ll ans=0;
	for (int i=0; i<(1<<3); i++) {
		vector<ll> v;
		for (int k=0; k<n; k++) {
			ll tmp=0;
			for (int j=0; j<3; j++) {
				if (i&(1<<j)) {
					tmp+=a[k][j];
				}
				else tmp-=a[k][j];
			}
			v.push_back(tmp);
		}	
		sort(v.begin(), v.end(), greater<ll>());
		ll tmp=0;
		for (int j=0; j<m; j++) {
			tmp+=v[j];
		}
		ans=max(ans, tmp);
	}
	cout << ans;

	return 0;
}
