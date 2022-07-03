#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	int ans=1;
	for (int i=-99; i<=99; i++) {
		if (!i) continue;
		vector<int> dp(101, 0);
		for (int j=0; j<n; j++) {
			dp[a[j]]=max(dp[a[j]], 1);
			int t=a[j]-i;
			if (t>=1 && t<=100) dp[a[j]]=max(dp[a[j]], dp[t]+1);
		}
		rep(j, 101) ans=max(ans, dp[j]);
	}

	vector<int> cnt(101, 0);
	rep(i, n) cnt[a[i]]++;
	ans=max(ans, *max_element(cnt.begin(), cnt.end()));

	cout << ans;

	return 0;
}
