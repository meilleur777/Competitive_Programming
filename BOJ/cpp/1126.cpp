#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	vector<vector<int>> dp(n, vector<int>(1e6+10, -1));
	
	int min=-1e7;
	int offset=5e5;
	function<int(int, int)> sol=[&](int num, int dif) {
		if (num==-1) {
			if (dif==0) return 0;
			return min;
		}
		int& ret=dp[num][dif+offset];
		if (ret!=-1) return ret;

		ret=min;
		ret=max(ret, sol(num-1, dif-a[num]));
		ret=max(ret, a[num]+sol(num-1, dif+a[num]));
		ret=max(ret, sol(num-1, dif));
		return ret;
	};

	int ans=sol(n-1, 0);
	ans=(ans<=0?-1:ans);
	cout << ans;

	return 0;
}
