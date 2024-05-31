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

const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N, K;
	cin >> N >> K;
	vector<int> h(N);
	rep(i, N) cin >> h[i];
	vector<int> dp(N, INF);
	dp[0]=0;
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N && j<=i+K; j++) {
			dp[j]=min(dp[j], dp[i]+abs(h[i]-h[j]));
		}
	}
	cout << dp[N-1];

	return 0;
}
