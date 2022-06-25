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

int main() {
	init_code();

	int N;
	cin >> N;
	int sum0 = 0, sum1 = 0;
	vector<vector<int> > A(2, vector<int>(N));
	rep(i, N) {
		cin >> A[0][i];
	}
	rep(i, N) {
		cin >> A[1][i];
		sum1 += A[1][i];
	}
	sum0 = A[0][0];
	int ans = -1;
	for (int i = 0; i < N-1; i++) {
		ans = max(ans, sum0+sum1);
		sum0 += A[0][i+1];
		sum1 -= A[1][i];
	}
	ans = max(ans, sum0+sum1);
	cout << ans;

	return 0;
}
