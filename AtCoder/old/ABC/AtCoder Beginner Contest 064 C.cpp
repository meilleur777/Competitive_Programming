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
	vector<int> cnt(9, 0);
	rep(i, n) {
		int x;
		cin >> x;
		x=min(x/400, 8);
		cnt[x]++;
	}
	int ans=0;
	for (int i=0; i<8; i++) {
		ans+=cnt[i]>0;
	}
	if (ans>0) {
		cout << ans;
	}
	else {
		if (cnt[8]) cout << 1;
		else cout << 0;
	}
	cout << ' ' << ans+cnt[8];

	return 0;
}
