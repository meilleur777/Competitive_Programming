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

	ll H, W;
	cin >> H >> W;
	if (H == 1 || W == 1) {
		cout << 1;
		return 0;
	} 
	if (H%2) {
		if (W%2) {
			cout << W*(H/2)+(W/2)+1;
		}
		else {
			cout << W*(H/2)+(W/2);
		}
	}
	else {
		if (W%2) {
			cout << W*(H/2);
		}
		else {
			cout << W*(H/2);
		}
	}

	return 0;
}
