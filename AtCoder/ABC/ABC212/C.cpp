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

int main() {
	init_code();

	int N, M;
	cin >> N >> M;

	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	sort(B.begin(), B.end());

	int ans = INT_MAX;
	for (int i = 0; i < N; i++) {
		int a = lower_bound(B.begin(), B.end(), A[i]) - B.begin();

		if (ans != B.size()) {
			ans = min(ans, abs(A[i] - B[a]));
		} 
		if (a != 0) ans = min(ans, abs(A[i] - B[a - 1]));
	}
	cout << ans;
}
