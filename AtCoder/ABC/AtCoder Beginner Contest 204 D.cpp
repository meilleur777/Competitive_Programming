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
	vector<bool> dp(1e5+1, 0);
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	int sum=0;
	dp[0]=true;
	for (int i=0; i<n; i++) {
		sum+=t[i];
		for (int j=1e5-t[i]; j>=0; j--) {
			if (dp[j]) {
				dp[j+t[i]]=true;
			}
		}
	}
	int ans=0;
	for (int i=0; i<=1e5; i++) {
		if (dp[i] && abs(sum/2-i)<abs(sum/2-ans)) {
			ans=i;
		}
	}
	cout << max(ans, sum-ans);

	return 0;
}
