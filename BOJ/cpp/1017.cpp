#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

vector<bool> ispri(2001, true);

void sieve() {
	ispri[0]=ispri[1]=false;
	for (int i=2; i*i<=2000; i++) {
		for (int j=i*2; j<=2000; j+=i) {
			ispri[j]=false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	sieve();
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	vector<vector<int>> q(2);
	rep(i, n) q[(v[0]+v[i])%2].push_back(v[i]);
	if (q[0].size()!=q[1].size()) {
		cout << -1;
		return 0;
	}
	vector<vector<int>> edge(n/2);
	rep(i, n/2) rep(j, n/2) {
		if (ispri[q[0][i]+q[1][j]]) {
			edge[i].push_back(j);
		}
	}
	vector<int> ans;
	for (int i=0; i<n/2; i++) {
		if (!ispri[q[0][0]+q[1][i]]) continue;
		int tmp=0;
		vector<bool> vis;
		vector<int> a(n/2, -1);
		a[i]=0;
		function<bool(int)> dfs=[&](int now) {
			if (now==0) return false;
			for (auto nxt:edge[now]) {
				if (vis[nxt]) continue;
				vis[nxt]=true;
				if (a[nxt]==-1 || dfs(a[nxt])) {
					a[nxt]=now;
					return true;
				}
			}
			return false;
		};
		for (int j=1; j<n/2; j++) {
			vis=vector<bool>(n/2, false);
			vis[i]=true;
			tmp+=dfs(j);
		}
		if (tmp==n/2-1) ans.push_back(q[1][i]);
	}
	if (ans.empty()) cout << -1;
	else {
		sort(ans.begin(), ans.end());
		for (auto i:ans) cout << i << ' ';
	}

	return 0;
}
