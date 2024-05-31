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
const ll INF=0x3F3F3F3F3F3F3F3F;

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<vector<ll> > dis(N+1, vector<ll>(N+1, INF));
	rep(i, M) {
		ll a, b, c;
		cin >> a >> b >> c;
		dis[a][b]=min(dis[a][b], c);
	}
	ll ans=0;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=1; k<=N; k++) {
				if (j==k) {
					dis[j][k]=0;
					continue;
				}
				dis[j][k]=min(dis[j][k], dis[j][i]+dis[i][k]);
				if (dis[j][k]<INF) ans+=dis[j][k];
			}
		}
	}
	cout << ans;

	return 0;
}
