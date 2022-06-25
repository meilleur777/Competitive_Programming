#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int v, e;
	cin >> v >> e;
	vector<vector<int>> edge(v);
	rep(i, e) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
	}
	vector<vector<int>> scc;
	vector<int> a(v, -1);
	vector<bool> fin(v, false);
	stack<int> sk;
	int num=1;
	function<int(int)> trj=[&](int now) {
		a[now]=num;
		num++;
		sk.push(now);
		int par=a[now];
		for (auto nxt:edge[now]) {
			if (a[nxt]==-1) par=min(par, trj(nxt));
			else if (!fin[nxt]) par=min(par, a[nxt]);
		}
		if (par==a[now]) {
			vector<int> tmp;
			while (true) {
				int ww=sk.top();
				sk.pop();
				tmp.push_back(ww);
				fin[ww]=true;
				if (ww==now) break;
			}
			sort(tmp.begin(), tmp.end());
			scc.push_back(tmp);
		}
		return par;
	};
	rep(i, v) if (!fin[i]) trj(i);
	cout << (int)scc.size() << '\n';
	sort(scc.begin(), scc.end());
	for (auto i:scc) {
		for (auto j:i) {
			cout << j+1 << ' ';
		}
		cout << "-1\n";
	}

	return 0;
}
