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
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<int> H(N), W(M);
	rep(i, N) cin >> H[i];
	rep(i, M) cin >> W[i];
	sort(H.begin(), H.end());
	vector<ll> psum(N);
	psum[0]=-H[0];
	for (int i=1; i<N; i++) {
		if (i%2) {
			psum[i]=H[i]+psum[i-1];
		}
		else {
			psum[i]=-H[i]+psum[i-1];
		}
	}
	ll res=LLONG_MAX;
	for (int i=0; i<M; i++) {
		ll tmp;
		int now=lower_bound(H.begin(), H.end(), W[i])-H.begin();
		if (now==0) {
			tmp=-psum[N-1]-W[i];
		}
		else {
			if (now%2) {
				tmp=psum[now-1]-(psum[N-1]-psum[now-1])+W[i];
			}
			else {
				tmp=psum[now-1]-(psum[N-1]-psum[now-1])-W[i];
			}
		}
		res=min(res, tmp);
	}
	cout << res;

	return 0;
}
