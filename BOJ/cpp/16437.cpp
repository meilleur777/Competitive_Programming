#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> qqq(n);
	vector<vector<int>> edge(n);
	rep(i, n-1) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		c--;
		if (a=='W') b*=-1;
		qqq[i+1]=b;
		edge[c].push_back(i+1);
	}
	function<ll(int)> dfs=[&](int now) {
		ll t=0;
		for (auto nxt:edge[now]) {
			t+=dfs(nxt);
		}
		t+=qqq[now];
		return max(0LL, t);
	};
	cout << dfs(0);

	return 0;
}
