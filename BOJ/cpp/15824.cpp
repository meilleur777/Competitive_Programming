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

const ll mod=1e9+7;
const int INF=0x3F3F3F3F;

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

int main() {
	init_code();

	ll N;
	cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end());
	ll ans=0;
	ll tmp=0;
	for (ll i=0; i<N/2; i++) {
		tmp-=A[i];
		tmp+=A[N-1-i];
		tmp%=mod;
		ans+=tmp*power(2, i);
		ans%=mod;
		if (N%2==0 && i==N/2-1) continue;
		ans+=tmp*power(2, N-i-2);
		ans%=mod;
	}
	cout << ans;

	return 0;
}
