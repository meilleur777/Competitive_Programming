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
	vector<vector<int> > a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	vector<pair<intp, intp> > res;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w-1; j++) {
			if (a[i][j]%2==0) continue;
			res.push_back({{i, j}, {i, j+1}});
			a[i][j]--;
			a[i][j+1]++;
		}	
	}
	for (int i=0; i<h-1; i++) {
		if (a[i][w-1]%2) {
			res.push_back({{i, w-1}, {i+1, w-1}});
			a[i][w-1]--;
			a[i+1][w-1]++;
		}
	}
	cout << res.size() << '\n';
	for (auto [a, b]:res) {
		cout << a.first+1 << ' ' << a.second+1 << ' ' << b.first+1 << ' ' << b.second+1 << '\n';
	}
	/*cout << '\n';
	for (auto i:a) {
		for (auto j:i) {
			cout << j << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}
