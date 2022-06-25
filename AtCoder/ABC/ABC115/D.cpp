#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
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

ll l[51], p[51];

ll solve(int N, ll X) {
	if (N == 0) {
		if (X == 0) return 0;
		else return 1;
	}
	if (X == 0) return 0;
	ll mid = (l[N]+1)/2;
	if (mid < X) {
		return 1+p[N-1]+solve(N-1, X-mid);
	}
	else if (mid == X) {
		return 1+p[N-1];
	}
	else {
		return solve(N-1, X-1);
	}
}

int main() {
	init_code();

	ll N, X;
	cin >> N >> X;
	l[0] = 1, p[0] = 1;
	for (int i = 1; i <= N; i++) {
		l[i] = l[i-1]*2+3;
		p[i] = p[i-1]*2+1;
	}
	cout << solve(N, X);

	return 0;
}
