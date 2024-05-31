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
	vector<vector<int>> a(n, vector<int>(n, -1));
	rep(i, n) {
		int w;
		cin >> w;
		rep(j, w) {
			int x, y;
			cin >> x >> y;
			x--;
			a[i][x]=y;
		}
	}
	int ans=0;
	for (int i=1; i<(1<<n); i++) {
		bool ok=true;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				for (int k=0; k<n; k++) {
					if (a[j][k]==1) {
						if ((i&(1<<k))==0) ok=false;
					}
					else if (a[j][k]==0) {
						if (i&(1<<k)) ok=false;
					}
				}
			}
		}
		if (ok) ans=max(ans, __builtin_popcount(i));
	}
	cout << ans;

	return 0;
}
