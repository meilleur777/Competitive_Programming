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

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> dp(n+1, INF);
	dp[n]=0;
	for (int i=n; i>0; i--) {
		dp[i-1]=min(dp[i-1], dp[i]+1);
		for (int j=1; j<9; j++) {
			int tmp=(int)pow(6, j);
			if (tmp>i) break;
			dp[i-tmp]=min(dp[i-tmp], dp[i]+1);
		}
		for (int j=1; j<8; j++) {
			int tmp=(int)pow(9, j);
			if (tmp>i) break;
			dp[i-tmp]=min(dp[i-tmp], dp[i]+1);
		}
	}
	cout << dp[0];

	return 0;
}
