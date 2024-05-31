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

	ll b, c;
	cin >> b >> c;
	vector<pair<ll, ll>> v;
	v.push_back({b-c/2, b});
	v.push_back({-b-(c-1)/2, -b});
	v.push_back({-b, -b+(c-1)/2});
	if (c>=2) v.push_back({b, b+(c-2)/2});
	sort(v.begin(), v.end());
	ll ans=0;
	ll sta=v[0].first, end=v[0].second;
	for (int i=1; i<v.size(); i++) {
		if (end<v[i].first) {
			ans+=end-sta+1;
			sta=v[i].first, end=v[i].second;
		}
		else if (end<v[i].second) {
			end=v[i].second;
		}
	}
	ans+=end-sta+1;
	cout << ans;

	return 0;
}
