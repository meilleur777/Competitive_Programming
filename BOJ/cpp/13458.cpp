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

	int N, B, C;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] <= 0) {
			ans += 1;
		}
		else {
			ans += (A[i]+C-1)/C+1; 
		}
	}
	cout << ans;

	return 0;
}
