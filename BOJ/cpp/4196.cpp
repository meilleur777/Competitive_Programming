#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> edge(n);
		rep(i, m) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			edge[x].push_back(y);
		}
		int num=1;
		stack<int> sk;
		vector<int> par(n, -1), a(n, -1), scc;
		vector<bool> fin(n, false);
		function<int(int)> trj=[&](int now) {
			a[now]=num;
			num++;
			sk.push(now);
			int ret=a[now];
			for (auto nxt:edge[now]) {
				if (a[nxt]==-1) ret=min(ret, trj(nxt));
				else if (!fin[nxt]) ret=min(ret, a[nxt]);
			}
			if (ret==a[now]) {
				scc.push_back(now);
				while (true) {
					int ww=sk.top();
					sk.pop();
					par[ww]=now;
					fin[ww]=true;
					if (ww==now) break;
				}
			}
			return ret;
		};
		rep(i, n) if (!fin[i]) trj(i);
		vector<int> ind(n, 0);
		for (int i=0; i<n; i++) {
			for (auto j:edge[i]) {
				if (par[i]!=par[j]) ind[par[j]]++;
			}
		}
		set<int> st;
		for (int i=0; i<n; i++) {
			if (ind[par[i]]==0) st.insert(par[i]);
		}
		cout << (int)st.size() << '\n';
	}

	return 0;
}
