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
const ll INF=0x3F3F3F3F3F3F3F3F;

int main() {
	init_code();

	int n;
	cin >> n;
	vector<vector<int>> f(n, vector<int>(10));
	rep(i, n) rep(j, 10) cin >> f[i][j];
	vector<vector<int>> p(n, vector<int>(11));
	rep(i, n) rep(j, 11) cin >> p[i][j];
	ll ans=-INF;
	for (int i=1; i<(1<<10); i++) {
		ll tmp=0;
		for (int j=0; j<n; j++) {
			int cnt=0;
			for (int k=0; k<10; k++) {
				if ((i&(1<<k)) && f[j][k]) {
					cnt++;
				}
			}
			tmp+=p[j][cnt];
		}
		ans=max(ans, tmp);
	}
	cout << ans;

	return 0;
}
