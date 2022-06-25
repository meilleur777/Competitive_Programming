#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int k, n;
	cin >> k >> n;
	// red=true, blue=false;
	// blue:0~k-1, red:k+1~2*k;
	int siz=2*k+1;
	vector<vector<int>> edge(siz);
	rep(i, n) {
		int a, b, c;
		char ac, bc, cc; 
		cin >> a >> ac >> b >> bc >> c >> cc;
		if (ac=='R') a+=k;
		else a=k-a;
		if (bc=='R') b+=k;
		else b=k-b;
		if (cc=='R') c+=k;
		else c=k-c;
		edge[2*k-a].push_back(b);
		edge[2*k-b].push_back(a);
		edge[2*k-b].push_back(c);
		edge[2*k-c].push_back(b);
		edge[2*k-c].push_back(a);
		edge[2*k-a].push_back(c);
	}
	int num=1, sccnum=1;
	stack<int> sk;
	vector<bool> fin(siz, false);
	vector<int> par(siz, -1), mem(siz, -1);
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
	rep(i, k) if (!fin[i+k+1]) trj(i+k+1);
	rep(i, k) if (!fin[2*k-(i+k+1)]) trj(2*k-(i+k+1));
	bool flag=true;
	rep(i, k) {
		if (par[i]==par[2*k-i]) {
			flag=false;
			break;
		}
	}
	if (!flag) cout << -1;
	else {
		rep(i, k) {
			cout << (par[i+k+1]<par[2*k-(i+k+1)]?'R':'B');
		}
	}

	return 0;
}
