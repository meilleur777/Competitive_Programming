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

	int n, m;
	cin >> n >> m;
	vector<bool> chk(n+1, false);
	vector<int> pen(n+1, 0);
	rep(i, m) {
		int p;
		string s;
		cin >> p >> s;
		if (s=="AC") {
			chk[p]=true;
		}
		else {
			if (!chk[p]) pen[p]++;
		}
	}
	int psu=0, acs=0;
	for (int i=1; i<=n; i++) {
		if (chk[i]) {
			acs++;
			psu+=pen[i];
		}
	}
	cout << acs << ' ' << psu;

	return 0;
}
