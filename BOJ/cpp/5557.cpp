#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<vector<ll>> dp(n, vector<ll>(21, -1));
	function<ll(int, int)> sol=[&](int now, int sum) {
		if (now==n-1) {
			if (sum==a[now]) return 1LL;
			else return 0LL;
		}
		ll& ret=dp[now][sum];
		if (ret!=-1) return ret;
		ret=0;
		if (sum+a[now]<=20 && sum+a[now]>=0) ret+=sol(now+1, sum+a[now]);
		if (sum-a[now]<=20 && sum-a[now]>=0) ret+=sol(now+1, sum-a[now]);
		return ret;
	};

	cout << sol(1, a[0]);

	return 0;
}
