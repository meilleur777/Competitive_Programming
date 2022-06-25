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

	int h, w;
	cin >> h >> w;
	vector<vector<int>> c(10, vector<int>(10));
	rep(i, 10) rep(j, 10) cin >> c[i][j];
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<10; k++) {
				c[j][k]=min(c[j][k], c[j][i]+c[i][k]);
			}
		}
	}
	ll ans=0;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (a[i][j]==-1) continue;
			ans+=c[a[i][j]][1];
		}
	}
	cout << ans;

	return 0;
}
