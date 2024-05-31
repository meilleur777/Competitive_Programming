#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

vector<ll> r;
vector<vector<ll> > dis;
vector<vector<ll> > cache;

ll solve(int now, int sta) {
	if (sta==((1<<r.size())-1)) return 0;
	ll& ret=cache[now][sta];
	if (ret!=-1) return ret;
	ret=INF;
	for (int i=0; i<r.size(); i++) {
		if (i==now || (sta&(1<<i))) continue;
		ret=min(ret, solve(i, sta|(1<<i))+dis[r[now]][r[i]]);
	}
	return ret;	
}

int main() {
	init_code();

	int N, M, R;
	cin >> N >> M >> R;
	r.resize(R);
	dis=vector<vector<ll> >(N+1, vector<ll>(N+1, INF));
	cache=vector<vector<ll> >(N+1, vector<ll>(1<<R, -1));
	rep(i, R) cin >> r[i];
	rep(i, M) {
		ll a, b, c;
		cin >> a >> b >> c;
		dis[a][b]=min(dis[a][b], c);
		dis[b][a]=min(dis[b][a], c);
	}
	for (int i=1; i<=N; i++) {
		dis[i][i]=0;
	}
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=1; k<=N; k++) {
				dis[j][k]=min(dis[j][k], dis[j][i]+dis[i][k]);
			}
		}
	}
	ll res=INF;
	for (int i=0; i<r.size(); i++) {
		res=min(res, solve(i, (1<<i)));
	}
	cout << res;

	return 0;
}
