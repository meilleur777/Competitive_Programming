#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> dp(n+1, INF);
	dp[1]=0;
	auto smi=[&](int& a, int b) {
		a=min(a, b);
	};
	for (int i=2; i<=n; i++) {
		smi(dp[i], dp[i-1]+1);
		if (i%3==0) smi(dp[i], dp[i/3]+1);
		if (i%2==0) smi(dp[i], dp[i/2]+1);
	}
	cout << dp[n];

	return 0;
}
