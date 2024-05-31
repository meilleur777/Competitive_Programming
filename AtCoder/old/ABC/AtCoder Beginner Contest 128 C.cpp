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
	vector<vector<bool> > but(m, vector<bool>(n, false));
	rep(i, m) {
		int k;
		cin >> k;
		while (k--) {
			int s;
			cin >> s;
			s--;
			but[i][s]=true;
		}
	}
	vector<int> p(m);
	rep(i, m) cin >> p[i];
	int ans=0;
	for (int i=0; i<(1<<n); i++) {
		bool flag=true;
		for (int j=0; j<m; j++) {
			int cnt=0;
			for (int k=0; k<n; k++) {
				if (i&(1<<k) && but[j][k]) {
					cnt++;
				}
			}
			if (cnt%2!=p[j]%2) {
				flag=false;
				break;
			}
		}
		if (flag) ans++;
	}
	cout << ans;

	return 0;
}
