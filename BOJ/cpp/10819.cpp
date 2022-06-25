#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

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

int N;
vector<int> A;
int best = -1;

void solve() {
	while (next_permutation(A.begin(), A.end())) {
		int sum = 0;
		for (int i = 0; i < N - 1; i++) {
			sum += abs(A[i] - A[i + 1]);
		}
		best = max(best, sum);
	}
}

int main() {
	init_code();

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	solve();
	cout << best;

	return 0;
}
