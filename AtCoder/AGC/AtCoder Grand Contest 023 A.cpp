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
	ll psum=0;
	int ans=0;
	map<ll, int> m;
	m[0]++;
	rep(i, n) {
		int x;
		cin >> x;
		psum+=x;
		ans+=m[psum];
		m[psum]++;
	}
	cout << ans;

	return 0;
}
