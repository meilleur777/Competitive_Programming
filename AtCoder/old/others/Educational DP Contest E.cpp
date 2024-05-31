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

	int N, W;
	cin >> N >> W;
	vector<int>	w(N), v(N);
	rep(i, N) cin >> w[i] >> v[i];
	int vsum=0;
	rep(i, N) vsum+=v[i];
	//dp[a]::=the minimum sum of the weights when the sum of the values of items is exactly a
	vector<ll> dp(vsum+1, 1e12);
	dp[0]=0;
	rep(i, N) {
		for (int j=vsum-v[i]; j>=0; j--) {
			dp[j+v[i]]=min(dp[j+v[i]], dp[j]+w[i]);
		}
	}
	for (int i=vsum; i>=0; i--) {
		if (dp[i]<=W) {
			cout << i;
			return 0;
		}
	}

	return 0;
}
