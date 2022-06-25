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
	vector<intp> peo(n), tmp;
	rep(i, n) cin >> peo[i].first >> peo[i].second;
	int d;
	cin >> d;
	for (auto& [a, b]:peo) {
		if (a>b) swap(a, b);
		if (b-a>d) continue;
		tmp.push_back({a, 1});
		tmp.push_back({b-d, -1});
	}
	sort(tmp.begin(), tmp.end());
	int cnt=0;
	int ans=0;
	for (auto [a, b]:tmp) {
		cnt-=b;
		ans=max(ans, cnt);
	}
	cout << ans;

	return 0;
}
