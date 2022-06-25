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

	ll k;
	cin >> k;
	ll now=7%k;
	for (int i=1; i<=k+10; i++) {
		if (now==0) {
			cout << i;
			return 0;
		}
		now=(now*10+7)%k;
	}
	cout << -1;

	return 0;
}
