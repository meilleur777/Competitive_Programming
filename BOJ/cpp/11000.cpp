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

	int n;
	cin >> n;
	map<int, int> mp;
	rep(i, n) {
		int s, t;
		cin >> s >> t;
		mp[s]++;
		mp[t]--;
	}
	int ans=0;
	int now=0;
	for (auto [a, b]:mp) {
		now+=b;
		ans=max(ans, now);
	}
	cout << ans;

	return 0;
}
