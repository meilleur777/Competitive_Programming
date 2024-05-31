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

const int mod=998244353;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N;
	cin >> N;
	vector<intp> C(N);
	rep(i, N) cin >> C[i].first;
	rep(i, N) cin >> C[i].second;
    sort(C.begin(), C.end());
    ll ans = 0;
    vector<ll> dp(5e3+1, 0);
    dp[0] = 1;
    for (auto [a, b] : C) {
        for (int i=0; i+b<=a; i++) {
        	ans+=dp[i];
        	ans%=mod;
        }
        for (int i=5e3; i>=b; i--) {
        	dp[i]+=dp[i-b];
        	dp[i]%=mod;
        }
    }
    cout << ans;

	return 0;
}
