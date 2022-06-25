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

	ll n, d;
	cin >> n >> d;
	vector<ll> x(n), y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
	}
	vector<ll> dis(n);
	for (int i=0; i<n; i++) {
		ll tmp=x[i]*x[i]+y[i]*y[i];
		dis[i]=tmp;
	}
	ll ans=0;
	for (int i=0; i<n; i++) {
		if (dis[i]<=d*d) ans++;
	}
	cout << ans;

	return 0;
}
