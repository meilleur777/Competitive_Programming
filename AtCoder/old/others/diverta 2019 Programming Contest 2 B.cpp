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
	set<pair<ll, ll> > s;
	vector<ll> x(n), y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
		s.insert({x[i], y[i]});
	}
	int ans=n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==j) continue;
			ll p=x[i]-x[j];
			ll q=y[i]-y[j];
			int cnt=0;
			for (int k=0; k<n; k++) {
				if (s.count({x[k]+p, y[k]+q})) cnt++;
			}
			ans=min(ans, n-cnt);
		}
	}
	cout << ans;

	return 0;
}
