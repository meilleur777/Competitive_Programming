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

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N;
	cin >> N;
	vector<vector<int> > A(3, vector<int>(N));
	rep(i, N) rep(j, 3) cin >> A[j][i];
	vector<vector<int> > dp(3, vector<int>(N, -INF));
	for (int i=0; i<3; i++) {
		dp[i][0]=A[i][0];
	}
	for (int i=1; i<N; i++) {
		for (int j=0; j<3; j++) {
			for (int k=0; k<3; k++) {
				if (j==k) continue;
				dp[k][i]=max(dp[k][i], dp[j][i-1]+A[k][i]);
			}
		}
	}
	cout << max({dp[0][N-1], dp[1][N-1], dp[2][N-1]});

	return 0;
}
