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

	int n, a, b;
	cin >> n >> a >> b;
	int ans=0;
	for (int i=1; i<=n; i++) {
		string tmp=to_string(i);
		int sum=0;
		for (auto j:tmp) {
			sum+=j-'0';
		}
		if (sum>=a && sum<=b) ans+=i;
	}
	cout << ans;

	return 0;
}
