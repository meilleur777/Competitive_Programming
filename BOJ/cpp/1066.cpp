#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, a;
	cin >> n >> a;
	if (a>9) {
		cout << 0;
		return 0;
	}

	int mod=1e9+7;

	vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(a+1, vector<vector<int>>(10, vector<int>(11, -1))));
	function<int(int, int, int, int)> sol=[&](int now, int rem, int last, int d) {
		if (now==n) {
			if (rem==1) return 1;
			else return 0;
		}
		int& ret=dp[now][rem][last][d];
		if (ret!=-1) return ret;

		ret=0;
		if (d==10) {
			for (int nxt=last; nxt<10; nxt++) {
				ret+=sol(now+1, rem, nxt, nxt-last);
				ret%=mod;
			}
		}
		else {
			for (int nxt=last; nxt<10; nxt++) {
				if (last+d==nxt) {
					ret+=sol(now+1, rem, nxt, d);
					ret%=mod;
				}
				else if (rem>1) {
					ret+=sol(now+1, rem-1, nxt, 10);
					ret%=mod;
				}
			}
		}
		return ret;
	};

	int ans=0;
	for (int start=1; start<10; start++) {
		ans+=sol(1, a, start, 10);
		ans%=mod;
	}
	cout << ans;

	return 0;
}
