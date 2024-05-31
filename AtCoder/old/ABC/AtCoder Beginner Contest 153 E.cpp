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

	int h, n;
	cin >> h >> n;
	vector<int> dp(h+1, INF);
	dp[0]=0;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		rep(j, h) {
			int t=min(j+a, h);
			dp[t]=min(dp[t], dp[j]+b);
		}
	}
	cout << dp[h];

	return 0;
}
