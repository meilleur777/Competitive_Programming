#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	while (true) {
		int M, N;
		cin >> M >> N;
		if (!M) break;
		vector<vector<int> > A(M+1, vector<int>(N+1));
		rep(i, M) rep(j, N) cin >> A[i+1][j+1];
		vector<vector<int> > dp(M+1, vector<int>(N+1, 0));
		for (int i=1; i<=M; i++) {
			dp[i][1]=A[i][1];
			for (int j=2; j<=N; j++) {
				dp[i][j]=max(dp[i][j-1], A[i][j]+dp[i][j-2]);
			}
			if (i==1) continue;
			dp[i][N]=max(dp[i-1][N], dp[i][N]+dp[i-2][N]);
		}
		cout << dp[M][N] << '\n';
	}

	return 0;
}
