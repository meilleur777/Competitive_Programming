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

	int K, S;
	cin >> K >> S;
	ll ans=0;
	for (int i=0; i<=K; i++) {
		for (int j=0; j<=min(K, S-i); j++) {
			if (S-i-j>=0 && S-i-j<=K) ans++;
		}
	}
	cout << ans;

	return 0;
}
