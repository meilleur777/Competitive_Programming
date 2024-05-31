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

const int mod = 1e9+7;

int main() {
	init_code();

	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	vector<int> cnt = {0, 0, 0};
	ll ans = 1;
	for (int i = 0; i < N; i++) {
		auto temp = find(cnt.begin(), cnt.end(), A[i]);
		if (temp == cnt.end()) {
			cout << '0';
			return 0;
		}
		else {
			ans *= upper_bound(cnt.begin(), cnt.end(), A[i]) -
					lower_bound(cnt.begin(), cnt.end(), A[i]);
			ans %= mod;
			cnt[temp-cnt.begin()]++;
		}
		sort(cnt.begin(), cnt.end());
	}
	cout << ans;

	return 0;
}
