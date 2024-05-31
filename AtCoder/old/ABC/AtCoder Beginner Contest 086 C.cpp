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
	vector<ll> t(n), x(n), y(n);
	rep(i, n) {
		cin >> t[i] >> x[i] >> y[i];
	}
	ll now=0;
	pair<ll, ll> s={0, 0};
	for (int i=0; i<n; i++) {
		ll dis=llabs(s.first-x[i])+llabs(s.second-y[i]);
		if (dis>t[i]-now) {
			cout << "No";
			return 0;
		}
		else {
			if ((t[i]-now-dis)%2) {
				cout << "No";
				return 0;
			}
			else {
				s={x[i], y[i]};
				now=t[i];
			}
		}
	}
	cout << "Yes";

	return 0;
}
