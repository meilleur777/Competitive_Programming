#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, r;
	cin >> n >> r;
	r--;
	vector<vector<intp>> edge(n);
	rep(i, n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	vector<int> dep(n, -1);
	int gig=-1;
	function<void(int, int)> sol=[&](int now, int add) {
		dep[now]=add;
		int cnt=0;
		for(auto nxt:edge[now]) {
			cnt+=dep[nxt.first]==-1;
		}
		if (cnt>1 && gig==-1) gig=now;
		for(auto nxt:edge[now]) {
			if (dep[nxt.first]!=-1) continue;
			sol(nxt.first, add+nxt.second);
		}
	};
	sol(r, 0);
	if (gig==-1) {
		gig=max_element(dep.begin(), dep.end())-dep.begin();
	}
	cout << dep[gig] << ' ' << *max_element(dep.begin(), dep.end())-dep[gig];

	return 0;
}
