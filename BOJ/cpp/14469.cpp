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
	vector<intp> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	int t=v[0].first+v[0].second;
	for (int i=1; i<n; i++) {
		if (v[i].first>t) {
			t=v[i].first+v[i].second;
		}
		else {
			t+=v[i].second;
		}
	}
	cout << t;

	return 0;
}
