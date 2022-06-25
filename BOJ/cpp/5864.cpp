#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const ll INF=0x3F3F3F3F3F3F3F3F;

ll n, a, b;
vector<ll> dp;
vector<int> w;

ll sol(int now) {
	if (now==n) return 0;
	ll& ret=dp[now];
	if (ret!=-1) return ret;
	ret=INF;
	for (int i=now; i<n; i++) {
		ret=min(ret, sol(i+1)+2*a+b*(w[i]-w[now]));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> a >> b;
	w.resize(n);
	rep(i, n) cin >> w[i];
	sort(w.begin(), w.end());
	dp=vector<ll>(n, -1);
	ll tmp=sol(0);
	if (tmp%2) cout << tmp/2 << ".5";
	else cout << tmp/2;

	return 0;
}
