#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

	ll N;
	cin >> N;
	vector<ll> fac;
	for (ll i=1; i*i<=N; i++) {
		if (N%i==0) {
			fac.push_back(i);
		}
	}
	int ans=INF;
	for (int i=0; i<fac.size(); i++) {
		string a=to_string(fac[i]);
		string b=to_string(N/fac[i]);
		ans=min(ans, max((int)a.size(), (int)b.size()));
	}
	cout << ans;

	return 0;
}
