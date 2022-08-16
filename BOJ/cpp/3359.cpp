#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;

	vector<vector<int>> dp(1e3, vector<int>(1e3+1, -1));
	function<int(int, int)> sol=[&](int now, int last) {
		if (now==n) {
			return 0;
		}
		int& ret=dp[now][last];
		if (ret!=-1) return ret;
		ret=0;
		int tmp1=abs(a[now].first-last)+a[now].second+sol(now+1, a[now].first);
		int tmp2=abs(a[now].second-last)+a[now].first+sol(now+1, a[now].second);
		return ret=max(tmp1, tmp2);
	};
	cout << max(sol(1, a[0].first)+a[0].second, sol(1, a[0].second)+a[0].first);

	return 0;
}
