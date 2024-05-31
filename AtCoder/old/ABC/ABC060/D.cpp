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
const int INF=0x3F3F3F3F;

ll N, W;
vector<ll> w, v;
vector<vector<vector<ll> > > cache;

ll solve(ll now, ll wei, ll num) {
	if (now==N) return 0;
	ll& ret=cache[now][wei-num*w[0]][num];
	if (ret!=-1) return ret;
	if (w[now]+wei<=W) {
		ret=max(ret, solve(now+1, wei+w[now], num+1)+v[now]);
	}
	ret=max(ret, solve(now+1, wei, num));
	return ret;
}

int main() {
	init_code();

	cin >> N >> W;
	w.resize(N), v.resize(N);
	rep(i, N) cin >> w[i] >> v[i];
	ll tmp=0;
	rep(i, N) tmp+=w[i]-w[0];
	cache=vector<vector<vector<ll> > >(N, vector<vector<ll> >(tmp+1, vector<ll>(N+1, -1)));
	cout << solve(0, 0, 0);

	return 0;
}
