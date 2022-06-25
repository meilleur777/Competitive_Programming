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
	vector<int> s(n);
	rep(i, n) cin >> s[i];
	vector<bool> dp(1e5+1, false);
	dp[0]=true;
	for (int i=0; i<n; i++) {
		for (int j=1e5; j>=s[i]; j--) {
			if (dp[j-s[i]]) dp[j]=true;
		}
	}
	for (int i=1e5; i>=0; i--) {
		if (i%10!=0 && dp[i]) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0;

	return 0;
}
