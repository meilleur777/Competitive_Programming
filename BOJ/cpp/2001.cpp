#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;

	int mod=1e6;
	vector<int> dp((int)s.size(), -1);
	function<int(int)> sol=[&](int now) {
		if (now==(int)s.size()) return 1;
		int& ret=dp[now];
		if (ret!=-1) return ret;
		if (s[now]=='0') return 0;
		ret=sol(now+1);
		if (now+1<(int)s.size() && stoi(s.substr(now, 2))<=26) {
			ret+=sol(now+2);
			ret%=mod;
		}
		return ret;
	};

	cout << sol(0)%mod;

	return 0;
}
