#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(2*m+1);
	auto rev=[&](int k) {return 2*m-k;};
	while (n--) {
		int a, b;
		cin >> a >> b;
		a+=m, b+=m;
		edge[rev(a)].push_back(b);
		edge[rev(b)].push_back(a);
	}
	int num=1;
	stack<int> sk;
	vector<bool> fin(2*m+1, false);
	vector<int> id(2*m+1, -1), par(2*m+1, -1);
	function<int(int)> trj=[&](int now) {
		id[now]=num++;
		sk.push(now);
		int ret=id[now];
		for (auto nxt:edge[now]) {
			if (id[nxt]==-1) ret=min(ret, trj(nxt));
			else if (!fin[nxt]) ret=min(ret, id[nxt]);
		}
		if (ret==id[now]) {
			while (true) {
				int tmp=sk.top()				;
				sk.pop();
				par[tmp]=now;
				fin[tmp]=true;
				if (tmp==now) break;
			}
		}
		return ret;
	};
	rep(i, 2*m+1) if (!fin[i]) trj(i);
	rep(i, m) if (par[i]==par[rev(i)]) {
		cout << "OTL";
		return 0;
	}
	cout << "^_^";

	return 0;
}
