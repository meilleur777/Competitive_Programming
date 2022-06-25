#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> edge(2*n+1);
		rep(i, m) {
			int a, b;
			cin >> a >> b;
			a+=n, b+=n;
			edge[2*n-a].push_back(b);
			edge[2*n-b].push_back(a);
		}
		edge[n-1].push_back(n+1);
		int num=1, sccnum=1;
		stack<int> sk;
		vector<bool> fin(2*n+1, false);
		vector<int> par(2*n+1, -1), mem(2*n+1, -1);
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
					par[tmp]=sccnum;
					fin[tmp]=true;
					if (tmp==now) break;
				}
				sccnum++;
			}
			return ret;
		};
		rep(i, n) if (!fin[i+n+1]) trj(i+n+1);
		rep(i, n) if (!fin[2*n-(i+n+1)]) trj(2*n-(i+n+1));
		bool flag=true;
		rep(i, n) {
			if (par[i]==par[2*n-i]) {
				flag=false;
				break;
			}
		}
		flag=flag&&par[n-1]>par[n+1];
		if (flag) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
