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

	int N;
	cin >> N;
	int sum = 0, qsum = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		sum += x;
		qsum += x*x;
	}
	int ans = INT_MAX;
	for (int i = 1; i <= 100; i++) {
		ans = min(ans, qsum-2*i*sum+N*i*i);
	}
	cout << ans;

	return 0;
}
