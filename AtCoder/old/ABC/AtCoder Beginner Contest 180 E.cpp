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

typedef struct {
	ll x, y, z;
} city;

int n;
vector<city> node;
vector<vector<ll> > dis;
vector<vector<ll> > dp;

ll solve(int now, int sta) {
	if (sta==(1<<n)-1) {
		return dis[now][0];
	}
	ll& ret=dp[now][sta];
	if (ret!=-1) return ret;
	ret=INF;
	for (int i=1; i<n; i++) {
		if (i==now || (sta&(1<<i))) continue;
		ret=min(ret, solve(i, (sta|(1<<i)))+dis[now][i]);
	}
	return ret;
}

int main() {
	init_code();

	cin >> n;
	node.resize(n);
	rep(i, n) {
		cin >> node[i].x >> node[i].y >> node[i].z;
	}
	dis=vector<vector<ll> >(n, vector<ll>(n, 0));
	dp=vector<vector<ll> >(n, vector<ll>(1<<n, -1));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==j) continue;
			dis[i][j]=llabs(node[i].x-node[j].x)+llabs(node[i].y-node[j].y)+max(0LL, node[j].z-node[i].z);
		}
	}
	cout << solve(0, 1);

	return 0;
}
