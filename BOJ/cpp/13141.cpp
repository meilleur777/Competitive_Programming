#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();
	cout << fixed;
	cout.precision(1);

	int n, m;
	cin >> n >> m;
	vector<vector<int> > dis(n, vector<int>(n, INF));
	vector<pair<intp, int> > edge(m);
	rep(i, m) {
		int s, e, l;
		cin >> s >> e >> l;
		s--, e--;
		edge[i]={{s, e}, l};
		dis[s][e]=min(dis[s][e], l);
		dis[e][s]=min(dis[e][s], l);
	}
	rep(i, n) dis[i][i]=0;
	rep(i, n) rep(j, n) rep(k, n) {
		if (dis[j][k]>dis[j][i]+dis[i][k]) {
			dis[j][k]=dis[j][i]+dis[i][k];
		}
	}
	double ans=2e7;
	for (int i=0; i<n; i++) {
		double tmp=-1;
		for (int j=0; j<m; j++) {
			int s=edge[j].first.first;
			int e=edge[j].first.second;
			int l=edge[j].second;
			int sho=min(dis[i][s], dis[i][e]);
			int lon=max(dis[i][s], dis[i][e]);
			if (sho==INF || lon==INF) continue;
			tmp=max(tmp, lon+(l-lon+sho)/2.0);
			/*cout << sho << ' ' << lon << '\n';
			cout << lon+max(0.0, (l-lon+sho)/2.0) << '\n';*/
		}
		ans=min(ans, tmp);
	}
	cout << ans;

	return 0;
}
