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

	ll n;
	cin >> n;
	vector<ll> ans;
	for (ll i=1; i*i<=n; i++) {
		if (i*i==n) {
			ans.push_back(i);
		}
		else if (n%i==0) {
			ans.push_back(i);
			ans.push_back(n/i);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto i:ans) cout << i << '\n';

	return 0;
}
