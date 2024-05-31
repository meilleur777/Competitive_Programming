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
	vector<intp> v(m);
	rep(i, m) {
		cin >> v[i].second >> v[i].first;
		v[i].first--;
	}
	sort(v.begin(), v.end());
	int now=-1;
	int ans=0;
	for (int i=0; i<m; i++) {
		if (now<v[i].second) {
			ans++;
			now=v[i].first;
		}
	}
	cout << ans;

	return 0;
}
