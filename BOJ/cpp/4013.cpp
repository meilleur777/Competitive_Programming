#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
	}
	vector<int> mny(n);
	rep(i, n) cin >> mny[i];
	int s, p;
	cin >> s >> p;
	s--;
	vector<bool> res(n, false);
	rep(i, p) {
		int a;
		cin >> a;
		a--;
		res[a]=true;
	}
	int nn=1;
	vector<int> num(n, -1), par(n, -1);
	vector<bool> fin(n, false);
	stack<int> sk;
	function<int(int)> trj=[&](int now) {
		num[now]=nn;
		nn++;
		sk.push(now);
		int ret=num[now];
		for (auto nxt:edge[now]) {
			if (num[nxt]==-1) ret=min(ret, trj(nxt));
			else if (!fin[nxt]) ret=min(ret, num[nxt]);
		}
		if (ret==num[now]) {
			while (true) {
				int qq=sk.top();
				sk.pop();
				par[qq]=now;
				fin[qq]=true;
				if (qq==now) break;
			}
		}
		return ret;
	};	
	rep(i, n) if (!fin[i]) trj(i);
	rep(i, n) {
		if (par[i]!=i) {
			mny[par[i]]+=mny[i];
			res[par[i]]=res[par[i]]|res[i];
		}
	}
	s=par[s];
	vector<int> cnt(n, 0);
	rep(i, n) {
		for (auto j:edge[i]) {
			if (par[i]!=par[j]) {
				cnt[par[j]]++;
				edge[par[i]].push_back(par[j]);
			}
		}
	}
	queue<int> q;
	vector<int> dp(n, 0);
	rep(i, n) {
		if (par[i]!=i) continue;
		dp[i]=mny[i];
		if (cnt[i]==0) q.push(i);
	}
	s=par[s];
	vector<bool> vis(n, false);
	vis[s]=true;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (auto nxt:edge[now]) {
			if (par[nxt]!=nxt) continue;
			if (vis[now]) {
				vis[nxt]=true;
				dp[nxt]=max(dp[nxt], dp[now]+mny[nxt]);
			}
			cnt[nxt]--;
			if (cnt[nxt]==0) q.push(nxt);
		}
	}
	int ans=0;
	rep(i, n) {
		if (i!=par[i]) continue;
		if (vis[i] && res[i]) ans=max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
