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

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	vector<int> B(n+1);
	rep(i, n) cin >> B[i+1];
	vector<vector<int> > C(n+1);
	vector<int> A(n+1, 0);
	rep(j, m) {
		int i, w;
		cin >> i >> w;
		A[i]+=w;
	}
	for (int i=2; i<=n; i++) {
		A[i]+=A[B[i]];
	}
	for (int i=1; i<=n; i++) {
		cout << A[i] << ' ';
	}

	return 0;
}
