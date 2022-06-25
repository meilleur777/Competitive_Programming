#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(2*n+1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a+=n, b+=n;
		edge[2*n-a].push_back(b);
		edge[2*n-b].push_back(a);
	}
	int num=1;
	stack<int> sk;
	vector<int> par(2*n+1, -1), mem(2*n+1, -1);
	vector<bool> fin(2*n+1, false);
	function<int(int)> trj=[&](int now) {
		mem[now]=num;
		num++;
		sk.push(now);
		int ret=mem[now];
		for (auto nxt:edge[now]) {
			if (mem[nxt]==-1) ret=min(ret, trj(nxt));
			else if (!fin[nxt]) ret=min(ret, mem[nxt]);
		}
		if (ret==mem[now]) {
			while (true) {
				int tmp=sk.top();
				sk.pop();
				fin[tmp]=true;
				par[tmp]=now;
				if (tmp==now) break;
			}
		}
		return ret;
	};
	rep(i, 2*n+1) if (!fin[i]) trj(i);
	rep(i, n) {
		if (par[i]==par[2*n-i]) {
			cout << 0;
			return 0;
		}
	}	
	cout << 1;

	return 0;
}
