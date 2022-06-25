#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<intp> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	vector<vector<int>> dp(n, vector<int>(n, -1));
	function<int(int, int)> sol=[&](int sta, int ed) {
		if (sta==ed) return 0;
		int& ret=dp[sta][ed];
		if (ret!=-1) return ret;
		ret=INT_MAX;
		for (int i=sta; i<ed; i++) {
			ret=min(ret, v[sta].first*v[i].second*v[ed].second+sol(sta, i)+sol(i+1, ed));
		}
		return ret;
	};
	cout << sol(0, n-1);

	return 0;
}
