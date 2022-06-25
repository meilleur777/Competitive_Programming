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

const ll mod=1e9+7;
const ll INF=0x3F3F3F3F;

vector<vector<vector<ll> > > cache;

ll solve(ll N, ll L, ll R) {
	if ((L==N && R==1) || (L==1 && R==N)) return 1;
	if (N==0 || L==0 || R==0) return 0;
	ll& ret=cache[N][L][R];
	if (ret!=-1) return ret;
	return ret=(solve(N-1, L, R)*(N-2)%mod+(solve(N-1, L-1, R)+solve(N-1, L, R-1))%mod)%mod;
}

int main() {
	init_code();

	ll N, L, R;
	cin >> N >> L >> R;
	cache=vector<vector<vector<ll> > >(N+1, vector<vector<ll> >(L+1, vector<ll>(R+1, -1)));
	cout << solve(N, L, R) << '\n';

	return 0;
}
