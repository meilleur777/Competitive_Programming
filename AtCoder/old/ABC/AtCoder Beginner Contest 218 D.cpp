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
	set<intp> s;
	vector<intp> v(n);
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		v[i]={x, y};
		s.insert({x, y});
	}
	ll ans=0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (v[i].first==v[j].first || v[j].second==v[i].second) continue;
			if (s.count({v[i].first, v[j].second})>0 && s.count({v[j].first, v[i].second})>0) {
			//cout << v[i].first << ' ' << v[j].second << ' ' << v[j].first << ' ' << v[i].second << '\n';
				ans++;
			}
		}
	}
	cout << ans/2;

	return 0;
}
