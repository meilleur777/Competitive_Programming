#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(2*n);
	rep(i, 2*n) cin >> a[i];
	vector<intp> v(2*n);
	rep(i, 2*n) {
		v[i].first=0;
		v[i].second=i;
	}
	auto win=[&](int r, int c, int d) {
		char cc=a[c][r];
		char dd=a[d][r];
		// cout << cc << ' ' << dd << '\n';
		if (cc==dd) return -1;
		if (cc=='G' && dd=='C') return c;
		if (cc=='C' && dd=='P') return c;
		if (cc=='P' && dd=='G') return c;
		return d;
	};
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			// cout << v[2*j].second << ' ' << v[2*j+1].second << '\n';
			int who=win(i, v[2*j].second, v[2*j+1].second);
			if (who==-1) continue;
			if (who==v[2*j].second) v[2*j].first++;
			if (who==v[2*j+1].second) v[2*j+1].first++;
		}
		// rep(i, 2*n) cout << v[i].first << ' ' << v[i].second << '\n';
		sort(v.begin(), v.end(), [](intp& a, intp& b){
			if (a.first==b.first) return a.second<b.second;
			return a.first>b.first;
		});
	}
	rep(i, 2*n) cout << v[i].second+1 << '\n';

	return 0;
}
