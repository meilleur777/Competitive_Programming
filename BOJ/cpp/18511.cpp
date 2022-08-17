#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> k(m);
	rep(i, m)  cin >> k[i];

	int ans=-1;
	function<void(string, int)> sol=[&](string now, int num) {
		if (num>=1 && num<=(int)n.size()) {
			if (stoi(n)>=stoi(now)) {
				ans=max(ans, stoi(now));
			}
			if (num==(int)n.size()) return;
		}

		for (int nxt=0; nxt<m; nxt++) {
			sol(now+char(k[nxt]+'0'), num+1);
		}
	};
	sol("", 0);
	cout << ans;

	return 0;
}
