#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(n);
	vector<int> par(n);
	vector<int> cnt(n, 1);
	for (int i=0; i<n; i++) par[i]=i;
	for (int i=0; i<n; i++) cin >> c[i];

	function<int(int)> find=[&](int x) {
		if (x==par[x]) return x;
		return par[x]=find(par[x]);
	};
	function<void(int, int)> merge=[&](int a, int b) {
		int aa=find(a), bb=find(b);
		if (aa==bb) return;
		par[aa]=par[bb];
		c[bb]+=c[aa];
		cnt[bb]+=cnt[aa];
	};

	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		merge(a, b);
	}

	vector<int> dp(k, -1);
	dp[0]=0;
	for (int i=0; i<n; i++) {
		if (find(i)!=i) continue;
		for (int j=k-1; j>=cnt[i]; j--) {
			if (dp[j-cnt[i]]==-1) continue;
			dp[j]=max(dp[j], dp[j-cnt[i]]+c[i]);
		}
	}
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}
