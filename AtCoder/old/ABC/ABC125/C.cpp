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

int gcd(int a, int b) {
	return a%b ? gcd(b, a%b) : b;
}

int main() {
	init_code();

	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	vector<int> fl(N);
	fl[0] = A[0];
	for (int i = 1; i < N; i++) {
		fl[i] = gcd(fl[i-1], A[i]);
	}
	vector<int> fr(N);
	fr[N-1] = A[N-1];
	for (int i = N-2; i >= 0; i--) {
		fr[i] = gcd(fr[i+1], A[i]);
	}
	int ans = max(fl[N-2], fr[1]);
	for (int i = 1; i < N-1; i++) {
		ans = max(ans, gcd(fl[i-1], fr[i+1]));
	}
	cout << ans;

	return 0;
}
