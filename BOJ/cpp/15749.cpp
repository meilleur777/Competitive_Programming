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

	int n, b;
	cin >> n >> b;
	vector<int> f(n), s(b), d(b);
	rep(i, n) cin >> f[i];
	rep(i, b) cin >> s[i] >> d[i];
	vector<vector<bool>> dp(n, vector<bool>(b, false));
	for (int i=0; i<b; i++) dp[0][i]=true;
	for (int i=1; i<n; i++) {
		for (int j=0; j<b; j++) {
			if (dp[i][j]) continue;
			if (f[i]>s[j]) continue;
			for (int k=i-1; k>=0 && k>=i-d[j]; k--) {
				if (dp[k][j]) {
					for (int l=j; l<b; l++) {
						if (f[i]<=s[l]) dp[i][l]=true;
					}
					break;
				}
			}
		}
	}
	for (int i=0; i<b; i++) {
		if (dp[n-1][i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}
