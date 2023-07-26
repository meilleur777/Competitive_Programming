#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string s;
	cin >> s;
	int mod=1e4+7;
	vector<vector<int>> dp((int)s.size(), vector<int>((int)s.size(), -1));
	function<int(int, int)> sol=[&](int left, int right) {
		if (left+1==right) {
			if (s[left]==s[right]) return 3;
			else return 2;
		}
		if (left==right) return 1;
		int& ret=dp[left][right];
		if (ret!=-1) return ret;

		ret=sol(left+1, right)+sol(left, right-1)-sol(left+1, right-1);
		if (s[left]==s[right]) {
			ret+=1+sol(left+1, right-1);
		}
		return ret=(ret+mod)%mod;
	};
	cout << sol(0, (int)s.size()-1) << '\n';

	return 0;
}
