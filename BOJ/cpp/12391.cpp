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
	vector<int> b(n);
	rep(i, n) cin >> b[i];
	int ans=0;
	auto chk=[&]() {
		bool ok=true;
		for (auto i:b) {
			if (i) ok=false;
		}
		return ok;
	};
	while (true) {
		for (int i=0; i<n; i++) {
			if (b[i]%2) {
				b[i]--;
				ans++;
			}
		}
		if (chk()) break;
		for (int i=0; i<n; i++) {
			if (b[i]!=1) b[i]/=2;
		}
		ans++;
		if (chk()) break;
	}
	cout << ans;

	return 0;
}
