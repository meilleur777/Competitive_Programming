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

vector<ll> X, Y;

ll solve(vector<ll>& A) {
	sort(A.begin(), A.end());
	int mid = A.size()/2;
	ll ret = 0;
	for (auto i : A) {
		ret += abs(A[mid]-i);
	}
	return ret;
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	X.resize(M), Y.resize(M);
	rep(i, M) cin >> X[i] >> Y[i];
	cout << solve(X)+solve(Y);

	return 0;
}
