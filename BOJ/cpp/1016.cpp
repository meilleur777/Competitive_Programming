#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	ll start, end;
	cin >> start >> end;
	vector<bool> chk(end-start+1, true);
	for (ll i = 2; i*i <= end; i++) {
		ll temp = ((start+i*i-1)/(i*i))*i*i;
		for (ll j = temp; j <= end; j += i*i) {
			chk[j - start] = false;
		}
	}
	int ans = 0;
	for (auto i : chk) {
		ans += i;
	}
	cout << ans;

	return 0;
}
