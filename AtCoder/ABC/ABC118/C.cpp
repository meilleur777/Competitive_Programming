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
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

int main() {
	init_code();

	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	int g = A[0];
	for (int i = 1; i < N; i++) {
		g = gcd(g, A[i]);
	}
	cout << g;

	return 0;
}
