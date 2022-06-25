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

const int INF=0X3F3F3F3F;

int main() {
	init_code();

	int N;
	cin >> N;
	vector<int> h(N+1);
	vector<int> dp(N+1, INF);
	rep(i, N) cin >> h[i+1];
	dp[0]=dp[1]=0;
	dp[2]=abs(h[2]-h[1]);
	for (int i=3; i<=N; i++) {
		dp[i]=min(dp[i], min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2])));
	}
	cout << dp[N];

	return 0;
}
