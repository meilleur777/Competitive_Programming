#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const ll INF=1e12;

int main() {
	init_code();

	ll A, B, Q;
	cin >> A >> B >> Q;
	vector<ll> s(A+2), t(B+2);
	s[0]=-INF, t[0]=-INF;
	rep(i, A) cin >> s[i+1];	
	rep(i, B) cin >> t[i+1];
	s[A+1]=INF, t[B+1]=INF;
	while (Q--) {
		ll x;	
		cin >> x;
		int b=lower_bound(s.begin(), s.end(), x)-s.begin();
		int c=lower_bound(t.begin(), t.end(), x)-t.begin();
		ll res=INF;
		for (int i=b-1; i<=b; i++) {
			for (int j=c-1; j<=c; j++) {
				ll d=llabs(s[i]-x)+llabs(t[j]-s[i]);
				ll e=llabs(t[j]-x)+llabs(s[i]-t[j]);
				res=min({res, d, e});
			}
		}
		cout << res << '\n';
	}

	return 0;
}
