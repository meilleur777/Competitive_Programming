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

	int N;
	cin >> N;
	vector<ll> A(N+1);
	vector<vector<ll> > dp(N+1, vector<ll>(N+1, 1e14));
	rep(i, N) cin >> A[i+1];
	for (int i=1; i<=N; i++) {
		dp[i][i]=0;
		A[i]+=A[i-1];
	}
	for (int i=1; i<N; i++) {
		for (int j=1; j+i<=N; j++) {
			for (int k=j; k<j+i; k++) {
				dp[j][j+i]=min(dp[j][j+i], dp[j][k]+dp[k+1][j+i]+A[j+i]-A[j-1]);
			}
		}
	}
	cout << dp[1][N];

	return 0;
}
