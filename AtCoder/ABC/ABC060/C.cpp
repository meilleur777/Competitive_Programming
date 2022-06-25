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

int main() {
	init_code();

	ll N, T;
	cin >> N >> T;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	ll ans=0;
	for (int i=0; i<N-1; i++) {
		ans+=min(T, A[i+1]-A[i]);
	}
	ans+=T;
	cout << ans;

	return 0;
}
