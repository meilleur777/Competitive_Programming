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

	int n, k, q;
	cin >> n >> k >> q;
	vector<int> cnt(n, 0);
	rep(i, q) {
		int a;
		cin >> a;
		cnt[a-1]++;
	}
	for (auto i:cnt) {
		if (k+i-q>0) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
