#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<tuple<int, int, int> > edge(M);
	vector<vector<int> > dis(N+1, vector<int>(N+1, 0x3F3F3F3F));
	rep(i, M) {
		int a, b, c;
		cin >> a >> b >> c;
		dis[a][b] = c;
		dis[b][a] = c;
		edge[i] = {a, b, c};
	}	
	for (int i = 1; i <= N; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				dis[j][k] = min(dis[j][k], dis[j][i]+dis[i][k]);
			}
		}
	}
	int ans = M;
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++) {
			if (dis[j][get<0>(edge[i])]+get<2>(edge[i]) == dis[j][get<1>(edge[i])]) {
				ans--;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
