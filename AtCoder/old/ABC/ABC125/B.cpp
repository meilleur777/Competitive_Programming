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
	vector<int> V(N), C(N), T(N);
	rep(i, N) cin >> V[i];
	rep(i, N) cin >> C[i];
	rep(i, N) T[i] = V[i]-C[i];
	sort(T.begin(), T.end(), greater<int>());
	int sum = 0;
	for (auto i : T) {
		if (i < 0) break;
		sum += i;
	}
	cout << sum;

	return 0;
}
