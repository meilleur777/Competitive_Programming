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
	cin >> n;
	map<string, int> s, t;
	rep(i, n) {
		string x;
		cin >> x;
		s[x]++;
	}
	cin >> m;
	rep(i, m) {
		string x;
		cin >> x;
		t[x]++;
	}
	int ans=0;
	for (auto [a, b]:s) {
		ans=max(ans, b-t[a]);
	}
	cout << ans;

	return 0;
}
