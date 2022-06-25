#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

	int S;
	cin >> S;
	vector<ll> dp(S+1, 0);
	for (int i=3; i<=S; i++) {
		dp[i]+=1;
		for (int j=3; i+j<=S; j++) {
			dp[i+j]+=dp[i];
			dp[i+j]%=mod;
		}
	}
	cout << dp[S];

	return 0;
}
