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

const ll mod=998244353;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(10, vector<ll>(n, 0)));
	dp[0][a[0]][0]=1;
	// dp[1][a[0]][0]=1;
	for (int i=1; i<n; i++) {
		for (int k=0; k<10; k++) {
			dp[0][(k+a[i])%10][i]+=dp[0][k][i-1]+dp[1][k][i-1];
			dp[0][(k*a[i])%10][i]+=dp[0][k][i-1]+dp[1][k][i-1];
			dp[0][(k+a[i])%10][i]%=mod;
			dp[0][(k*a[i])%10][i]%=mod;
		}
	}
	rep(k, 10) {
		cout << (dp[0][k][n-1]+dp[1][k][n-1])%mod << '\n';
	}

	return 0;
}
