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

	ll N, A, B;
	cin >> N >> A >> B;
	vector<ll> X(N);
	rep(i, N) cin >> X[i];
	ll ans=0;
	for (int i=0; i<N-1; i++) {
		ans+=min((X[i+1]-X[i])*A, B);
	}
	cout << ans;

	return 0;
}
