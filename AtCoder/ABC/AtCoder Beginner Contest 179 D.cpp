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

const int mod=998244353;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	ll N, K;
	cin >> N >> K;
	vector<pair<ll, ll> > seg;
	rep(i, K) {
		ll l, r;
		cin >> l >> r;
		seg.push_back({l, r});
	}
	sort(seg.begin(), seg.end());
	vector<ll> dp(N+1, 0);
	dp[1]=1;
	dp[2]=-1;	
	for (int i=1; i<=N; i++) {
		dp[i]+=dp[i-1];
		dp[i]%=mod;
		for (auto [a, b]:seg) {
			if (i+a<=N) {
				dp[i+a]+=dp[i];
				dp[i+a]%=mod;
			}
			if (i+b+1<=N) {
				dp[i+b+1]-=dp[i];
				dp[i+b+1]%=mod;
			}
		}
	}
	if (dp[N]<0) dp[N]+=mod;
	cout << dp[N];

	return 0;
}
