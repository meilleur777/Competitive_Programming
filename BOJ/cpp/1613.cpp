#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> dis(n, vector<int>(n, 0));
	rep(i, k) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		dis[a][b]=-1;
		dis[b][a]=1;
	}
	rep(i, n) dis[i][i]=0;
	rep(i, n) rep(j, n) rep(k, n) {
		if (dis[j][i]*dis[i][k]<=0) continue;
		if (abs(dis[j][k])<abs(dis[j][i]+dis[i][k])) dis[j][k]=dis[j][i]+dis[i][k];
	}
	int s;
	cin >> s;
	while (s--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (dis[a][b]!=0) cout << dis[a][b]/abs(dis[a][b]) << '\n';
		else cout << "0\n";
	}

	return 0;
}
