#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<vector<int>> edge(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	int h;
	cin >> h;

	vector<int> dep(n, -1);
	dep[0]=0;

	function<int(int)> getmax=[&](int now) {
		int ret=dep[now];
		for (auto nxt:edge[now]) {
			ret=max(ret, getmax(nxt));
		}
		return ret;
	};

	function<void(int)> maketree=[&](int now) {
		for (auto nxt:edge[now]) {
			dep[nxt]=dep[now]+1;
			maketree(nxt);
		}
	};

	int ans=0;
	function<void(int)> sol=[&](int now) {
		if (getmax(now)>h) {
			ans++;
			dep[now]=1;
			maketree(now);
			for (auto nxt:edge[now]) {
				sol(nxt);
			}
		}
	};

	maketree(0);
	for (int i=1; i<n; i++) {
		if (dep[i]==2) {
			sol(i);
		}
	}
	cout << ans;

	return 0;
}
